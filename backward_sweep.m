function traj = backward_sweep(traj)
    
    % Does backward sweep step of DDP
    % Proceeds backwards stagewise and computes matrices for updates
    % Updates variable 'traj'

    %% Stage Loop
    
    nx = traj.nx;
    nu = traj.nu;
    nw = traj.nw;
    nl = traj.nl;
    nX = nx + nu + nw;
    
    n_stages = traj.num_stages;
    % Loop /backwards
    for k = n_stages-1:-1:1
        
        part_string = "stage update";
        
        %% STM and STT for current stage
        
        STM = traj.stage{k}.STM;
        STT = traj.stage{k}.STT;
        
        %% Compute LX and LXX
        L_derivs = traj.local_ctg_derivs(traj,k);
        LX = L_derivs.LX;
        LXX = L_derivs.LXX;
        
        %% Stage Cost-to-go Derivatives
        
        % Map stage derivatives with STM and STT
        JX = LX + STM'*traj.stage{k+1}.JX_star;
        Jl = traj.stage{k+1}.Jl_star;
        JXX = zeros(nX,nX);
%         for i = 1:(nx+nu+nw)
% %             JXX = JXX + double(STT(i,:,:))*traj.stage{k+1}.JX_star(i);%JX(i);
%             JXX = JXX + squeeze(STT(i,:,:))*traj.stage{k+1}.JX_star(i);%JX(i);
%         end
        for i = 1:(nx+nu+nw)
            JXX(:,i) = JXX(:,i) + (traj.stage{k+1}.JX_star'*squeeze(STT(:,:,i)))';
        end
        JXX = JXX + LXX + STM'*traj.stage{k+1}.JXX_star*STM;% + double(ttv(STT,traj.stage{k+1}.JX_star,1));

        % Naive calculation of JXX
%         JXX_s = traj.stage{k+1}.JXX_star;
%         JX_s = traj.stage{k+1}.JX_star;
%         for i = 1:nX
%             for j = 1:nX
%                 comp1 = 0; % tensor part
%                 comp2 = 0; % matrix part
%                 for gam1 = 1:nX
%                     for gam2 = 1:nX
%                         comp1 = comp1 + JXX_s(gam1,gam2)*STM(gam1,i)*STM(gam2,j);
%                     end
%                     comp2 = comp2 + JX_s(gam1)*STT(gam1,i,j);
%                 end
%                 JXX(i,j) = comp1 + comp2;
%             end
%         end
        
        Jll = traj.stage{k+1}.Jll_star;
        JXl = STM'*traj.stage{k+1}.JXl_star;
        
        %% Unpack big matrices into submatrices
        
        Jx = JX(1:nx);
        Ju = JX(nx+1:nx+nu);
        Jw = JX(nx+nu+1:end);
        
        Jxx = JXX(1:nx,1:nx);
        Jxu = JXX(1:nx,nx+1:nx+nu);
        Jxw = JXX(1:nx,nx+nu+1:end);
        
        Jux = JXX(nx+1:nx+nu,1:nx);
        Juu = JXX(nx+1:nx+nu,nx+1:nx+nu);
        Juw = JXX(nx+1:nx+nu,nx+nu+1:end);
        
        Jwx = Jxw';
        Jwu = JXX(nx+nu+1:end,nx+1:nx+nu);
        Jww = JXX(nx+nu+1:end,nx+nu+1:end);
        
        % JXl should be nx+nu+nw X nl
        Jxl = JXl(1:nx,1:nl);
        Jul = JXl(nx+1:nx+nu,1:nl);
        Jwl = JXl(nx+nu+1:end,1:nl);
        
        %% Unconstrained Feedback Law Matrices
        
        % TRQP
        feedback_scaling_matrix = 1/traj.max_thrust_mag^2.*eye(3);
        feedback_scaling_matrix = eye(3);
        [A, Juu_t, bool_TRQP_failure] = trqp_new(Juu,Ju,traj.delta_TRQP,feedback_scaling_matrix,'Newton');
        if bool_TRQP_failure
            traj.bool_TRQP_failure = true; % Lets outer DDP loop know TRQP failed
            warning("TRQP failed at " + part_string + ", stage %i.",k);
            return
        end
        traj.bool_TRQP_failure = false;
        
%         if ~is_pos_def(Juu)
%             warning("Juu not positive definite at stage %d.",k)
%         end
        
        % Constrain control to lie along bounds if prediction exceeds
        % constraint
        % Otherwise proceed as normal
        u_predicted = traj.stage{k}.nominal_u + A;
        if norm(u_predicted) > 1
            fprintf("Predicted control larger than allowable at stage %i, ratio is %d.\n",k,norm(u_predicted)/1);
            u_cap = u_predicted/norm(u_predicted);
            A = u_cap - traj.stage{k}.nominal_u;
            B = zeros(nu, nx);
            if nw ~= 0
                C = -Juu_inv*Juw;
            else
                C = zeros(nu,1);
            end
            D = zeros(nu, nl);
        else
            Juu_inv = inv(Juu_t);% Precompute since it's used a bunch of times
            B = -Juu_inv*Jux;
            if nw ~= 0
                C = -Juu_inv*Juw;
            else
                C = zeros(nu,1);
            end
            D = -Juu_inv*Jul;

            % Safeguard for B 
            B = traj.eta1*norm(A)/max([traj.eta1*norm(A), norm(B*traj.stage{k}.deltax_prev)])*B;
        end
        
%         A = 0*A;
%         B = 0*B;
%         C = 0*C;
%         D = 0*D;
        
        % Save matrices for this stage
        traj.stage{k}.A = A; % Feedforward term
        traj.stage{k}.B = B; % Feedback gain for state deviation
        traj.stage{k}.C = C; % Feedback gain for static parameters
        traj.stage{k}.D = D; % Feedback gain for multipliers
        
        %% Stage Update Equations
        
        ER = traj.stage{k+1}.ER + Ju'*A + 1/2*A'*Juu*A; % Expected reduction
        %fprintf("Expected reduction is %d at stage %i.\n",ER,k);
        
        Jx_star = Jx + B'*Ju + B'*Juu'*A + Jux'*A;
        Jw_star = Jw + C'*Ju + C'*Juu'*A + Juw'*A;
        JX_star = [Jx_star; zeros(nu,1); Jw_star];

        Jl_star = Jl + D'*Ju + D'*Juu'*A + Jul'*A;

        Jxx_star = Jxx + B'*Juu*B + B'*Jux + Jux'*B;
        Jww_star = Jww + C'*Juu*C + C'*Juw + Juw'*C;
        Jxw_star = Jxw + B'*Juu*C + B'*Juw + Jux'*C;
        Jwx_star = Jxw_star';
        Jxu_star = zeros(nx,nu);
        Jux_star = Jxu_star';
        Juu_star = zeros(nu,nu);
        Juw_star = zeros(nu,nw);
        Jwu_star = Juw_star';
        JXX_star = [
                    Jxx_star, Jxu_star, Jxw_star;
                    Jux_star, Juu_star, Juw_star;
                    Jwx_star, Jwu_star, Jww_star
                    ];
        
        Jll_star = Jll + D'*Juu*D + D'*Jul + Jul'*D;
        
        Jxl_star = Jxl + B'*Juu*D + B'*Jul + Jux'*D;
        Jul_star = zeros(nu,nl);
        Jwl_star = Jwl + C'*Juu*D + C'*Jul + Juw'*D;
        JXl_star = [Jxl_star; Jul_star; Jwl_star];
        
        %% Save matrices
        
        traj.stage{k}.ER = ER; % Save
        traj.stage{k}.JX_star = JX_star;
        traj.stage{k}.Jl_star = Jl_star;
        traj.stage{k}.JXX_star = JXX_star;
        traj.stage{k}.Jll_star = Jll_star;
        traj.stage{k}.JXl_star = JXl_star;
        
    end
    
    % End of stage loop, do outer loop for multiplier and parameter updates
    %% Interphase Stuff (SINGLE PHASE)
    
    augphi_derivs = traj.augmented_lagrangian_derivs(traj);
    augphixp = augphi_derivs.augphixp;
    augphiwp = augphi_derivs.augphiwp;
    augphixpxp = augphi_derivs.augphixpxp;
    augphiwpwp = augphi_derivs.augphiwpwp;
    augphixpwp = augphi_derivs.augphixpwp;
    
    Jx_star = traj.stage{1}.JX_star(1:nx);
    Jw_star = traj.stage{1}.JX_star(nx+nu+1:end);
    
    
    Jxp = Jx_star + augphixp;
    Jwp = Jw_star + augphiwp;
    Jlp = traj.stage{1}.Jl_star;
    % Don't need minuses right now because we are only doing single phase
    % DDP
%     Jxm = augphixm;
%     Jwm = augphiwm;
%     Jlm = augphilm;
    
    Jxx_star = traj.stage{1}.JXX_star(1:nx,1:nx);
    Jww_star = traj.stage{1}.JXX_star(nx+nu+1:end,nx+nu+1:end);
    
    Jxpxp = Jxx_star + augphixpxp;
    Jwpwp = Jww_star + augphiwpwp;
    if isempty(Jwpwp)
        Jwpwp = 0;
    end
    Jlplp = traj.stage{1}.Jll_star;
    
%     Jxmxm = augphixmxm;
%     Jwmwm = augphiwmwm;
%     Jlmlm = zeros(nx,nx);
    
    Jxw_star = traj.stage{1}.JXX_star(1:nx,nx+nu+1:end);
    Jxpwp = Jxw_star + augphixpwp;
    
    Jxl_star = traj.stage{1}.JXl_star(1:nx,1:nl);
    Jxplp = Jxl_star;
    
%     Jxpxm = augphixpxm;
%     Jxpwm = augphixpwm;
%     Jxplm = augphixplm;
    
    % If no parameters, assign this zero to avoid empty matrices
    if isempty(JXl_star(nx+nu+1:end,1:nl))
        Jwl_star = 0;
    else
        Jwl_star = traj.stage{1}.JXl_star(nx+nu+1:end,1:nl);
    end
    Jwplp = Jwl_star;
    Jlpwp = Jwplp;
    
%     Jwpxm = augphiwpxm;
%     Jwpwm = augphiwpwm;
%     Jwplm = augphiwplm;
%     Jxmwm = augphixmwm;
%     Jxmlm = augphixmlm;
%     Jwmlm = augphiwmlm;
    
    % Aziz Dissertation 3.32
    if nw == 0
        Jwp_tilde = 0;
        Jwpwp_tilde = 0;
        Jwplop_tilde = 0;
    else
        Jwp_tilde = Jwp + Gamw'*Jxp;
        Jwpwp_tilde = Jwpwp + ttv(Gamww,Jxp,2) + Gamw'*Jxpxp*Gamw + Jxpwp*Gamw + Gamw'*Jxpwp;
        Jwplp_tilde = Jwplp + Gamw'*Jxpwp;
    end
%     Jwpxm_tilde = Jwpxm + Gamw'*Jxpxm;
%     Jwpwm_tilde = Jwpwm + Gamw'*Jxpwm;
%     Jwplm_tilde = Jwplm + Gamw'*Jxplm;
    
    %% Multiplier update matrices
    
    % TRQP for multiplier
    % Jll should be negative def, so use -Jll and -Jl
    part_string = "multiplier update";
    [Alp,Jlplp_t,bool_TRQP_failure] = trqp_new(-Jlplp,-Jlp,traj.delta_TRQP,eye(length(Jlp)),'Newton');
    if bool_TRQP_failure
        traj.bool_TRQP_failure = true;
        warning("TRQP failed at " + part_string + ".");
        return
    end
    traj.bool_TRQP_failure = false;
    
    Jlplp_t = -Jlplp_t;
    
    Jlplp_inv = inv(Jlplp_t); % Precompute since it's used a bunch of times
    %Alp = -Jlplp_inv*Jlp; % suspect Alp from trqp function is not the same as this (testing shows it's the negative)
    Clp = Jlplp_inv*Jlpwp;
    
    %% Multipler phase update equations
    
    ER_phase_multiplier = Jlp'*Alp + 1/2*Alp'*Jlplp*Alp;
    Jwp_hat = (Jwp_tilde' + Jlp'*Clp + Alp'*Jlplp*Clp + Alp'*Jlpwp)';
    Jwpwp_hat = Jwpwp_tilde + Clp'*Jwpwp*Clp + Clp'*Jlpwp + Jwplp*Clp;
%     Jwpxm_hat = Jwpxm_tilde;
%     Jwpwm_hat = Jwpwm_tilde;
%     Jwplm_hat = Jwplm_tilde;

    %% Static controls/parameters update matrices
    
    if nw ~= 0
        % Ensures Jwpwp positive definite (and invertible)
        if ~is_pos_def(Jwpwp)
            lambda_min_w = eigs(Jwpwp,1,'smallestabs'); % Finds eigenvalue with smallest magnitude
            if lambda_min_w < 0
                Jwpwp = Jwpwp - 2*lambda_min_w*eye(size(Jwpwp)); % Shift eigenvalues of Juu to make it pos def (Eq 26 from Yakowitz 1989)
            else
                error("Jwpwp not positive definite, but does not have negative eigenvalues.")
            end
        end
        Jwpwphat_inv = inv(Jwpwphat); % Precompute since it's used a bunch of times
        Awp = -Jwpwphat_inv*Jwp;
        Bwp = -Jwpwphat_inv*Jwpxm;
        Cwp = -Jwpwphat*Jwpwm;
        Dwp = -Jwpwphat*Jwplm;
        
    
        %% Static controls/parameters phase update equations

        ER_phase_parameter = Jwp_hat'*Awp + 1/2*Awp'*Jwpwp_hat*Awp; % This is the only one needed for single phase

        % The following are all for multiphase stuff
    %     Jxm_star = (Jxm' + Jwp_hat'*Bwp + Awp'*Jwpwp_hat*Bwp + Awp'*Jwpxm_hat)';
    %     Jwm_star = (Jwm' + Jwp_hat'*Cwp + Awp'*Jwpwp_hat*Cwp + Awp'*Jwpwm_hat)';
    %     Jlm_star = (Jlm' + Jwp_hat'*Dwp + Awp'*Jwpwp_hat*Dwp + Awp'*Jwplm_hat)';
    %     Jxmxm_star = Jxmxm + Bwp'*Jwpwp_hat*Bwp + Bwp'*Jwpxm_hat + Jwpxm_hat'*Bwp;
    %     Jwmwm_star = Jwmwm + Cwp'*Jwpwp_hat*Cwp + Cwp'*Jwpwm_hat + Jwpwm_hat'*Cwp;
    %     Jlmlm_star = Jlmlm + Dwp'*Jwpwp_hat*Dwp + Dwp'*Jwplm_hat + Jwplm_hat'*Dwp;
    %     Jxmwm_star = Jxmwm + Bwp'*Jwpwp_hat*Cwp + Bwp'*Jwpwm_hat + Jwpwm_hat'*Cwp;
    %     Jxmlm_star = Jxmlm + Bwp'*Jwpwp_hat*Dwp + Bwp'*Jwplm_hat + Jwpxm_hat'*Dwp;
    %     Jwmlm_star = Jwmlm + Cwp'*Jwpwp_hat*Dwp + Cwp'*Jwplm_hat + Jwpwm_hat'*Dwp;


        %% Parameter update

        deltawp = Awp + Bwp*deltaxm + Cwp*deltawm + Dwp*deltalm;
        traj.deltaw = deltawp;
    else
        ER_phase_parameter = 0;
        deltawp = 0;
        traj.deltaw = deltawp;
    end

    %% Multiplier update
    
    if nw == 0 
        deltawp = zeros(nl,1);
    end
    deltalp = (Alp + Clp*deltawp); % Scales multiplier update
    traj.deltal = deltalp;
    
    %% Phase ER update
    
    stage_ER = traj.stage{1}.ER;
    ER_phase = stage_ER + ER_phase_multiplier + ER_phase_parameter;
    traj.ER_phase = ER_phase;
    
    % Backward sweep iteration done, next is forward sweep
end