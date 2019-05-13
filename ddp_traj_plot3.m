function [fig_traj, fig_control] = ddp_traj_plot3(traj)

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
    scatter3(x_L1, 0, 0, 'rd', 'DisplayName','L1'); hold on
    scatter3(x_L2, 0, 0, 'bd', 'DisplayName','L2');
    plot3(1-traj.mu, 0, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
    scatter3(initial_state(1), initial_state(2), initial_state(3), 'co','filled','DisplayName','Initial State');
    scatter3(target_state_posvel(1), target_state_posvel(2), target_state_posvel(3), 'mo','filled','DisplayName', 'Target State');
    plot3(states(1,:), states(2,:), states(3,:), '-o', 'DisplayName','Trajectory');
    quiver3(states(1,:), states(2,:), states(3,:), u(1,:), u(2,:), u(3,:), 1.1, 'DisplayName', 'Thrust Vectors');
    hold off
    grid on
    legend();
    set(gca,'DataAspectRatio',[1 1 1]);
    xlabel('x')
    ylabel('y')

    fig_control = figure;
    addToolbarExplorationButtons(fig_control)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(1,:), '-o','DisplayName','x thrust'); hold on
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(2,:), '-o','DisplayName','y thrust');
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(3,:), '-o','DisplayName','z thrust'); hold off
    grid on
    legend()
    title('Control History')
    ylabel('Thrust [mN]')
    xlabel('Time [days]')
    
    fig_control_mag = figure;
    addToolbarExplorationButtons(fig_control_mag)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u_mag, '-o','DisplayName','Thrust Magnitude');
    grid on
    legend()
    title('Control Magnitude History')
    ylabel('Thrust Magnitude [mN]')
    xlabel('Time [days]')
    
end