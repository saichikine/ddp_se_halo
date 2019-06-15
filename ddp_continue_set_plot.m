function [fullplot,xyplot,yzplot,xzplot,magplot] = ddp_continue_set_plot(continuation_set,num_conts,first_prim,second_prim)

    L_points = lagrangePoints(continuation_set{1}.traj.mu); 
    x_L1 = L_points(1,1);
    x_L2 = L_points(1,2);
    FU = continuation_set{1}.traj.normalizers.FU;
    TU = continuation_set{1}.traj.normalizers.TU;
    initial_state = continuation_set{1}.traj.initial_state;
    spacing = 3;
    mu = continuation_set{1}.traj.mu;
    
    % Colors vectors
    len = length(continuation_set);
    blue = [0, 0, 1];
    red = [1, 0, 1];
    colors_p = [linspace(blue(1),red(1),len)', linspace(blue(2),red(2),len)', linspace(blue(3),red(3),len)'];
    
    % 3D plot
    full_plot = figure('position',[1388,522,1003,536]); hold on;
    addToolbarExplorationButtons(full_plot)
    earth = scatter3(1-mu, 0, 0, 300,'o','filled','markerfacecolor',[58 128 242]./255,'markeredgecolor',[0, 0, 0]./255,'DisplayName',first_prim,'HandleVisibility','off');
    text(1-mu, 0, 0+0.001, first_prim,'HorizontalAlignment','Center','FontSize',16)
    scatter3(L_points(1,1), L_points(2,1), 0, 100, 'd', 'filled', 'MarkerFaceColor','b','MarkerEdgeColor','k','DisplayName', '$$L_1$$', 'HandleVisibility','off');
    text(L_points(1,1), L_points(2,1), L_points(3,1)-0.0012, '$$L_1$$','HorizontalAlignment','Center','FontSize',18);
    scatter3(L_points(1,2), L_points(2,2), 0, 100, 'd', 'filled', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName', '$$L_2$$', 'HandleVisibility','off');
    text(L_points(1,2), L_points(2,2), L_points(3,2)-0.0012, '$$L_2$$','HorizontalAlignment','Center','FontSize',18);
    
    %scatter3(target_state_posvel(1), target_state_posvel(2), target_state_posvel(3), 50,'o','MarkerFaceColor','m','MarkerEdgeColor','k','DisplayName', 'Target State');
    for i = 1:num_conts
        trans_label_string = "Transfer " + num2str(i);
        targ_label_string = "Target " + num2str(i);
        traj = continuation_set{i}.traj;
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
        scatter3(traj.target_state(1), traj.target_state(2), traj.target_state(3), 'o','filled','HandleVisibility','off');
        scatter3(traj.target_state(1), traj.target_state(2), traj.target_state(3), 50,'o','MarkerFaceColor','m','MarkerEdgeColor','k','HandleVisibility', 'Off');
        tp = plot3(states(1,:), states(2,:), states(3,:), '.-','Color',colors_p(i,:),'DisplayName',trans_label_string);
        %c = get(tp,'Color');
         quiver3(states(1,1:spacing:end), states(2,1:spacing:end), states(3,1:spacing:end), u(1,1:spacing:end), u(2,1:spacing:end), u(3,1:spacing:end), 1.5, 'Color',colors_p(i,:),'linewidth',2,'ShowArrowHead','off','HandleVisibility', 'off');
    end
    scatter3(initial_state(1), initial_state(2), initial_state(3), 70, 's','MarkerFaceColor','c','MarkerEdgeColor','k','DisplayName','Initial State');
    grid on
    legend();
    set(gca,'DataAspectRatio',[1 1 1]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    view([-37.1298828125,29.7275390625]);
    set(gcf,'color','w')
    
    % xy plot
    xy_plot = figure('position',[1260,340,842,625]); hold on
    addToolbarExplorationButtons(gcf);
    earth = scatter(1-mu, 0, 300,'o','filled','markerfacecolor',[58 128 242]./255,'markeredgecolor',[0, 0, 0]./255,'DisplayName',first_prim,'HandleVisibility','off');
    text(1-mu, 0+0.001, first_prim,'HorizontalAlignment','Center','FontSize',16)
    annotation('textarrow',[0.5 0.43], [0.2 0.2], 'String',strcat("To ",second_prim),'FontSize',16,'interpreter','latex')
    scatter(L_points(1,1), L_points(2,1), 100, 'd', 'filled', 'MarkerFaceColor','b','MarkerEdgeColor','k','DisplayName', '$$L_1$$', 'HandleVisibility','off');
    text(L_points(1,1), L_points(2,1)-0.001, '$$L_1$$','HorizontalAlignment','Center','FontSize',18);
    scatter(L_points(1,2), L_points(2,2), 100, 'd', 'filled', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName', '$$L_2$$', 'HandleVisibility','off');
    text(L_points(1,2), L_points(2,2)-0.001, '$$L_2$$','HorizontalAlignment','Center','FontSize',18);
         
    for i = 1:num_conts
        trans_label_string = "Transfer " + num2str(i);
        targ_label_string = "Target " + num2str(i);
        traj = continuation_set{i}.traj;
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
        scatter(traj.target_state(1), traj.target_state(2),'o','MarkerFaceColor','m','MarkerEdgeColor','k','HandleVisibility','off');
        tp = plot(states(1,:), states(2,:), '.-','Color',colors_p(i,:),'DisplayName',trans_label_string);
        %c = get(tp,'Color');
        quiver(states(1,:), states(2,:), u(1,:), u(2,:), 1.1, 'Color', colors_p(i,:), 'linewidth',2,'ShowArrowHead','off','HandleVisibility','off');
    end
    scatter(initial_state(1), initial_state(2), 70, 's','MarkerFaceColor','c','MarkerEdgeColor','k','DisplayName','Initial State', 'HandleVisibility', 'off'); 
    grid on
    %legend();
    axis equal
    xlabel('x')
    ylabel('y')
    set(gcf,'color','w')
    
    % yz plot
    yz_plot = figure('position',[1260,340,842,625]); hold on
    addToolbarExplorationButtons(gcf);
    earth = scatter(0, 0, 300,'o','filled','markerfacecolor',[58 128 242]./255,'markeredgecolor',[0, 0, 0]./255,'DisplayName',first_prim,'HandleVisibility','off');
    %text(0, 0+0.001, first_prim,'HorizontalAlignment','Center','FontSize',16)
    scatter(L_points(2,1), L_points(3,1), 100, 'd', 'filled', 'MarkerFaceColor','b','MarkerEdgeColor','k','DisplayName', '$$L_1$$', 'HandleVisibility','off');
    %text(L_points(2,1), L_points(3,1)+0.0008, '$$L_1$$','HorizontalAlignment','Center','FontSize',18);
    scatter(L_points(2,2), L_points(3,2), 100, 'd', 'filled', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName', '$$L_2$$', 'HandleVisibility','off');
    %text(L_points(2,2), L_points(3,2)+0.0008, '$$L_2$$','HorizontalAlignment','Center','FontSize',18);
    
    for i = 1:num_conts
        trans_label_string = "Transfer " + num2str(i);
        targ_label_string = "Target " + num2str(i);
        traj = continuation_set{i}.traj;
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
        scatter(traj.target_state(2), traj.target_state(3), 'o','MarkerFaceColor','m','MarkerEdgeColor','k','HandleVisibility','off');
        tp = plot(states(2,:), states(3,:), '.-','Color',colors_p(i,:),'DisplayName',trans_label_string);
        %c = get(tp,'Color');
        quiver(states(2,:), states(3,:), u(2,:), u(3,:), 1.1, 'Color', colors_p(i,:), 'linewidth',2,'ShowArrowHead','off','HandleVisibility','off');
    end
    scatter(initial_state(2), initial_state(3), 70, 's','MarkerFaceColor','c','MarkerEdgeColor','k','DisplayName','Initial State', 'HandleVisibility', 'off');
    grid on
    %legend();
    axis equal
    xlabel('y')
    ylabel('z')
    set(gcf,'color','w')
    
    % xz plot
    xz_plot = figure('position',[1260,340,842,625]); hold on
    addToolbarExplorationButtons(gcf);
    earth = scatter(1-traj.mu, 0, 300,'o','filled','markerfacecolor',[58 128 242]./255,'markeredgecolor',[0, 0, 0]./255,'DisplayName',first_prim,'HandleVisibility','off');
    text(1-traj.mu, 0+0.001, first_prim,'HorizontalAlignment','Center','FontSize',16)
    annotation('textarrow',[0.5 0.43], [0.32 0.32], 'String',strcat("To ",second_prim),'FontSize',16,'interpreter','latex')
    scatter(L_points(1,1), L_points(3,1), 100, 'd', 'filled', 'MarkerFaceColor','b','MarkerEdgeColor','k','DisplayName', '$$L_1$$', 'HandleVisibility','off');
    text(L_points(1,1), L_points(3,1)+0.0008, '$$L_1$$','HorizontalAlignment','Center','FontSize',18);
    scatter(L_points(1,2), L_points(3,2), 100, 'd', 'filled', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName', '$$L_2$$', 'HandleVisibility','off');
    text(L_points(1,2), L_points(3,2)+0.0008, '$$L_2$$','HorizontalAlignment','Center','FontSize',18);
    scatter(initial_state(1), initial_state(3), 70, 's','MarkerFaceColor','c','MarkerEdgeColor','k','DisplayName','Initial State', 'HandleVisibility', 'off'); 
    for i = 1:num_conts
        trans_label_string = "Transfer " + num2str(i);
        targ_label_string = "Target " + num2str(i);
        traj = continuation_set{i}.traj;
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
        scatter(traj.target_state(1), traj.target_state(3), 'o','MarkerFaceColor','m','MarkerEdgeColor','k','HandleVisibility','off');
        tp = plot(states(1,:), states(3,:), '.-','Color',colors_p(i,:),'DisplayName',trans_label_string);
        %c = get(tp,'Color');
        quiver(states(1,:), states(3,:), u(1,:), u(3,:), 1.1, 'Color',colors_p(i,:),'linewidth',2,'ShowArrowHead','off','HandleVisibility','off');
    end
    grid on
    %legend();
    axis equal
    xlabel('x')
    ylabel('z')
    set(gcf,'color','w')
    
    % Plot with all control magnitude profiles
    magplot = figure('position',[1260,340,842,625]);
    addToolbarExplorationButtons(magplot)
    hold on
    for i = 1:num_conts
        trans_label_string = "Transfer " + num2str(i);
        targ_label_string = "Target " + num2str(i);
        traj = continuation_set{i}.traj;
        u = NaN(traj.nu,traj.num_stages);
        u_mag = NaN(1,traj.num_stages);
        for k = 1:traj.num_stages
            u(:,k) = traj.max_thrust_mag*FU*1000*1000.*(traj.stage{k}.nominal_u);%-traj.stage{k}.nominal_u); % FU is in kN; multiply by FU to get kN, then convert to mN
            u_mag(k) = norm(u(:,k));
            %fprintf("u diff at stage %i is:\n %d\n%d\n%d\n",k,u(1,k),u(2,k),u(3,k));
        end
        
        plot(traj.stage_times(1:traj.num_stages).*TU/60/60/24, u_mag, '-','Color',colors_p(i,:),'DisplayName',trans_label_string);
        
    end
    hold off
    grid on
    %legend()
    title('Control Magnitude History')
    ylabel('Thrust Magnitude [mN]')
    xlabel('Time [days]')
    set(gcf,'color','w')
    
end