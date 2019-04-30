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

p = gcp % Start parallel pool if one doesn't exist

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
        [t_hist_arc,X_hist_arc] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_SE,exh_vel,max_thrust_mag), [0+t_last, arc_integration_times(i)+t_last], [arc_initial_states(1:7,i); zeros(3,1)], ode_opts);
    else
        [t_hist_arc,X_hist_arc] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_SE,exh_vel,max_thrust_mag), [0+t_last, arc_integration_times(i)+t_last], arc_initial_states(:,i), ode_opts);
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

figure
addToolbarExplorationButtons(gcf) % Adds buttons to figure toolbar
plot3(1-mu_SE, 0, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
plot3(x_L1, 0, 0, 'dk', 'markerfacecolor', 'r', 'DisplayName', '$$L_1$$'); hold on % L1 location
plot3(x_L2, 0, 0, 'dk' , 'markerfacecolor', 'b', 'DisplayName', '$$L_2$$'); hold on % L2 location
for i = 1:size(arc_initial_states,2)
    node_string = "Node" + num2str(i);
    %plot3(arc_initial_states(1,i), arc_initial_states(2,i), arc_initial_states(3,i), 'o', 'DisplayName', node_string); hold on
end
%plot(X_hist_total_guess(1,1), X_hist_total_guess(1,2), X_hist_total_guess(1,3), 'ok', 'markerfacecolor',[244,179,66]./255, 'DisplayName', 'Initial Point'); hold on
scatter3(initial_state_full(1), initial_state_full(2), initial_state_full(3), 'x', 'DisplayName', 'Initial Position');
scatter3(target_state_full(1), target_state_full(2), target_state_full(3), 'x', 'DisplayName', 'Target Position');
scatter3(X_hist_ig_flight(:,1), X_hist_ig_flight(:,2), X_hist_ig_flight(:,3), 'r.','DisplayName', 'Low-Thrust Transfer Trajectory'); hold on
quiver3(X_hist_ig_flight(:,1),X_hist_ig_flight(:,2),X_hist_ig_flight(:,3),thrust_hist_ig_flight(:,1),thrust_hist_ig_flight(:,2),thrust_hist_ig_flight(:,3), 1.1,'DisplayName', 'Thrust Vectors'); hold on
title('Final Low-Thrust Transfer')
xlabel('x')
ylabel('y')
zlabel('z')
grid on;
%legend();
h = get(gca,'DataAspectRatio');
if h(3)==1
      set(gca,'DataAspectRatio',[1 1 1])
else
      set(gca,'DataAspectRatio',[1 1 1])
end
%% DDP Parameters/Setup

nx =  7; % 7 with mass?
nu = 3; % number of controls
nw = 0; % number of parameters/static controls
nl = 6; % number of lagrange multipliers (same as dimension of constraint function)

% Acceptance bounds
iterate_epsilon = 0.1; % acceptance bound for each iteration, 0.01 is what Lantoine uses
opt_epsilon = 1e-7; % acceptance bound for expected reduction
feas_epsilon = 1e-7;

% Penalty weight
penalty_sigma = 100; % scaling parameter for quadratic penalty term, Lantoine uses 0.001

% TRQP parameters
k_sigma = 1.1;
kappa = 0.1; % LR value
delta_TRQP_default = 1e-1;
delta_TRQP_min = 5e-20;
delta_TRQP_max = 1;

% Gain guard parameters
eta1 = 10;
eta2 = 1000;

% Number of stages/phases
n_stages = 300;
M = 1; % number of phaess

% Multipliers initial guess
initial_lambda = 0*ones(nl,1);

% Initial guess and target
initial_state_mass = [initial_state_full(1:6); m_sc];
target_state_posvel = target_state_full(1:6);

% Create traj
traj = struct('num_stages',n_stages,'num_phases',M,'mu',mu_SE,'exh_vel',exh_vel,'normalizers',normalizers,'initial_state',initial_state_mass,'lambda',initial_lambda,'nominal_lambda',initial_lambda,'w',[],'nx',nx,'nu',nu,'nw',nw,'nl',nl,...
    'stages',[],'stage_times',[],'deltaw',[],'deltal',[],'ER_phase',[],'J_nom',[],'h_nom',[],'f_nom',[],...
    'max_thrust_mag',max_thrust_mag,'eta1',eta1,'eta2',eta2,'bool_TRQP_failure',[],...
    'iterate_epsilon',iterate_epsilon,'opt_epsilon',opt_epsilon,'feas_epsilon',feas_epsilon,'penalty_sigma',penalty_sigma,'k_sigma',k_sigma,...
    'kappa',kappa,'delta_TRQP',delta_TRQP_default,'delta_TRQP_min',delta_TRQP_min,'delta_TRQP_max',delta_TRQP_max,...
    'compute_STMs',@compute_STMs_ser,'initialize',@initialize,'local_ctg_derivs',@L_derivs,'augmented_lagrangian_derivs',@phitilde_derivs,...
    'compute_constraintvec',@(traj) constraint_vec(traj,target_state_posvel),'compute_f',@compute_f,'compute_h',@compute_h,'compute_J',@compute_J,...
    'stage_cost',@stage_cost,'terminal_cost',@terminal_cost,'augmented_lagrangian',@augmented_lagrangian);

%% Get initial guess from multiple shooting and finish DDP setup

% Stage times
time_spacing_nonlinear_flag = 0;
if time_spacing_nonlinear_flag
    stage_time_indices = floor(linspace(1,length(t_hist_ig_flight),n_stages));
    stage_times = t_hist_ig_flight(stage_time_indices); % spacing based on ode output
    
    % Initial guess controls
    u_stage_ig = u_hist_ig_flight(stage_time_indices,:)';
else
    if n_stages == ms_results_initial_guess(1).num_nodes
        
        stage_times = [0; cumsum(arc_integration_times)];

        % Initial guess controls
        u_stage_ig = arc_initial_states(8:end,:);
    else
        stage_times = linspace(0,t_hist_ig_flight(end),n_stages);
        u_stage_ig = interp1(t_hist_ig_flight,u_hist_ig_flight,stage_times,'linear');        
        u_stage_ig = u_stage_ig';
    end
end
u_stage_ig(:,end) = zeros(3,1); % set last stage controls to zero

% Cap controls if above max
% for i = 1:length(u_stage_ig)
%     if norm(u_stage_ig(:,i)) > 1
%         u_stage_ig(:,i) = u_stage_ig(:,i)/norm(u_stage_ig(:,i));
%     end
% end

traj.stage_times = stage_times;

% Initialize traj with initial guess
current_state = initial_state_mass;
% First stage is separate
u_ig = u_stage_ig(:,1);
traj.stage{1} = struct('nominal_state',current_state,'state',current_state,'time',stage_times(1),'nominal_u',u_ig,'u',u_ig,'A',[],'B',[],'C',[],'D',[],...
        'JX_star',[],'Jl_star',[],'JXX_star',[],'Jll_star',[],'JXl_star',[],'STM',[],'STT',[],'ER',[],'deltax',[],'deltax_prev',zeros(nx,1)); % deltax_prev is zero at first iteration
for i = 1:n_stages-1
    u_ig = u_stage_ig(:,i);
    [~,stage_states] = ode113(@(t,X) CR3BP_cart_control(t,X,traj.mu,exh_vel,max_thrust_mag), [stage_times(i), stage_times(i+1)], [current_state; u_ig], ode_opts);
    current_state = stage_states(end,1:7)';
    
    traj.stage{i+1} = struct('nominal_state',current_state,'state',current_state,'time',stage_times(i+1),'nominal_u',u_stage_ig(:,i+1),'u',u_stage_ig(:,i+1),'A',[],'B',[],'C',[],'D',[],...
        'JX_star',[],'Jl_star',[],'JXX_star',[],'Jll_star',[],'JXl_star',[],'STM',[],'STT',[],'ER',[],'deltax',[],'deltax_prev',zeros(nx,1)); 
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

u = NaN(nu,traj.num_stages);
for k = 1:traj.num_stages
    u(:,k) = traj.max_thrust_mag*FU*1000*1000.*(traj.stage{k}.nominal_u);%-traj.stage{k}.nominal_u); % FU is in kN; multiply by FU to get kN, then convert to mN
    %fprintf("u diff at stage %i is:\n %d\n%d\n%d\n",k,u(1,k),u(2,k),u(3,k));
end

states = NaN(nx,traj.num_stages);
for k = 1:traj.num_stages
    states(:,k) = traj.stage{k}.state;
end

figure
addToolbarExplorationButtons(gcf)
scatter3(x_L1, 0, 0, 'rd', 'DisplayName','L1'); hold on
scatter3(x_L2, 0, 0, 'bd', 'DisplayName','L2');
scatter3(1-mu_SE, 0, 0, 'kx', 'DisplayName','Second Primary');
%scatter3(-mu_EM, 0, 0, 'bx', 'DisplayName', 'First Primary');
scatter3(initial_state_mass(1), initial_state_mass(2), initial_state_mass(3), 'co','filled','DisplayName','Initial State');
scatter3(target_state_posvel(1), target_state_posvel(2), target_state_posvel(3), 'mo','filled','DisplayName', 'Target State');
plot3(states(1,:), states(2,:), states(3,:), '-o', 'DisplayName','Trajectory');
quiver3(states(1,:), states(2,:), states(3,:), u(1,:), u(2,:), u(3,:), 1.1, 'DisplayName', 'Thrust Vectors');
hold off
grid on
legend();
h = get(gca,'DataAspectRatio');
if h(3)==1
      set(gca,'DataAspectRatio',[1 1 1])
else
      set(gca,'DataAspectRatio',[1 1 1])
end

figure
addToolbarExplorationButtons(gcf)
plot(stage_times.*TU/60/60/24, u(1,:), '-o','DisplayName','x thrust'); hold on
plot(stage_times.*TU/60/60/24, u(2,:), '-o','DisplayName','y thrust');
plot(stage_times.*TU/60/60/24, u(3,:), '-o','DisplayName','z thrust'); hold off
grid on
legend()
title('Control History')
ylabel('mN')
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
        if abs(traj.ER_phase) < opt_epsilon && fnew < feas_epsilon
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
        traj.penalty_sigma = max([min([abs(0.5*hnew/fnew^2),k_sigma*traj.penalty_sigma]),traj.penalty_sigma]);
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
    for k = 1:n_stages
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

%% Plot final results

