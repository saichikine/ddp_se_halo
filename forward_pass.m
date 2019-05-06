function traj = forward_pass(traj)
    
    % Performs forward pass step of DDP
    % Integrates trajectory forward in time with updated controls
    
    %%   
    n_stages = length(traj.stage);
    ode_opts = odeset('RelTol',1e-13,'AbsTol',1e-18);
    
    %% Unpack parameter and multiplier updates (computed at end of backward sweep)
    deltal = traj.deltal;
    deltaw = traj.deltaw;
        
    %% Get stage times   
    stage_times = traj.stage_times;
    
    %% Define current state to start loop
    state_current = traj.initial_state;
    
    %% Stage loop
    
    % Loop forwards
    for k = 1:n_stages-1
        
        % State deviation
        % Note that state_current is always equal to traj.stage{k}.state
        deltax = state_current - traj.stage{k}.nominal_state;
        traj.stage{k}.deltax = deltax;
        
        % Unpack control policy matrices
        A = traj.stage{k}.A;
        B = traj.stage{k}.B;
        C = traj.stage{k}.C;
        D = traj.stage{k}.D;
        
        % Compute control update
        deltau = (A + C*deltaw + D*deltal) + B*deltax;
        if any(isnan(deltau),'all')
            deltau = zeros(size(deltau));
        end
        u_current = traj.stage{k}.nominal_u + deltau; % Update control
        %fprintf("deltau is:\n %d\n%d\n%d\n",deltau(1),deltau(2),deltau(3));
        
        % Check for control constraint violations again
        if norm(u_current) > 1
            %fprintf("Control exceeds allowable magnitude. Ratio is %d.\n", norm(u_current)/1);
            %fprintf("Forward pass: attempted control larger than allowable at stage %i, ratio is %d.\n",k,norm(u_current)/1);
            u_current = u_current./norm(u_current);
            %fprintf("Using thrusts: Tx = %dmN, Ty = %dmN, Tz = %dmN.\n Total magnitude: %dmN.\n", u_current(1)*traj.max_thrust_mag*1e6*traj.normalizers.force_norm, u_current(2)*traj.max_thrust_mag*1e6*traj.normalizers.force_norm, u_current(3)*traj.max_thrust_mag*1e6*traj.normalizers.force_norm, norm(u_current*traj.max_thrust_mag*1e6*traj.normalizers.force_norm));
        end
        traj.stage{k}.u = u_current;
        
        % Integrate 
        [~, x_stage] = ode113(@(t,X) CR3BP_cart_control_mex(t,X,traj.mu,traj.exh_vel,traj.max_thrust_mag), [stage_times(k) stage_times(k+1)], [state_current; u_current], ode_opts);
        
        % Update current state and save
        state_current = x_stage(end,1:7)';
        traj.stage{k+1}.state = state_current;
    end
    
    % Forward pass done
    
end