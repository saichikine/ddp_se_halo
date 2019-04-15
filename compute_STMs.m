function traj = compute_STMs(traj)
    
    % Computes first and second order STMs forward in time along stages
    % Modifies variable 'traj'
    
    %% Get stuff ready
    
    nX = traj.nx + traj.nu + traj.nw;
    nx = traj.nx;
    nu = traj.nu;
    nw = traj.nw;

    % Assemble states, times, and controls (for parfor)
    states = NaN(nx,traj.num_stages);
    controls = NaN(nu,traj.num_stages);
    for i = 1:traj.num_stages
        states(:,i) = traj.stage{i}.state;
        controls(:,i) = traj.stage{i}.u;
    end
    times = traj.stage_times;
    mu = traj.mu;
    exh_vel = traj.exh_vel;
    
    %%
    % nx = dimension of state vector
    % nu = dimension of dynamic control vector
    % nw = dimension of static control vector
    
    STM_0 = eye(nX);
    STT_0 = zeros([nX nX nX]);
    
    %% Integrate
    % We need STMs from time step k to k+1, NOT STMs from 0 to k+1
    
    ode_opts = odeset('RelTol',5e-14,'AbsTol',1e-20);
    
    current_state = traj.initial_state;
    states_post = NaN(nx,traj.num_stages);
    STMs_post = NaN(nX,nX,traj.num_stages);
    STTs_post = NaN(nX,nX,nX,traj.num_stages);
    
    max_thrust = traj.max_thrust_mag; % define this here so 'traj' struct isn't passed into parfor
    
    [
    
    for k = 1:traj.num_stages-1
%         current_state = states(:,k);
        X0 = [reshape(current_state,[],1); controls(:,k); reshape(STM_0,[],1); reshape((STT_0),[],1)]; % initial state (stage k)
        [~,stage_full_states] = ode113(@(t,X) CR3BP_cart_control_STMSTT(t,X,mu,exh_vel,max_thrust), [times(k) times(k+1)], X0, ode_opts); % prop to k+1
        current_state = stage_full_states(end,1:traj.nx)';
        states_post(:,k+1) = current_state;
        STMs_post(:,:,k) = reshape(stage_full_states(end,nX+1:nX+nX^2),nX,nX);
        STTs_post(:,:,:,k) = reshape(stage_full_states(end,nX+nX^2+1:end),[nX nX nX]);
    end
    
    % Assign stuff to traj
    for k = 1:traj.num_stages-1
        traj.stage{k+1}.state = states_post(:,k+1);
        traj.stage{k}.STM = STMs_post(:,:,k);
        traj.stage{k}.STT = (STTs_post(:,:,:,k));
    end
    
end