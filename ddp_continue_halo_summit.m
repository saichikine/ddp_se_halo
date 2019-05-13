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

num_transfers = 5;
cont_times = NaN(num_transfers,1);

%% 1st (base) case

base_case_start = tic;
optprob_halo_start;
ddp_halo_trans_set(1) = ddp_halo1;
ddp_conv_traj_prev = ddp_halo1.traj;
cont_times(1) = toc(base_case_start);

%% Continuation part

load('tau_start.mat');
load('Az_start.mat');
Az_L2_prev = Az_L2;
tau_prev = tau;

total_cont_time_start = tic;
for trans_num = 2:num_transfers
    
    cont_start = tic;
    
    new_traj = ddp_conv_traj_prev;
    new_targ = continue_halo_fast(Az_L2,tau,1.01,ddp_conv_traj_prev.target_state_posvel,ddp_conv_traj_prev.mu,ddp_conv_traj_prev.normalizers.LU,"L2","north",'bool_plot',false);
    Az_L2 = new_targ.Az;
    tau = new_targ.tau;
    
    new_traj.target_state = new_targ.target_state;
    new_traj.penalty_sigma = 1e1;
    new_traj.delta_TRQP = 1e-4;
    new_traj.compute_constraintvec = @(traj) constraint_vec(traj,new_traj.target_state);
    
    new_traj = new_traj.initialize(new_traj);
    new_traj.J_nom = new_traj.compute_J(new_traj);
    new_traj.f_nom = new_traj.compute_f(new_traj);
    new_traj.h_nom = new_traj.compute_h(new_traj);

    fprintf("Done initializing.\n")
    
    % Safeguard against DDP failure
    try
        ddp_halo = ddp_func(new_traj,'max_iters',3000,'bool_liveplot',false);
        ddp_halo_trans_set(trans_num) = ddp_halo;
    catch
        bool_continue_success = false;
        ddp_halo_trans_set(trans_num) = [];
    end
    
    % Save so not all is lost if timeout occurs on Summit
    save('progress_data/current_progress.mat');
    
    % If DDP was not successful, don't use it as the new initial guess
    % Possible issues with this: if one continuation is not successful, why
    % would the next one with even larger amplitude be successful with
    % same initial guess, which would be worse?
    if ddp_halo.stop_condition ~= 0
        bool_continue_success = false;
    end
    
    if bool_continue_success
        ddp_conv_traj_prev = ddp_halo.traj;
    end
    
    cont_times(trans_num) = toc(cont_start);
end
total_cont_time = toc(total_cont_time_start);

%% Save
save('continuation_success.mat');
fprintf("Continuation process successful!");