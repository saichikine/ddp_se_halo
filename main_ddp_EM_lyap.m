% DDP for lyapunov transfer (Earth-Moon system)

%% dioxy
clear; close all; clc;
set(groot,'defaultLineLineWidth', 1.5)
set(groot,'defaultAxesFontSize', 16)
set(groot,'defaulttextinterpreter','latex');  
set(groot, 'defaultAxesTickLabelInterpreter','latex');  
set(groot, 'defaultLegendInterpreter','latex');
p = gcp;
addpath(genpath(pwd));

%% Load relevant data

load('environment_EM_spacecraft_cubesat.mat');
load('initial_state_lyap_trans.mat');
load('target_state_lyap_trans.mat');
target_state_posvel = X0_arr_guess;

%% Simulate multiple-shooting results to pick suitable start and end states
ode_opts = odeset('RelTol',1e-13,'AbsTol',1e-20);

% Simulate for chosen tof with start and endpoints indicated
tof = 5.4881;
[t_ig, X_ig] = ode113(@(t,X) CR3BP_cart_control_mex(t,X,mu_EM,exh_vel,max_thrust_mag), [0 tof], [initial_state; zeros(3,1)], ode_opts);

figure
addToolbarExplorationButtons(gcf) % Adds buttons to figure toolbar
plot(1-mu_SE, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
plot(x_L1, 0, 'dk', 'markerfacecolor', 'r', 'DisplayName', '$$L_1$$'); % L1 location
plot(x_L2, 0, 'dk' , 'markerfacecolor', 'b', 'DisplayName', '$$L_2$$'); % L2 location
scatter(initial_state(1), initial_state(2), 'x', 'DisplayName', 'Initial Position');
scatter(target_state_posvel(1), target_state_posvel(2), 'x', 'DisplayName', 'Target state');
plot(X_ig(:,1), X_ig(:,2), 'b.-','DisplayName', 'Initial Guess Trajectory');
hold off
title('Multiple-Shooting Lyapunov Connection')
xlabel('x')
ylabel('y')
grid on;
legend();
axis equal

%% Set up DDP

% Create empty traj struct
num_stages = 200;
num_phases = 1;
traj = generate_traj(num_stages,num_phases);

% Assign values
traj.mu = mu_EM;
traj.exh_vel = exh_vel;
traj.max_thrust_mag = max_thrust_mag;
traj.normalizers = normalizers;
traj.initial_state = initial_state;

% Acceptance bounds
traj.iterate_epsilon = 0.1; % acceptance bound for each iteration, rho must be within this of 1
traj.opt_epsilon = 1e-7; % stop condition for expected reduction
traj.feas_epsilon = 1e-7; % stop condition for endpoint constraint

% Penalty weight
traj.penalty_sigma = 1e1; % scaling parameter for quadratic penalty term

% TRQP parameters
traj.k_sigma = 1.5;
traj.kappa = 0.1; 
delta_TRQP_default = 1e-3;
traj.delta_TRQP_min = 5e-18;
traj.delta_TRQP_max = 1;
traj.delta_TRQP = delta_TRQP_default;

% Gain guard parameters
traj.eta1 = 10;
traj.eta2 = 1000;

% Multipliers
initial_lambda = zeros(6,1);
traj.lambda = initial_lambda;
traj.nominal_lambda = initial_lambda;

% Constraint vector function
traj.compute_constraintvec = @(traj) constraint_vec(traj,target_state_posvel);

% Times
stage_times = linspace(0,tof,num_stages);
stage_times = t_ig(floor(linspace(1,length(t_ig),num_stages)));
traj.stage_times = stage_times;

% Loop through to initialize stages
traj.stage{1}.nominal_state = initial_state;
traj.stage{1}.state = initial_state;
traj.stage{1}.time = traj.stage_times(1);
traj.stage{1}.nominal_u = zeros(3,1);
traj.stage{1}.u = zeros(3,1);
current_state = initial_state;
for k = 1:num_stages-1
    [~,stage_states] = ode113(@(t,X) CR3BP_cart_control_mex(t,X,mu_EM,exh_vel,max_thrust_mag), [stage_times(k), stage_times(k+1)], [current_state; zeros(3,1)], ode_opts);
    current_state = stage_states(end,1:7)';
    traj.stage{k+1}.nominal_state = current_state;
    traj.stage{k+1}.state = current_state;
    traj.stage{k+1}.time = stage_times(k+1);
    traj.stage{k+1}.nominal_u = zeros(3,1);
    traj.stage{k+1}.u = zeros(3,1);
end

traj = traj.initialize(traj);
traj.J_nom = traj.compute_J(traj);
traj.f_nom = traj.compute_f(traj);
traj.h_nom = traj.compute_h(traj);

fprintf("Done initializing.\n");

%% Plot initial guess

u = NaN(traj.nu,traj.num_stages);
for k = 1:traj.num_stages
    u(:,k) = traj.max_thrust_mag*FU*1000*1000.*(traj.stage{k}.nominal_u);%-traj.stage{k}.nominal_u); % FU is in kN; multiply by FU to get kN, then convert to mN
    %fprintf("u diff at stage %i is:\n %d\n%d\n%d\n",k,u(1,k),u(2,k),u(3,k));
end

states = NaN(traj.nx,traj.num_stages);
for k = 1:traj.num_stages
    states(:,k) = traj.stage{k}.state;
end

figure
addToolbarExplorationButtons(gcf)
scatter(x_L1, 0, 'rd', 'DisplayName','L1'); hold on
scatter(x_L2, 0, 'bd', 'DisplayName','L2');
plot(1-mu_SE, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
scatter(initial_state(1), initial_state(2), 'co','filled','DisplayName','Initial State');
scatter(target_state_posvel(1), target_state_posvel(2), 'mo','filled','DisplayName', 'Target State');
plot(states(1,:), states(2,:), '-o', 'DisplayName','Trajectory');
quiver(states(1,:), states(2,:), u(1,:), u(2,:), 1.1, 'DisplayName', 'Thrust Vectors');
hold off
grid on
legend();
axis equal
xlabel('x')
ylabel('y')

figure
addToolbarExplorationButtons(gcf)
plot(stage_times.*TU/60/60/24, u(1,:), '-o','DisplayName','x thrust'); hold on
plot(stage_times.*TU/60/60/24, u(2,:), '-o','DisplayName','y thrust');
plot(stage_times.*TU/60/60/24, u(3,:), '-o','DisplayName','z thrust'); hold off
grid on
legend()
title('Control History')
ylabel('Thrust [mN]')
xlabel('Time [days]')

%% DDP Loop

fdata = [traj.f_nom];
Jdata = [traj.J_nom];

bool_converged = false;
max_iter = 3000;

iteration_counter = 0;
iteration_data = [iteration_counter];
fprintf("Starting DDP loop.\n")

figure; hold on
addToolbarExplorationButtons(gcf)
yyaxis left
DDP_f_plot = plot(iteration_data,fdata,'o-','DisplayName','$$||\psi||$$');
set(gca,'yscale','log')
yyaxis right
DDP_J_plot = plot(iteration_data,Jdata,'o-','DisplayName','J');
set(gca,'yscale','linear')
hold off

drawnow
title('Convergence Data')
xlabel('Iteration Number')
legend()
grid on

DDP_start = tic;
while ~bool_converged
    
    % Update plot
    DDP_f_plot.XData = iteration_data;
    DDP_f_plot.YData = fdata;
    DDP_J_plot.XData = iteration_data;
    DDP_J_plot.YData = Jdata;
    drawnow
    
    if iteration_counter ~= 0
        fprintf("Finished iteration %i.\n",iteration_counter)
    end
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
        
        % Convergence test (Lantoine step 3)
        fnew = traj.compute_f(traj);
        if abs(traj.ER_phase) < traj.opt_epsilon && fnew < traj.feas_epsilon
            bool_converged = true;
            fprintf("Expected reduction within convergence criteria, constraints satisfied to within acceptable range. Terminating iteration with %i iterations.\n",iteration_counter);
            traj.f_nom = fnew;
            traj.J_nom = traj.compute_J(traj);
            traj.h_nom = traj.compute_h(traj);
            traj.lambda = traj.nominal_lambda + traj.deltal;
            traj.nominal_lambda = traj.lambda;
            for k = 1:traj.num_stages
                traj.stage{k}.nominal_state = traj.stage{k}.state;
                traj.stage{k}.nominal_u = traj.stage{k}.u;
            end
            break
        end
%         if traj.ER_phase < 0
%             error("Error: Expected reduction is negative.\n");
%         end
%         
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
            break
        end
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
    %if ~bool_converged
        traj.nominal_lambda = traj.nominal_lambda + traj.deltal;
        traj.lambda = traj.nominal_lambda;
        traj.w = traj.w + traj.deltaw;
        traj.J_nom = traj.compute_J(traj);
        traj.h_nom = traj.compute_h(traj);
        traj.f_nom = traj.compute_f(traj);
        Jdata = [Jdata; traj.J_nom];
        fdata = [fdata; traj.f_nom];
    %end
    
    % Need a separate nominal in case trial iterate is not accepted
    % Otherwise if trial iterate is not accepted and iteration is
    % reattempted, states and controls have already changed
    for k = 1:traj.num_stages
        traj.stage{k}.nominal_state = traj.stage{k}.state;
        traj.stage{k}.nominal_u = traj.stage{k}.u;
        traj.stage{k}.deltax_prev = traj.stage{k}.deltax;
    end
    
    iteration_counter = iteration_counter + 1;
    iteration_data = [iteration_data; iteration_counter];
    if iteration_counter >= max_iter
        fprintf("Reached iteration limit. Terminating.\n")
        break
    end
end
toc(DDP_start)
