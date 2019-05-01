function final_traj_info = ddp_func(initial_traj)

    % DDP set up as a function so it can be used in continuation
    % traj struct is initialized OUTSIDE of this function; this function is
    % only for ddp iteration
    
    %% Preallocate iteration-wise history
    
    f_hist = NaN(max_iters, 1); % history for feasibility 
    J_hist = NaN(max_iters, 1); % history for cost
    sigma_hist = NaN(max_iters,1); % history for penalty weight
    delta_hist = NaN(max_iters,1); % history for TRQP radius
    rho_hist = NaN(max_iters,1); % history for rho
    lambda_hist = NaN(6,max_iters); % history for multipliers
    mass_hist = NaN(max_iters,1); % history for delivered mass

end