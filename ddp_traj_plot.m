function [fig_traj, fig_control, fig_control_mag] = ddp_traj_plot(traj,first_prim,second_prim)

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

    fig_traj = figure('position',[1280 600 745 480]); hold on;
    addToolbarExplorationButtons(fig_traj)
    earth = scatter(1-traj.mu, 0, 300,'o','filled','markerfacecolor',[58 128 242]./255,'markeredgecolor',[0, 0, 0]./255,'DisplayName', first_prim, 'HandleVisibility','off');
    text(1-traj.mu, 0+0.018, first_prim,'HorizontalAlignment','Center','FontSize',16)
    annotation('textarrow',[0.5 0.42], [0.25 0.25], 'String',strcat("To ",second_prim),'FontSize',16,'interpreter','latex')
    scatter(x_L1, 0, 100, 'd', 'filled', 'MarkerFaceColor','b','MarkerEdgeColor','k','DisplayName', '$$L_1$$', 'HandleVisibility','off');
    text(x_L1, 0-0.018, '$$L_1$$','HorizontalAlignment','Center','FontSize',18)
    scatter(x_L2, 0, 100, 'd', 'filled', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName', '$$L_2$$', 'HandleVisibility','off');
    text(x_L2, 0-0.018, '$$L_2$$','HorizontalAlignment','Center','FontSize',18)
    plot(states(1,:), states(2,:), '.-', 'MarkerSize',10,'color',[0,0.4470,0.7410],'DisplayName','Trajectory','HandleVisibility','off');
    quiver(states(1,1:spacing:end), states(2,1:spacing:end), u(1,1:spacing:end), u(2,1:spacing:end), 1.5, 'Color',[0.8500,0.3250,0.0980],'linewidth',2,'ShowArrowHead','off','DisplayName', 'Thrust Vectors','HandleVisibility','off');
    scatter(initial_state(1), initial_state(2), 70, 's','MarkerFaceColor','c','MarkerEdgeColor','k','DisplayName','Initial State');
    scatter(target_state_posvel(1), target_state_posvel(2), 70,'s','MarkerFaceColor','m','MarkerEdgeColor','k','DisplayName', 'Target State');
    hold off
    grid on
    legend('FontSize',13);
    axis equal
    xlabel('x')
    ylabel('y')
    set(gcf,'color','w')

    fig_control = figure('position',[1260,340,842,625]);
    addToolbarExplorationButtons(fig_control)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(1,:), '.-','MarkerSize',15,'DisplayName','$$T_x$$'); hold on
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(2,:), '.-','MarkerSize',15,'DisplayName','$$T_y$$');
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u(3,:), '.-','MarkerSize',15,'DisplayName','$$T_z$$'); hold off
    grid on
    legend('FontSize',18)
    title('Control History')
    ylabel('Thrust [mN]')
    xlabel('Time [days]')
    set(gcf,'color','w')
    
    fig_control_mag = figure('position',[1260,340,842,625]);
    addToolbarExplorationButtons(fig_control_mag)
    plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u_mag, '.-','MarkerSize',15,'DisplayName','Thrust Magnitude');
    grid on
    %legend()
    title('Control Magnitude History')
    ylabel('Thrust Magnitude [mN]')
    xlabel('Time [days]')
    set(gcf,'color','w')
    
end