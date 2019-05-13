function [fig_traj, fig_control] = ddp_traj_plot(traj)

    TU = traj.normalizers.TU;
    FU = traj.normalizers.FU;
    initial_state = traj.initial_state;
    target_state_posvel = traj.target_state;

    L_points = lagrangePoints(traj.mu); 
    x_L1 = L_points(1,1);
    x_L2 = L_points(1,2);

    u = NaN(traj.nu,traj.num_stages);
    for k = 1:traj.num_stages
        u(:,k) = traj.max_thrust_mag*FU*1000*1000.*(traj.stage{k}.nominal_u);%-traj.stage{k}.nominal_u); % FU is in kN; multiply by FU to get kN, then convert to mN
        %fprintf("u diff at stage %i is:\n %d\n%d\n%d\n",k,u(1,k),u(2,k),u(3,k));
    end

    states = NaN(traj.nx,traj.num_stages);
    for k = 1:traj.num_stages
        states(:,k) = traj.stage{k}.state;
    end

    fig_traj = figure;
    addToolbarExplorationButtons(fig_traj)
    scatter(x_L1, 0, 'rd', 'DisplayName','L1'); hold on
    scatter(x_L2, 0, 'bd', 'DisplayName','L2');
    plot(1-traj.mu, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
    scatter(initial_state(1), initial_state(2), 'co','filled','DisplayName','Initial State');
    scatter(target_state_posvel(1), target_state_posvel(2), 'mo','filled','DisplayName', 'Target State');
    plot(states(1,:), states(2,:), '-o', 'DisplayName','Trajectory');
    quiver(states(1,:), states(2,:), u(1,:), u(2,:), 1.1, 'DisplayName', 'Thrust Vectors');
    hold off
    grid on
    legend();
    axis equal
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
    
end