function final_traj_info = ddp_func(initial_traj,varargin)

    % DDP set up as a function so it can be used in continuation
    % traj struct is initialized OUTSIDE of this function; this function is
    % only for ddp iteration
    
    %% Input Handling
    
    % Optional name-value pair arguments: 'max_iter' and 'bool_liveplot'
    
    default_max_iters = 3000;
    default_bool_liveplot = false;
    
    p = inputParser;
    %p.StructExpand = false;
    valid_scalar_pos_num = @(x) isnumeric(x) && isscalar(x) && (x>0);
    
    addRequired(p,'initial_traj');
    
    addParameter(p,'max_iters',default_max_iters,valid_scalar_pos_num);
    addParameter(p,'bool_liveplot',default_bool_liveplot,@islogical);
    
    parse(p,initial_traj,varargin{:});
    
    initial_traj = p.Results.initial_traj;
    max_iters = p.Results.max_iters;
    bool_liveplot = p.Results.bool_liveplot;
    
    %% Preallocate iteration-wise history
    
    f_hist = NaN(max_iters+1, 1); % history for feasibility 
    J_hist = NaN(max_iters+1, 1); % history for cost
    sigma_hist = NaN(max_iters+1,1); % history for penalty weight
    delta_hist = NaN(max_iters+1,1); % history for TRQP radius
    rho_hist = NaN(max_iters+1,1); % history for rho
    lambda_hist = NaN(6,max_iters+1); % history for multipliers
    mass_hist = NaN(max_iters+1,1); % history for delivered mass
    iteration_data = linspace(0,max_iters,max_iters+1);
    
    traj = initial_traj;
    
    f_hist(1) = traj.f_nom;
    J_hist(1) = traj.J_nom;
    sigma_hist(1) = traj.penalty_sigma;
    delta_hist(1) = traj.delta_TRQP;
    rho_hist(1) = NaN;
    lambda_hist(:,1) = traj.lambda;
    mass_hist(1) = traj.stage{end}.state(7)*traj.normalizers.MU;
    
    %% DDP Loop

    bool_converged = false;
    iteration_start_counter = 1;
    fprintf("Starting DDP loop.\n")
    
    % Start plot
    if bool_liveplot
        figure; hold on
        addToolbarExplorationButtons(gcf)
        yyaxis left
        DDP_f_plot = plot(iteration_data,f_hist,'o-','DisplayName','$$||\psi||$$');
        set(gca,'yscale','log')
        yyaxis right
        DDP_J_plot = plot(iteration_data,J_hist,'o-','DisplayName','J');
        set(gca,'yscale','linear')
        hold off
        drawnow
        title('Convergence Data')
        xlabel('Iteration Number')
        legend()
        grid on
    end

    DDP_start = tic;
    while ~bool_converged
 
        % Iterate through forward pass and backward sweep until converged

        % Compute STMs (Lantoine step 1)
        fprintf('Computing STMs and STTs...')
        tic
        traj = traj.compute_STMs(traj);
        fprintf('done.\n')
        toc

        % Initialize before each iteration
        traj = traj.initialize(traj);
    %     traj.delta_TRQP = delta_TRQP_default;

        bool_failed = false;
        bool_accept_iterate = false;
        while ~bool_accept_iterate

            % Backward sweep (Lantoine step 2)
            traj = backward_sweep(traj);
            if traj.bool_TRQP_failure
                delta_TRQP_old = traj.delta_TRQP;
                traj.delta_TRQP = max([(1-traj.kappa)*traj.delta_TRQP, traj.delta_TRQP_min]);
                fprintf('Changing TRQP delta from %s to %s.\n',delta_TRQP_old,traj.delta_TRQP)
                continue
            end
  
            % Forward Pass (Lantoine step 4)
            traj = forward_pass(traj);
            traj.lambda = traj.nominal_lambda + traj.deltal;
            Jnew = traj.compute_J(traj);
            hnew = traj.compute_h(traj);
            fnew = traj.compute_f(traj);

            % Trust region update/Iteration acceptance
            % test (Lantoine step 5)
            % Compute new cost Jnew
            bool_accept_iterate = false;
            rho = (Jnew - traj.J_nom)/traj.ER_phase;
            fprintf("rho is %d.\n",rho)
            if (rho) <= 1+traj.iterate_epsilon && (rho) >= 1-traj.iterate_epsilon
                traj.delta_TRQP = min([(1+traj.kappa)*traj.delta_TRQP, traj.delta_TRQP_max]); % LR eq 56
                fprintf('TRQP delta is %d.\n',traj.delta_TRQP)
                bool_accept_iterate = true;
                fprintf("Iterate accepted.\n Reduction in f is %d (new f is %d).\n Reduction in cost is %d (new J is %d).\n", traj.f_nom - fnew, fnew, traj.J_nom - Jnew, Jnew)
            else
                %traj.lambda_epsilon = traj.lambda_epsilon/2; % Reduce scaling factor for multiplier update to keep traj sufficiently close to quadratic expansion
                %fprintf("Reducing size of multiplier update: new epsilon is %d.\n",traj.lambda_epsilon)
                delta_TRQP_old = traj.delta_TRQP;
                traj.delta_TRQP = max([(1-traj.kappa)*traj.delta_TRQP, traj.delta_TRQP_min]);
                fprintf('Changing TRQP delta from %s to %s.\n',delta_TRQP_old,traj.delta_TRQP)
            end
            if traj.delta_TRQP == traj.delta_TRQP_min
                fprintf('TRQP delta too small. Exiting.\n')
                bool_failed = true;
                stop_condition = 1;
                break
            end
        end
        
        % Convergence test (Lantoine step 3)
        fnew = traj.compute_f(traj);
        if abs(traj.ER_phase) < traj.opt_epsilon && fnew < traj.feas_epsilon && bool_accept_iterate
            bool_converged = true;
            fprintf("Expected reduction within convergence criteria, constraints satisfied to within acceptable range. Terminating iteration with %i iterations.\n",iteration_start_counter);
            traj.f_nom = fnew;
            traj.J_nom = traj.compute_J(traj);
            traj.h_nom = traj.compute_h(traj);
            traj.lambda = traj.nominal_lambda + traj.deltal;
            traj.nominal_lambda = traj.lambda;
            for k = 1:traj.num_stages
                traj.stage{k}.nominal_state = traj.stage{k}.state;
                traj.stage{k}.nominal_u = traj.stage{k}.u;
            end
            f_hist(iteration_start_counter) = traj.f_nom;
            J_hist(iteration_start_counter) = traj.J_nom;
            sigma_hist(iteration_start_counter) = traj.penalty_sigma;
            delta_hist(iteration_start_counter) = traj.delta_TRQP;
            rho_hist(iteration_start_counter) = rho;
            lambda_hist(:,iteration_start_counter) = traj.nominal_lambda;
            mass_hist(iteration_start_counter) = traj.stage{end}.state(7)*traj.normalizers.MU;

            DDP_f_plot.XData = iteration_data;
            DDP_f_plot.YData = f_hist;
            DDP_J_plot.XData = iteration_data;
            DDP_J_plot.YData = J_hist;
            drawnow
            break
        end

        if bool_failed
            break
        end

        % Penalty update (Lantoine step 6)
        % Updating penalty weight seems to break algorithm
        if fnew > traj.f_nom
            %traj.penalty_sigma = max([min([abs(0.5*hnew/fnew^2),k_sigma*penalty_sigma]),penalty_sigma]); % Lantoine eq. 57
            traj.penalty_sigma = max([min([abs(0.5*hnew/fnew^2),traj.k_sigma*traj.penalty_sigma]),traj.penalty_sigma]);
            fprintf("Updating penalty sigma to %d.\n",traj.penalty_sigma)
        end

        % Nominal update (Lantoine step 7)
        traj.nominal_lambda = traj.nominal_lambda + traj.deltal;
        traj.lambda = traj.nominal_lambda;
        traj.w = traj.w + traj.deltaw;
        traj.J_nom = traj.compute_J(traj);
        traj.h_nom = traj.compute_h(traj);
        traj.f_nom = traj.compute_f(traj);

        % Need a separate nominal in case trial iterate is not accepted
        % Otherwise if trial iterate is not accepted and iteration is
        % reattempted, states and controls have already changed
        for k = 1:traj.num_stages
            traj.stage{k}.nominal_state = traj.stage{k}.state;
            traj.stage{k}.nominal_u = traj.stage{k}.u;
            traj.stage{k}.deltax_prev = traj.stage{k}.deltax;
        end
        
        fprintf("Finished iteration %i.\n",iteration_start_counter)
        iteration_start_counter = iteration_start_counter + 1;
        % Update plot
        if iteration_start_counter ~= 1
            f_hist(iteration_start_counter) = traj.f_nom;
            J_hist(iteration_start_counter) = traj.J_nom;
            sigma_hist(iteration_start_counter) = traj.penalty_sigma;
            delta_hist(iteration_start_counter) = traj.delta_TRQP;
            rho_hist(iteration_start_counter) = rho;
            lambda_hist(:,iteration_start_counter) = traj.nominal_lambda;
            mass_hist(iteration_start_counter) = traj.stage{end}.state(7)*traj.normalizers.MU;
            
            DDP_f_plot.XData = iteration_data;
            DDP_f_plot.YData = f_hist;
            DDP_J_plot.XData = iteration_data;
            DDP_J_plot.YData = J_hist;
            drawnow
        end
        if iteration_start_counter >= max_iters+1
            fprintf("Reached iteration limit. Terminating.\n")
            stop_condition = 2;
            break
        end
    end
    stop_condition = 0;
    DDP_time = toc(DDP_start)
    
    %% Assign outputs
    final_traj = traj;
    final_traj_info = struct('traj',final_traj,'f_hist',f_hist,'J_hist',J_hist,'sigma_hist',sigma_hist,'delta_hist',delta_hist,...
        'rho_hist',rho_hist,'lambda_hist',lambda_hist,'mass_hist',mass_hist,'stop_condition',stop_condition,'time',DDP_time);
end