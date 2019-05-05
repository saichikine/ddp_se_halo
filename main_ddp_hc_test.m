% Continuation test based on first reasonable converged halo transfer

%% let it rip
clear; close all; clc;
set(groot,'defaultLineLineWidth', 1.5)
set(groot,'defaultAxesFontSize', 16)
set(groot,'defaulttextinterpreter','latex');  
set(groot, 'defaultAxesTickLabelInterpreter','latex');  
set(groot, 'defaultLegendInterpreter','latex');

p = gcp % Start parallel pool if one doesn't exist

addpath(genpath(pwd)); % add all subfolders to path (for this session)

%%
load('halo_success_var_f.mat'); % Load successful workspace
load('tau_start.mat');
load('Az_start.mat');

%% Get new target state

new_targ = continue_halo(Az_L2,tau,1.01,target_state_posvel,mu_SE,LU,"L2","north",'bool_plot',true);

%% 
traj.penalty_sigma = 5000;
traj.delta_TRQP = delta_TRQP_default/1000;

traj.compute_constraintvec = @(traj) constraint_vec(traj,new_targ.target_state);
% stage_times = linspace(0,new_targ.tau,n_stages);
% traj.stage{1}.time = stage_times(1);
% 
% for i = 1:n_stages-1
%     traj.stage{i+1}.time = stage_times(i+1);
% end

traj = traj.initialize(traj);
traj.J_nom = traj.compute_J(traj);
traj.f_nom = traj.compute_f(traj);
traj.h_nom = traj.compute_h(traj);

fprintf("Done initializing.\n")

%% Plot

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
scatter3(new_targ.target_state(1), new_targ.target_state(2), new_targ.target_state(3), 'mo','filled','DisplayName', 'Target State');
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