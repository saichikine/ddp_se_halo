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
num_stages = 300;
num_phases = 1;
traj = generate_traj(num_stages,num_phases);

% Assign values
traj.mu = mu_EM;
traj.exh_vel = exh_vel;
traj.max_thrust_mag = max_thrust_mag;
traj.normalizers = normalizers;
traj.initial_state = initial_state;
traj.target_state = target_state_posvel;

% Acceptance bounds
traj.iterate_epsilon = 0.1; % acceptance bound for each iteration, rho must be within this of 1
traj.opt_epsilon = 1e-7; % stop condition for expected reduction
traj.feas_epsilon = 1e-7; % stop condition for endpoint constraint

% Penalty weight
traj.penalty_sigma = 1e-2; % scaling parameter for quadratic penalty term

% TRQP parameters
traj.k_sigma = 1.1;
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
%stage_times = t_ig(floor(linspace(1,length(t_ig),num_stages)));
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

ddp_traj_plot(traj,'Moon','Earth');

%% DDP Loop

ddp_lyap_ex = ddp_func(traj,'max_iters',3000,'bool_liveplot',true);

%% Plot final traj

ddp_traj_plot(ddp_lyap_ex.traj,'Moon','Earth');