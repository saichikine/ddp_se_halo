% Main file for running ddp with continuation in orbit amplitude
% For use on RMACC Summit supercomputer

%% mada mada koinu yo
clear; close all; clc;
set(groot,'defaultLineLineWidth', 1.5)
set(groot,'defaultAxesFontSize', 16)
set(groot,'defaulttextinterpreter','latex');  
set(groot, 'defaultAxesTickLabelInterpreter','latex');  
set(groot, 'defaultLegendInterpreter','latex');

p = gcp; % Start parallel pool if one doesn't exist

addpath(genpath(pwd)); % add all subfolders to path (for this session)

%% Setup

num_transfers = 10;
cont_times = NaN(num_transfers,1);

%% 1st (base) case

load('halo_base_good.mat');
ddp_halo_trans_set{1} = ddp_halo1;
ddp_conv_traj_prev = ddp_halo1.traj;
cont_times(1) = 0;
ddp_traj_plot3(ddp_halo1.traj);

%% Continuation part

load('tau_start.mat');
load('Az_start.mat');
Az_L2_prev = Az_L2;
tau_prev = tau;

%%
total_cont_time_start = tic;
for trans_num = 7:num_transfers
    
    cont_start = tic;
    
    new_traj = ddp_conv_traj_prev;
    new_targ = continue_halo_fast(Az_L2,tau,1.01,ddp_conv_traj_prev.target_state,ddp_conv_traj_prev.mu,LU,"L2","north",'bool_plot',false);
    Az_L2_prev = Az_L2;
    Az_L2 = new_targ.Az;
    tau = new_targ.tau;moon
    
    new_traj.target_state = new_targ.target_state;
    new_traj.penalty_sigma = 1e2;
    new_traj.delta_TRQP = 1e-3;
    new_traj.compute_constraintvec = @(traj) constraint_vec(traj,new_traj.target_state);
    
    new_traj = new_traj.initialize(new_traj);
    new_traj.J_nom = new_traj.compute_J(new_traj);
    new_traj.f_nom = new_traj.compute_f(new_traj);
    new_traj.h_nom = new_traj.compute_h(new_traj);

    fprintf("Done initializing.\n")
    
    % Safeguard against DDP failure
    ddp_halo = ddp_func(new_traj,'max_iters',6000,'bool_liveplot',true);
    ddp_halo_trans_set{trans_num} = ddp_halo;
    cont_times(trans_num) = toc(cont_start);
    ddp_traj_plot3(ddp_halo.traj);
    cont_times(trans_num) = toc(cont_start);
    
    % Save so not all is lost if timeout occurs on Summit
    save('progress_data/current_progress.mat');
    
    % If DDP was not successful, don't use it as the new initial guess
    % Possible issues with this: if one continuation is not successful, why
    % would the next one with even larger amplitude be successful with
    % same initial guess, which would be worse?
    if ddp_halo.stop_condition ~= 0
        bool_continue_success = false;
    else
        bool_continue_success = true;
    end
    
    ddp_conv_traj_prev = ddp_halo.traj;
    
    
end
total_cont_time = toc(total_cont_time_start);

%%
ddp_continue_set_plot(ddp_halo_trans_set,9,'Earth','Sun');

%% Save
save('continuation_success.mat');
fprintf("Continuation process successful!");