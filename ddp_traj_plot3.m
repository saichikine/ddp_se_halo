function [fig_traj, fig_control, fig_control_mag] = ddp_traj_plot3(traj,first_prim,second_prim)

    % Some (very not robust) input handling for colors
    if strcmpi(first_prim,"earth")
        first_prim_color = [58 128 242]./255;
    elseif strcmpi(first_prim,"moon")
        first_prim_color = [122 122 122]./255;
    else
        first_prim_color = [0 0 0]./255;
    end

    spacing = 3;

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

    fig_traj = figure('position',[1388,522,1003,536]); hold on;
    addToolbarExplorationButtons(fig_traj)
    first_prim_plot = scatter3(1-traj.mu, 0, 0, 300,'o','filled','markerfacecolor',first_prim_color,'markeredgecolor',[0, 0, 0]./255,'DisplayName',first_prim,'HandleVisibility','off');
    text(1-traj.mu, 0, 0+0.001, first_prim,'HorizontalAlignment','Center','FontSize',16)
    scatter3(L_points(1,1), L_points(2,1), 0, 100, 'd', 'filled', 'MarkerFaceColor','b','MarkerEdgeColor','k','DisplayName', '$$L_1$$', 'HandleVisibility','off');
    text(L_points(1,1), L_points(2,1), L_points(3,1)-0.0012, '$$L_1$$','HorizontalAlignment','Center','FontSize',18);
    scatter3(L_points(1,2), L_points(2,2), 0, 100, 'd', 'filled', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName', '$$L_2$$', 'HandleVisibility','off');
    text(L_points(1,2), L_points(2,2), L_points(3,2)-0.0012, '$$L_2$$','HorizontalAlignment','Center','FontSize',18);
    plot3(states(1,:), states(2,:), states(3,:), '.-', 'MarkerSize',10,'color',[0,0.4470,0.7410],'DisplayName','Trajectory','HandleVisibility','off');
    quiver3(states(1,1:spacing:end), states(2,1:spacing:end), states(3,1:spacing:end), u(1,1:spacing:end), u(2,1:spacing:end), u(3,1:spacing:end), 1.5, 'Color',[0.8500,0.3250,0.0980],'linewidth',2,'ShowArrowHead','off','DisplayName', 'Thrust Vectors');
    scatter3(initial_state(1), initial_state(2), initial_state(3), 70, 's','MarkerFaceColor','c','MarkerEdgeColor','k','DisplayName','Initial State');
    scatter3(target_state_posvel(1), target_state_posvel(2), target_state_posvel(3), 70,'s','MarkerFaceColor','m','MarkerEdgeColor','k','DisplayName', 'Target State');
    hold off
    grid on
    legend('FontSize',16);
    set(gca,'DataAspectRatio',[1 1 1]);
    xlabel('x');
    ylabel('y');
    zlabel('z');
    view([-37.1298828125,29.7275390625]);
    set(gcf,'color','w');

    fig_control = figure('position',[1260,340,842,625]);
    addToolbarExplorationButtons(fig_control)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(1,:), '.-','MarkerSize',15,'DisplayName','$$T_x$$'); hold on
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(2,:), '.-','MarkerSize',15,'DisplayName','$$T_y$$');
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(3,:), '.-','MarkerSize',15,'DisplayName','$$T_z$$'); hold off
    grid on
    legend('FontSize',18)
    title('Control History');
    ylabel('Thrust [mN]');
    xlabel('Time [days]');
    set(gcf,'color','w');
    
    fig_control_mag = figure('position',[1260,340,842,625]);
    addToolbarExplorationButtons(fig_control_mag)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u_mag, '.-','MarkerSize',15,'DisplayName','Thrust Magnitude');
    grid on
    legend();
    title('Control Magnitude History');
    ylabel('Thrust Magnitude [mN]');
    xlabel('Time [days]');
    set(gcf,'color','w');
    
end