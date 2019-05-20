% Sai Chikine
% Master's Thesis
% Spring 2019
% DDP (Differential Dynamic Programming) Transfer Test
% Control constraint via backward pass

% CR3BP transfer test
% Sun-Earth halo-to-halo
%% It's morphin time
clear; close all; clc;
set(groot,'defaultLineLineWidth', 1.5)
set(groot,'defaultAxesFontSize', 16)
set(groot,'defaulttextinterpreter','latex');  
set(groot, 'defaultAxesTickLabelInterpreter','latex');  
set(groot, 'defaultLegendInterpreter','latex');
p = gcp; % Start parallel pool if one doesn't exist
addpath(genpath(pwd));

%% Load 

load('environment_SE_spacecraft_cubesat.mat'); % m_sc, exh_vel, and max_thrust_mag are already normalized and loaded here
fprintf('Loaded spacecraft and environment.\n')
disp(cubesat);
load('halo_trans_ig_100_b.mat'); % initial guess for LT transfer from multiple-shooting
fprintf('Loaded initial guess.\n');

%% Plot initial guess

% Unpack initial guess
N_ms = ms_results_initial_guess.num_nodes;
thrust_flags = ms_results_initial_guess.thrust_flags;

nX = 10;

chi = ms_results_initial_guess.chi;
arc_initial_states = ms_results_initial_guess.arc_initial_states;
arc_integration_times = ms_results_initial_guess.arc_integration_times;
slack_vars = ms_results_initial_guess.slack_vars;

initial_state_full = arc_initial_states(:,1);
target_state_full = arc_initial_states(:,end);
target_state_posvel = target_state_full(1:6);

ode_opts = odeset('RelTol',1e-13,'AbsTol',1e-17);

X_hist_ig_flight = [arc_initial_states(:,1)'];
thrust_hist_ig_flight = [max_thrust_mag*FU*1000*1000*arc_initial_states(8:end,1)'];
u_hist_ig_flight = [arc_initial_states(8:end,1)'];
t_hist_ig_flight = [0];
t_last = 0;

fprintf("Simulating converged trajectory...")
tic
for i = 1:N_ms-1
      
    if thrust_flags(i) == 0
        [t_hist_arc,X_hist_arc] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_SE,exh_vel,max_thrust_mag), linspace(0+t_last, arc_integration_times(i)+t_last,100), [arc_initial_states(1:7,i); zeros(3,1)], ode_opts);
    else
        [t_hist_arc,X_hist_arc] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_SE,exh_vel,max_thrust_mag), linspace(0+t_last, arc_integration_times(i)+t_last,100), arc_initial_states(:,i), ode_opts);
    end
    t_last = t_hist_arc(end);
    
    % Go back through and compute control history
    for j = 2:length(t_hist_arc)
        thrust_hist_ig_flight = [thrust_hist_ig_flight; max_thrust_mag*FU*1000*1000*X_hist_arc(j,8:end)];
        u_hist_ig_flight = [u_hist_ig_flight; X_hist_arc(j,8:end)];
    end
    % Save total state history
    X_hist_ig_flight = [X_hist_ig_flight; X_hist_arc(2:end,:)];
    t_hist_ig_flight = [t_hist_ig_flight; t_hist_arc(2:end)];
end
% [t_hist_targ_orb, X_hist_targ_orb] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_SE,exh_vel,max_thrust_mag), [0+t_last, T_L2+t_last], [arc_initial_states(1:7,end); zeros(3,1)], ode_opts);
% for i = 1:length(t_hist_targ_orb)
%     u_hist_ig_flight = [u_hist_ig_flight; zeros(3,1)'];
% end
% X_hist_ig_flight = [X_hist_ig_flight; X_hist_targ_orb];
% t_hist_ig_flight = [t_hist_ig_flight; t_hist_targ_orb];
fprintf("done.\n")
toc

% Plot control history
figure
addToolbarExplorationButtons(gcf)
hold on
plot(t_hist_ig_flight.*TU/60/60/24, thrust_hist_ig_flight(:,1), '.-', 'DisplayName', 'x thrust');
plot(t_hist_ig_flight.*TU/60/60/24, thrust_hist_ig_flight(:,2), '.-', 'DisplayName', 'y thrust');
plot(t_hist_ig_flight.*TU/60/60/24, thrust_hist_ig_flight(:,3), '.-', 'DisplayName', 'z thrust');
hold off
xlabel('Time [days]')
ylabel('Control Thrust [$$mN$$]')
legend()
grid on

spacing = 20;
figure
addToolbarExplorationButtons(gcf) % Adds buttons to figure toolbar
plot3(1-mu_SE, 0, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
plot3(x_L1, 0, 0, 'dk', 'markerfacecolor', 'b', 'DisplayName', '$$L_1$$'); hold on % L1 location
plot3(x_L2, 0, 0, 'dk' , 'markerfacecolor', 'r', 'DisplayName', '$$L_2$$'); hold on % L2 location
for i = 1:size(arc_initial_states,2)
    node_string = "Node" + num2str(i);
    %plot3(arc_initial_states(1,i), arc_initial_states(2,i), arc_initial_states(3,i), 'o', 'DisplayName', node_string); hold on
end
%plot(X_hist_total_guess(1,1), X_hist_total_guess(1,2), X_hist_total_guess(1,3), 'ok', 'markerfacecolor',[244,179,66]./255, 'DisplayName', 'Initial Point'); hold on
scatter3(initial_state_full(1), initial_state_full(2), initial_state_full(3), 50, 'o', 'filled', 'DisplayName', 'Initial Position');
scatter3(target_state_full(1), target_state_full(2), target_state_full(3), 50, 'o', 'filled', 'DisplayName', 'Target Position');
plot3(X_hist_ig_flight(:,1), X_hist_ig_flight(:,2), X_hist_ig_flight(:,3), '.-', 'MarkerSize',10,'color',[0,0.4470,0.7410],'DisplayName','Trajectory'); hold on
quiver3(X_hist_ig_flight(1:spacing:end,1),X_hist_ig_flight(1:spacing:end,2),X_hist_ig_flight(1:spacing:end,3),thrust_hist_ig_flight(1:spacing:end,1),thrust_hist_ig_flight(1:spacing:end,2),thrust_hist_ig_flight(1:spacing:end,3), 1.5, 'Color',[0.8500,0.3250,0.0980],'linewidth',2,'ShowArrowHead','off','DisplayName', 'Thrust Vectors'); hold on
%title('Multiple Shooting Low-Thrust Transfer')
xlabel('x')
ylabel('y')
zlabel('z')
grid on;
legend();
h = get(gca,'DataAspectRatio');
if h(3)==1
      set(gca,'DataAspectRatio',[1 1 1])
else
      set(gca,'DataAspectRatio',[1 1 1])
end
%% DDP Parameters/Setup

% Create empty traj struct
num_stages = 300;
num_phases = 1;
traj = generate_traj(num_stages,num_phases);

% Assign values
traj.mu = mu_SE;
traj.exh_vel = exh_vel;
traj.max_thrust_mag = max_thrust_mag;
traj.normalizers = normalizers;
traj.initial_state = [initial_state_full(1:6); m_sc];
traj.target_state = target_state_posvel;

% Acceptance bounds
traj.iterate_epsilon = 0.1; % acceptance bound for each iteration, rho must be within this of 1
traj.opt_epsilon = 1e-9; % stop condition for expected reduction
traj.feas_epsilon = 1e-7; % stop condition for endpoint constraint

% Penalty weight
traj.penalty_sigma = 1e2; % scaling parameter for quadratic penalty term

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
time_spacing_nonlinear_flag = 0;
if time_spacing_nonlinear_flag
    stage_time_indices = floor(linspace(1,length(t_hist_ig_flight),traj.num_stages));
    stage_times = t_hist_ig_flight(stage_time_indices); % spacing based on ode output
    
    % Initial guess controls
    u_stage_ig = u_hist_ig_flight(stage_time_indices,:)';
else
    if traj.num_stages == ms_results_initial_guess(1).num_nodes
        
        stage_times = [0; cumsum(arc_integration_times)];

        % Initial guess controls
        u_stage_ig = arc_initial_states(8:end,:);
    else
        stage_times = linspace(0,t_hist_ig_flight(end),traj.num_stages);
        u_stage_ig = interp1(t_hist_ig_flight,u_hist_ig_flight,stage_times,'linear');        
        u_stage_ig = u_stage_ig';
    end
end
u_stage_ig(:,end) = zeros(3,1); % set last stage controls to zero
traj.stage_times = stage_times;

% Initial guess and target
initial_state_mass = [initial_state_full(1:6); m_sc];
target_state_posvel = target_state_full(1:6);
%% Get initial guess from multiple shooting and finish DDP setup

% Stage times
time_spacing_nonlinear_flag = 1;
if time_spacing_nonlinear_flag
    stage_time_indices = floor(linspace(1,length(t_hist_ig_flight),traj.num_stages));
    stage_times = t_hist_ig_flight(stage_time_indices); % spacing based on ode output
    
    % Initial guess controls
    u_stage_ig = u_hist_ig_flight(stage_time_indices,:)';
else
    if traj.num_stages == ms_results_initial_guess(1).num_nodes
        
        stage_times = [0; cumsum(arc_integration_times)];

        % Initial guess controls
        u_stage_ig = arc_initial_states(8:end,:);
    else
        stage_times = linspace(0,t_hist_ig_flight(end),traj.num_stages);
        u_stage_ig = interp1(t_hist_ig_flight,u_hist_ig_flight,stage_times,'linear');        
        u_stage_ig = u_stage_ig';
    end
end
u_stage_ig(:,end) = zeros(3,1); % set last stage controls to zero

traj.stage_times = stage_times;

% Initialize traj with initial guess
current_state = traj.initial_state;
% First stage is separate
u_ig = u_stage_ig(:,1);
traj.stage{1}.nominal_state = current_state;
traj.stage{1}.state = current_state;
traj.stage{1}.time = traj.stage_times(1);
traj.stage{1}.nominal_u = u_ig;
traj.stage{1}.u = u_ig;
for i = 1:traj.num_stages-1
    
    u_ig = u_stage_ig(:,i);
    [~,stage_states] = ode113(@(t,X) CR3BP_cart_control(t,X,traj.mu,exh_vel,max_thrust_mag), [stage_times(i), stage_times(i+1)], [current_state; u_ig], ode_opts);
    current_state = stage_states(end,1:7)';
    
    traj.stage{i+1}.nominal_state = current_state;
    traj.stage{i+1}.state = current_state;
    traj.stage{i+1}.time = stage_times(i+1);
    traj.stage{i+1}.nominal_u = u_stage_ig(:,i+1);
    traj.stage{i+1}.u = u_stage_ig(:,i+1);
end

% Initialize last stage
% Only need to initialize stage JX_star, Jl_star, JXX_star, Jll_star, JXl_star,
% and ER at last stage (first backwards sweep takes care of rest of stages)
% Note that stagewise ER at last stage = 0

traj = traj.initialize(traj);
traj.J_nom = traj.compute_J(traj);
traj.f_nom = traj.compute_f(traj);
traj.h_nom = traj.compute_h(traj);

fprintf("Done initializing.\n")

%% Show initial guess results

ddp_traj_plot3(traj);

%% DDP Loop

ddp_halo1 = ddp_func(traj,'max_iters',3000,'bool_liveplot',true);

%% Plot final results

ddp_traj_plot3(ddp_halo1.traj);
ddp_halo_traj_plot3(ddp_halo1.traj)
ddp_conv_plot(ddp_halo1);
