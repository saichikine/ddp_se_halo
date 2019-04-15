% Make sure STM and STT make sense

%% brace urselves
clear; close all; clc;

%% 

load('lt_vardir_50mN_N15.mat');
load('EM_sys_stuff.mat');

%%

c = 24.4010e+003; % fake exhaust velocity for now (doesn't matter since no control)
nX = 10;
X0 = [ms_results_endpoints.free_vars(1:6); 200/200; [0.000; 0; 0]];
tspan = linspace(0,5.5,3000);

ode_opts = odeset('RelTol',1e-13,'AbsTol',1e-20);

deltaX0 = X0.*0.0001;

X0p = X0 + deltaX0;

fprintf('Simulating reference trajectory...')
tic
[t,X_ref] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_EM,c), tspan, X0, ode_opts);
fprintf('done.\n')
toc

fprintf('Simulating perturbed trajectory...')
tic
[tp,X_ref_p] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_EM,c), tspan, X0p, ode_opts);
fprintf('done.\n')
toc

%% Plot ref and perturbed traj

figure
plot(X_ref(:,1), X_ref(:,2), 'DisplayName', 'Reference Trajectory'); hold on
plot(X_ref_p(:,1), X_ref_p(:,2), 'DisplayName', 'Perturbed Trajectory (full dynamics)'); hold off
grid on
xlabel('x')
ylabel('y')
title('Full Dynamics')
legend()

%% Propagate STM and use it for deltaX0

X0STM = [X0; reshape(eye(nX),[],1)];
fprintf('Simulating with STM...')
tic
[tSTM, X_STM] = ode113(@(t,X) CR3BP_cart_control(t,X,mu_EM,c), tspan, X0STM, ode_opts);
fprintf('done.\n')
toc

STM_hist = NaN(10,10,length(tSTM));
for i = 1:length(tSTM)
    STM_hist(:,:,i) = reshape(X_STM(i,nX+1:end),nX,nX);
end

X_p_STM = NaN(nX,length(tSTM));
for i = 1:length(tSTM)
    STM = STM_hist(:,:,i);
    X_p_STM(:,i) = X_ref(i,:)' + STM*deltaX0;
end

%% Propagate STM and STT and use them for deltaX0

X0STMSTT = [X0; reshape(eye(nX),[],1); reshape((zeros([nX nX nX])),[],1)];
fprintf('Simulating with STM and STT...')
tic
[tSTMSTT, X_STMSTT] = ode113(@(t,X) CR3BP_cart_control_STMSTT(t,X,mu_EM,c), tspan, X0STMSTT, ode_opts);
fprintf('done.\n')
toc
%%
X_p_STMSTT = NaN(nX,length(tSTMSTT));
for i = 1:length(tSTMSTT)
    STM = reshape(X_STMSTT(i,nX+1:nX+nX^2),nX,nX);
    STT = (reshape(X_STMSTT(i,nX+nX^2+1:end),[nX nX nX]));
    X_p_STMSTT(:,i) = X_ref(i,:)' + STM*deltaX0; %+ 0.5*double(ttv(STT,deltaX0,3))*deltaX0;
    for j = 1:nX
        X_p_STMSTT(j,i) = X_p_STMSTT(j,i) + 0.5*deltaX0'*(squeeze(STT(j,:,:)))*deltaX0;
    end
end

%%

figure
addToolbarExplorationButtons(gcf)
plot(X_ref(:,1), X_ref(:,2), 'DisplayName', 'Reference Trajectory'); hold on
plot(X_ref_p(:,1), X_ref_p(:,2), 'DisplayName', 'Perturbed Trajectory (full dynamics)');
plot(X_p_STM(1,:), X_p_STM(2,:), 'DisplayName', 'Perturbed Trajectory (STM)');
plot(X_p_STMSTT(1,:), X_p_STMSTT(2,:), 'DisplayName', 'Perturbed Trajectory (STM and STT)'); hold off
grid on
xlabel('x')
ylabel('y')
title('Full Dynamics')
legend()

figure
addToolbarExplorationButtons(gcf)
subplot(3,1,1)
plot(tspan,X_p_STM(1,:)'-X_ref_p(:,1), 'DisplayName','Difference between STM and full dynamics (x)'); hold on
plot(tspan,X_p_STMSTT(1,:)'-X_ref_p(:,1), 'DisplayName','Difference between STM+STT and full dynamics (x)'); hold off
grid on
xlabel('Time')
ylabel('Difference')
title('x component differences')
legend()
subplot(3,1,2)
plot(tspan,X_p_STM(2,:)'-X_ref_p(:,2), 'DisplayName','Difference between STM and full dynamics (y)'); hold on
plot(tspan,X_p_STMSTT(2,:)'-X_ref_p(:,2), 'DisplayName','Difference between STM+STT and full dynamics (y)'); hold off
grid on
xlabel('Time')
ylabel('Difference')
title('y component differences')
legend()
subplot(3,1,3)
plot(tspan,X_p_STM(3,:)'-X_ref_p(:,3), 'DisplayName','Difference between STM and full dynamics (z)'); hold on
plot(tspan,X_p_STMSTT(3,:)'-X_ref_p(:,3), 'DisplayName','Difference between STM+STT and full dynamics (z)'); hold off
grid on
xlabel('Time')
ylabel('Difference')
title('z component differences')
legend()

figure
addToolbarExplorationButtons(gcf)
subplot(3,1,1)
plot(tspan,X_p_STM(1,:)'-X_p_STMSTT(1,:)', 'DisplayName','Difference between STM and STM+STT propagation (x)');
grid on
xlabel('Time')
ylabel('Difference')
title('x component differences')
legend()
subplot(3,1,2)
plot(tspan,X_p_STM(2,:)'-X_p_STMSTT(2,:)', 'DisplayName','Difference between STM and STM+STT propagation (y)');
grid on
xlabel('Time')
ylabel('Difference')
title('y component differences')
legend()
subplot(3,1,3)
plot(tspan,X_p_STM(3,:)'-X_p_STMSTT(3,:)', 'DisplayName','Difference between STM and STM+STT propagation (z)');
grid on
xlabel('Time')
ylabel('Difference')
title('z component differences')
legend()