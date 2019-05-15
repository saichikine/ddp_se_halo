function [fullplot,xyplot,yzplot,xzplot] = ddp_continue_set_plot(continuation_set,num_conts)

    L_points = lagrangePoints(continuation_set{1}.traj.mu); 
    x_L1 = L_points(1,1);
    x_L2 = L_points(1,2);
    FU = continuation_set{1}.traj.normalizers.FU;
    
    % 3D plot
    full_plot = figure;
    addToolbarExplorationButtons(full_plot)
    scatter3(x_L1, 0, 0, 'rd', 'DisplayName','L1'); hold on
    scatter3(x_L2, 0, 0, 'bd', 'DisplayName','L2');
    plot3(1-continuation_set{1}.traj.mu, 0, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
    scatter3(continuation_set{1}.traj.initial_state(1), continuation_set{1}.traj.initial_state(2), continuation_set{1}.traj.initial_state(3), 'co','filled','DisplayName','Initial State');   
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
        tp = plot3(states(1,:), states(2,:), states(3,:), '.-','DisplayName',trans_label_string);
        c = get(tp,'Color');
        quiver3(states(1,:), states(2,:), states(3,:), u(1,:), u(2,:), u(3,:), 1.1, 'Color', c, 'HandleVisibility','off');
    end
    grid on
    legend();
    set(gca,'DataAspectRatio',[1 1 1]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    set(gcf,'color','w')
    
    % xy plot
    xy_plot = figure;
    addToolbarExplorationButtons(xy_plot)
    scatter(x_L1, 0, 'rd', 'DisplayName','L1'); hold on
    scatter(x_L2, 0, 'bd', 'DisplayName','L2');
    plot(1-continuation_set{1}.traj.mu, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
    scatter(continuation_set{1}.traj.initial_state(1), continuation_set{1}.traj.initial_state(2), 'co','filled','DisplayName','Initial State');      
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
        scatter(traj.target_state(1), traj.target_state(2), 'o','filled','HandleVisibility','off');
        tp = plot(states(1,:), states(2,:), '.-','DisplayName',trans_label_string);
        c = get(tp,'Color');
        quiver(states(1,:), states(2,:), u(1,:), u(2,:), 1.1, 'Color', c, 'HandleVisibility','off');
    end
    grid on
    legend();
    axis equal
    xlabel('x')
    ylabel('y')
    set(gcf,'color','w')
    
    % yz plot
    yz_plot = figure;
    addToolbarExplorationButtons(yz_plot)
    scatter(0, 0, 'rd', 'DisplayName','L1'); hold on
    scatter(0, 0, 'bd', 'DisplayName','L2');
    plot(0, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
    scatter(continuation_set{1}.traj.initial_state(2), continuation_set{1}.traj.initial_state(3), 'co','filled','DisplayName','Initial State');     
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
        scatter(traj.target_state(2), traj.target_state(3), 'o','filled','HandleVisibility','off');
        tp = plot(states(2,:), states(3,:), '.-','DisplayName',trans_label_string);
        c = get(tp,'Color');
        quiver(states(2,:), states(3,:), u(2,:), u(3,:), 1.1, 'Color', c, 'HandleVisibility','off');
    end
    grid on
    legend();
    axis equal
    xlabel('y')
    ylabel('z')
    set(gcf,'color','w')
    
    % xz plot
    xz_plot = figure;
    addToolbarExplorationButtons(xz_plot)
    scatter(x_L1, 0, 'rd', 'DisplayName','L1'); hold on
    scatter(x_L2, 0, 'bd', 'DisplayName','L2');
    plot(1-continuation_set{1}.traj.mu, 0, 'ok', 'markerfacecolor', 'b', 'markersize', 10, 'DisplayName', 'Earth'); hold on % Smaller primary
    scatter(continuation_set{1}.traj.initial_state(1), continuation_set{1}.traj.initial_state(3), 'co','filled','DisplayName','Initial State');     
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
        scatter(traj.target_state(1), traj.target_state(3), 'o','filled','HandleVisibility','off');
        tp = plot(states(1,:), states(3,:), '.-','DisplayName',trans_label_string);
        c = get(tp,'Color');
        quiver(states(1,:), states(3,:), u(1,:), u(3,:), 1.1, 'Color',c,'HandleVisibility','off');
    end
    grid on
    legend();
    axis equal
    xlabel('x')
    ylabel('z')
    set(gcf,'color','w')
    
end