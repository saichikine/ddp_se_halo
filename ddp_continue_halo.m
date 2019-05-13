% Main file for running ddp with continuation in orbit amplitude

%% mada mada koinu yo
clear; close all; clc;
set(groot,'defaultLineLineWidth', 1.5)
set(groot,'defaultAxesFontSize', 16)
set(groot,'defaulttextinterpreter','latex');  
set(groot, 'defaultAxesTickLabelInterpreter','latex');  
set(groot, 'defaultLegendInterpreter','latex');

p = gcp; % Start parallel pool if one doesn't exist

addpath(genpath(pwd)); % add all subfolders to path (for this session)

%% 