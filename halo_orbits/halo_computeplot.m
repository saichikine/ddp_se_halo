function halo_orbit = halo_computeplot(mu, Az_km, L_km, L_point_string, halo_pole, varargin)
    % Returns initial conditions for Halo orbit for a mu value and fixed Az
    
    %% Input checking
    
    if nargin>6
        error('Maximum of 6 arguments.')
    end
    
    if ~isstring(halo_pole)
        error('Fifth argument must be a string.')
    end
    
    if (~strcmpi(halo_pole,"south") && ~strcmpi(halo_pole,"north"))
        error('Fifth argument must be either "south" or "north"')
    end
    
    if ~isstring(L_point_string)
        error('Fourth argument must be a string.')
    end
    
    if (~strcmpi(L_point_string,"l1") && ~strcmpi(L_point_string,"l2"))
        error('Fourth argument must be either "L1" or "L2"')
    end
    
    plot_flag = 1;
    if size(varargin)>0
        plot_flag = varargin{1};
    end
    
    %% L1 or L2?
    
    L_points = lagrangePoints(mu);
    gammas = CR3BP_L1_L2_gammas(mu);
    
    if strcmpi(L_point_string,'l1')
        L_point = L_points(:,1);
        gamma = gammas.one;
    elseif strcmpi(L_point_string,'l2')
        L_point = L_points(:,2);
        gamma = gammas.two;
    else
        error('You should not be here.')
    end
    
    %% Get things
    
    c_n = c_n_coeffs(mu, gamma, L_point_string);
    freqs = halo_third_order_freqs(c_n);
    
    c2 = c_n(2);
    
    kappa = (freqs.wp^2 + 1 + 2*c2)/(2*freqs.wp);
    Delta = freqs.wp^2 - c2;
    
    coeffs = halo_third_order_coeffs(c_n);
    
    if strcmpi(halo_pole, "south")
        m = 3;
    elseif strcmpi(halo_pole, "north")
        m = 1;
    else
        error('You really should not be here.')
    end
    
    % Southern or northern halo
    delta_m = 2-m;
    
    % Halo amplitudes
    Az = Az_km/(L_km*gamma);
    Ax = sqrt((-coeffs.l12(2)*Az^2 - Delta)/coeffs.l12(1));
    Ay = kappa*Ax;
    
    % Get approximate orbit period
    nu_1 = 0;
    nu_2 = coeffs.s12(1)*Ax^2 + coeffs.s12(2)*Az^2;
    nu = 1 + nu_1 + nu_2;
    
    orbit_period = 2*pi/(freqs.wp*nu);
    
    % Third order ICs from third order approximate solution
    % Note: in coord system where L point is origin
    x_guess = coeffs.a(2,1)*Ax^2 + coeffs.a(2,2)*Az^2 - Ax + (coeffs.a(2,3)*Ax^2 - coeffs.a(2,4)*Az^2) + (coeffs.a(3,1)*Ax^3 - coeffs.a(3,2)*Ax*Az^2);
    ydot_guess = freqs.wp*kappa*nu*Ax + 2*freqs.wp*nu*(coeffs.b(2,1)*Ax^2 - coeffs.b(2,2)*Az^2) + 3*freqs.wp*nu*(coeffs.b(3,1)*Ax^3 - coeffs.b(3,2)*Ax*Az^2);
    z_guess = delta_m*Az + delta_m*coeffs.d(2,1)*Ax*Az*(1-3) + delta_m*(coeffs.d(3,2)*Az*Ax^2 - coeffs.d(3,1)*Az^3);
    
    % Transform back into usual CR3BP coordinate system
    if strcmpi(L_point_string,"L1")
        x0 = (1-mu) + gamma*(x_guess - 1);
    elseif strcmpi(L_point_string,"L2")
        x0 = (1-mu) + gamma*(x_guess + 1);
    else
        error('This is bad.')
    end
    dy0 = ydot_guess*gamma;
    z0 = z_guess*gamma;
%     z0 = Az*gamma;
    
    %% Compute initial guess orbit
    
    STM0 = reshape(eye(6),36,[]);
    X0_guess = [x0; 0; z0; 0; dy0; 0; STM0];
    
    ode_opts = odeset('RelTol',1e-13,'AbsTol',1e-22);
    
    %fprintf('Initial guess orbit.\n')
    %fprintf('Simulating...')
    %tic
    [t_guess, X_guess_hist] = ode113(@(t,X) CR3BP(t,X,mu), [0 orbit_period], X0_guess, ode_opts);
    %fprintf('done.\n')
    %toc
    
    %% Plot initial guess orbit
    
    if plot_flag
        xL1 = L_points(1,1);
        xL2 = L_points(1,2);

        % Large picture
        figure
        addToolbarExplorationButtons(gcf) % Adds buttons to figure toolbar

        subplot(2,1,1)
        plot3(X_guess_hist(:,1), X_guess_hist(:,2), X_guess_hist(:,3), 'DisplayName', 'Approximate Halo Orbit'); hold on
        plot3(X_guess_hist(1,1), X_guess_hist(1,2), X_guess_hist(1,3), 'ok', 'markerfacecolor', 'y', 'DisplayName', 'Initial Point'); hold on
        plot3(-mu, 0, 0, 'ok', 'markerfacecolor', 'k', 'markersize', 10, 'DisplayName', 'Larger Primary'); hold on % Larger primary
        plot3(1-mu, 0, 0, 'ok', 'markerfacecolor', 'm', 'markersize', 5, 'DisplayName', 'Smaller Primary'); hold on % Smaller primary
        plot3(xL1, 0, 0, 'ok', 'markerfacecolor', 'r', 'markersize', 2, 'DisplayName', 'L1 Point'); hold on % L1 location
        plot3(xL2, 0, 0, 'ok' , 'markerfacecolor', 'b', 'markersize', 2, 'DisplayName', 'L2 Point'); hold on % L2 location
        title('Initial (Approximate) Halo Orbit');
        xlabel('X')
        ylabel('Y')
        zlabel('Z')
        grid on;
        legend();
        hold off

        % Close up around Lagrange point
        subplot(2,1,2)
        addToolbarExplorationButtons(gcf) % Adds buttons to figure toolbar
        plot3(1-mu, 0, 0, 'ok', 'markerfacecolor', 'm', 'markersize', 8, 'DisplayName', 'Smaller Primary'); hold on % Smaller primary
        plot3(X_guess_hist(1,1), X_guess_hist(1,2), X_guess_hist(1,3), 'ok', 'markerfacecolor', 'y', 'DisplayName', 'Initial Point'); hold on
        plot3(xL1, 0, 0, 'ok', 'markerfacecolor', 'r', 'DisplayName', 'L1 Point'); hold on % L1 location
        plot3(xL2, 0, 0, 'ok' , 'markerfacecolor', 'b', 'DisplayName', 'L2 Point'); hold on % L2 location
        plot3(X_guess_hist(:,1), X_guess_hist(:,2), X_guess_hist(:,3), 'DisplayName', 'Approximate Halo Orbit'); hold on
        title('Initial (Approximate) Halo Orbit (Close Up)')
        xlabel('X')
        ylabel('Y')
        zlabel('Z')
        grid on;
        legend();
        hold off
    end
    %% Differential Correction
    
    ode_opts_XZ_crossing = odeset('Events',@Findyzero,'RelTol',1e-13,'AbsTol',1e-13);
    X0 = X0_guess;

    verbose = 0;

    delta_vec = [100; 100];
    counter = 0;
    
    %fprintf('Targeting periodic Halo orbit...\n')
    %tic
    while (norm(delta_vec) > 1e-13)
        counter = counter+1;
        [t_half,X_half] = ode113(@(t,X) CR3BP(t,X,mu), [0 inf], X0, ode_opts_XZ_crossing);

        % State when y=0 (half orbit period)
        dX = X_half(end,1:6);

        % STM at half orbit period
        dPhi = reshape(X_half(end,7:end),6,[]);

        %% dX/dt (X is state)
        x_dot = dX(4);
        y_dot = dX(5);
        z_dot = dX(6);

        r1 = sqrt((dX(1)+mu)^2 + dX(2)^2 + dX(3)^2); %S/C distance to Sun
        r2 = sqrt((dX(1)-1+mu)^2 + dX(2)^2 + dX(3)^2); %S/C distance to Earth

        % Accelerations
        x_ddot = 2*y_dot + dX(1) - (1 - mu)*((dX(1) + mu)/(r1^3)) - mu*(dX(1) - 1 + mu)/(r2^3);
        y_ddot = -2*x_dot + dX(2) - (1 - mu)*(dX(2)/(r1^3)) - mu*(dX(2))/(r2^3);
        z_ddot = -(1 - mu)*(dX(3))/(r1^3) - mu*(dX(3))/(r2^3); 

        % Derivative of new state
        dXdt = [x_dot y_dot z_dot x_ddot y_ddot z_ddot];

        %Update matrix to correct deltaVec
        %Only changes x0 and doty0, holds z0 constant
        update_mat = [dPhi(4,1)-dPhi(2,1)*(x_ddot/y_dot), dPhi(4,5)-dPhi(2,5)*(x_ddot/y_dot);...
            dPhi(6,1)-dPhi(2,1)*(z_ddot/y_dot), dPhi(6,5)-dPhi(2,5)*(z_ddot/y_dot)];

        delta_vec = inv(update_mat)*[-X_half(end,4); -X_half(end,6)];

        if verbose
            norm(delta_vec)
            fprintf('Iteration counter: %d\n', counter)
        end

        delta_X = [delta_vec(1), 0, 0, 0, delta_vec(2), 0]';

        X0(1:6) = X0(1:6) + delta_X;
    end
    %fprintf('done.\n')
    %toc

    %% New orbit with periodic initial conditions

    %Integrate orbit with solved initial conditions
    %fprintf('Corrected periodic orbit.\n')
    %fprintf('Simulating...')
    %tic
    [t_corrected, X_corrected_hist] = ode113(@(t,X) CR3BP(t,X,mu), [0 t_half(end)*2], X0, ode_opts);
    %fprintf('done.\n')
    %toc
    
    halo_orbit{1} = X0(1:6);
    halo_orbit{2} = t_half(end)*2;
    
    %% Plot Corrected Orbit
    
    if plot_flag
        figure
        addToolbarExplorationButtons(gcf) % Adds buttons to figure toolbar

%         subplot(2,1,1)
%         plot3(X_corrected_hist(:,1), X_corrected_hist(:,2), X_corrected_hist(:,3), 'DisplayName', 'Corrected Halo Orbit'); hold on
%         plot3(X_corrected_hist(1,1), X_corrected_hist(1,2), X_corrected_hist(1,3), 'ok', 'markerfacecolor', 'y', 'DisplayName', 'Initial Point'); hold on
%         plot3(-mu, 0, 0, 'ok', 'markerfacecolor', 'k', 'markersize', 10, 'DisplayName', 'Larger Primary'); hold on % Larger primary
%         plot3(1-mu, 0, 0, 'ok', 'markerfacecolor', 'm', 'markersize', 5, 'DisplayName', 'Smaller Primary'); hold on % Smaller primary
%         plot3(xL1, 0, 0, 'ok', 'markerfacecolor', 'r', 'markersize', 2, 'DisplayName', 'L1 Point'); hold on % L1 location
%         plot3(xL2, 0, 0, 'ok' , 'markerfacecolor', 'b', 'markersize', 2, 'DisplayName', 'L2 Point'); hold on % L2 location
%         title('Corrected Periodic Halo Orbit');
%         xlabel('X')
%         ylabel('Y')
%         zlabel('Z')
%         grid on;
%         legend();
%         hold off

        % Close up around Lagrange point
        subplot(2,1,2)
        addToolbarExplorationButtons(gcf) % Adds buttons to figure toolbar
        plot3(1-mu, 0, 0, 'ok', 'markerfacecolor', 'm', 'markersize', 8, 'DisplayName', 'Smaller Primary'); hold on % Smaller primary
        plot3(X_corrected_hist(1,1), X_corrected_hist(1,2), X_corrected_hist(1,3), 'ok', 'markerfacecolor', 'y', 'DisplayName', 'Initial Point'); hold on
        plot3(xL1, 0, 0, 'ok', 'markerfacecolor', 'r', 'DisplayName', 'L1 Point'); hold on % L1 location
        plot3(xL2, 0, 0, 'ok' , 'markerfacecolor', 'b', 'DisplayName', 'L2 Point'); hold on % L2 location
        plot3(X_corrected_hist(:,1), X_corrected_hist(:,2), X_corrected_hist(:,3), 'DisplayName', 'Corrected Halo Orbit'); hold on
        title('Corrected Periodic Halo Orbit (Close Up)')
        xlabel('X')
        ylabel('Y')
        zlabel('Z')
        grid on;
        legend();
        hold off
    end
end