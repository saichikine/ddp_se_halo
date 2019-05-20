function [fig_traj, fig_control, fig_control_mag] = ddp_traj_plot(traj)

    spacing = 2;

    TU = traj.normalizers.TU;
    FU = traj.normalizers.FU;
    initial_state = traj.initial_state;
    target_state_posvel = traj.target_state;

    L_points = lagrangePoints(traj.mu); 
    x_L1 = L_points(1,1);
    x_L2 = L_points(1,2);

    u = NaN(traj.nu,traj.num_stages);
    u_mag = NaN(1,traj.num_stages);
    for k = 1:traj.num_stages
        u(:,k) = traj.max_thrust_mag*FU*1000*1000.*(traj.stage{k}.nominal_u);%-traj.stage{k}.nominal_u); % FU is in kN; multiply by FU to get kN, then convert to mN
        u_mag(k) = norm(u(:,k));
        %fprintf("u diff at stage %i is:\n %d\n%d\n%d\n",k,u(1,k),u(2,k),u(3,k));
    end

    states = NaN(traj.nx,traj.num_stages);
    for k = 1:traj.num_stages
        states(:,k) = traj.stage{k}.state;
    end

    fig_traj = figure;
    addToolbarExplorationButtons(fig_traj)
    scatter(x_L1, 0, 'd', 'MarkerFaceColor','b','MarkerEdgeColor','k','DisplayName','L1'); hold on
    scatter(x_L2, 0, 'd', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName','L2');
    plot(1-traj.mu, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
    scatter(initial_state(1), initial_state(2), 50, 'o','MarkerFaceColor','c','MarkerEdgeColor','k','DisplayName','Initial State');
    scatter(target_state_posvel(1), target_state_posvel(2), 50,'o','MarkerFaceColor','m','MarkerEdgeColor','k','DisplayName', 'Target State');
    plot(states(1,:), states(2,:), '.-', 'MarkerSize',10,'DisplayName','Trajectory');
    quiver(states(1,1:spacing:end), states(2,1:spacing:end), u(1,1:spacing:end), u(2,1:spacing:end), 1.5, 'linewidth',2,'ShowArrowHead','off','DisplayName', 'Thrust Vectors');
    hold off
    grid on
    legend();
    axis equal
    xlabel('x')
    ylabel('y')
    set(gcf,'color','w')

    fig_control = figure;
    addToolbarExplorationButtons(fig_control)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(1,:), '.-','MarkerSize',15,'DisplayName','$$T_x$$'); hold on
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(2,:), '.-','MarkerSize',15,'DisplayName','$$T_y$$');
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(3,:), '.-','MarkerSize',15,'DisplayName','$$T_z$$'); hold off
    grid on
    legend()
    title('Control History')
    ylabel('Thrust [mN]')
    xlabel('Time [days]')
    set(gcf,'color','w')
    
    fig_control_mag = figure;
    addToolbarExplorationButtons(fig_control_mag)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u_mag, '.-','MarkerSize',15,'DisplayName','Thrust Magnitude');
    grid on
    %legend()
    title('Control Magnitude History')
    ylabel('Thrust Magnitude [mN]')
    xlabel('Time [days]')
    set(gcf,'color','w')
    
end