% This file runs codegen to create mex files

%% rip

clear; close all; clc;
addpath(genpath(pwd)); % add all subfolders to path (for this session)

%%

codegen CR3BP_cart_control_STMSTT -args {0,zeros(1110,1,'double'),0,0,0} -o mex_files/
codegen CR3BP_cart_control -args {0,zeros(10,1,'double'),0,0,0} -o mex_files/
codegen CR3BP_fast -args {0,zeros(6,1,'double'),0} -o mex_files/

%%

% Update path to include 'mex_files' folder
addpath(genpath(pwd));

%%

fprintf("mex file generation successful.\n\n");