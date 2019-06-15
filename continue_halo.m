function target_info = continue_halo(Az_km_old, tau, cont_scale_fac, target_state_old, mu, LU, L_point_string, halo_pole, varargin)
    
    % This function is used to continue target orbits in DDP.
    % Az_old is the z amplitude of the previous target orbit, and tau is
    % the time along that orbit of the previous target state.
    
    %% Input conditioning
    
    p = inputParser;
    valid_scalar_pos_num = @(x) isnumeric(x) && isscalar(x) && (x>0);
    valid_ICs = @(x) all(size(x)==[6 1]);
    valid_f_handle = @(x) isa(x, 'function_handle');
    valid_bool = @(x) isa(x,'logical');
    valid_int = @(x) mod(x,1)==0;
    valid_text = @(x) isstring(x) || ischar(x);
    
    % Required input parameters
    addRequired(p,'Az_km_old',valid_scalar_pos_num);
    addRequired(p,'tau',valid_scalar_pos_num);
    addRequired(p,'cont_scale_fac',valid_scalar_pos_num);
    addRequired(p,'target_state_old',valid_ICs);
    addRequired(p,'mu',valid_scalar_pos_num);
    addRequired(p,'LU',valid_scalar_pos_num);
    addRequired(p,'L_point_string',valid_text);
    addRequired(p,'halo_pole',valid_text);
    
    % Optional input parameters
    default_bool_plot = false;
    addParameter(p,'bool_plot',default_bool_plot,valid_bool);
    
    parse(p,Az_km_old,tau,cont_scale_fac,target_state_old,mu,LU,L_point_string,halo_pole,varargin{:});
    
    % Assign required parameters
    Az_km_old = p.Results.Az_km_old;
    tau = p.Results.tau;
    cont_scale_fac = p.Results.cont_scale_fac;
    target_state_old = p.Results.target_state_old;
    mu = p.Results.mu;
    LU = p.Results.LU;
    L_point_string = p.Results.L_point_string;
    halo_pole = p.Results.halo_pole;
    
    % Assign optional parameters
    bool_plot = p.Results.bool_plot;
    
    %% Add all subfolders to path in case they are not already accessible
    addpath(genpath(pwd));
    
    %% Find old and new orbits
    
    old_orbit = halo_computeplot(mu, Az_km_old, LU, L_point_string, halo_pole,0);
    
    Az_km_new = Az_km_old*cont_scale_fac; % scale Az by desired scaling factor Aznew = Azold*(1+epsilon)
    
    new_orbit = halo_computeplot(mu,Az_km_new,LU,L_point_string,halo_pole,0);
    
    %% Integrate both orbits to their target state
    
    ode_opts = odeset('RelTol',1e-13,'AbsTol',1e-19);
    [t_old, x_old] = ode113(@(t,X) CR3BP(t,X,mu), [0, tau], old_orbit{1}, ode_opts);
    
    tau_new = tau/old_orbit{2}*new_orbit{2}; % new time along new orbit is proportional to old time along old orbit
    [t_new, x_new] = ode113(@(t,X) CR3BP(t,X,mu), [0, tau_new], new_orbit{1}, ode_opts);
      
    %% Plot if desired
    
    if bool_plot
        L_points = lagrangePoints(mu);
        
        plot_fig = figure('position',[1225,453,1044,592]);
        set(gcf, 'Color', 'w');
        addToolbarExplorationButtons(gcf)
        hold on
        %scatter3((1-mu), 0, 0,'x','DisplayName', 'Earth');
        %scatter3(L_points(1,1), L_points(2,1), 0, 70, 'bd', 'filled', 'DisplayName', '$$L_1$$');
        scatter3(L_points(1,2), L_points(2,2), L_points(3,2), 100, 'd', 'filled', 'MarkerFaceColor','r','MarkerEdgeColor','k','DisplayName', '$$L_2$$', 'HandleVisibility','off'); hold on
        text(L_points(1,2), L_points(2,2), L_points(3,2)-0.00025, '$$L_2$$','HorizontalAlignment','Center','FontSize',18);
        plot3(x_old(:,1), x_old(:,2), x_old(:,3), '-','color',[59 119 8]./255,'DisplayName', 'Old Halo Orbit');
        plot3(x_old(1,1), x_old(1,2), x_old(1,3), 'ok', 'markerfacecolor', [59 119 8]./255, 'DisplayName', 'Old Halo Initial Point');
        plot3(x_old(end,1), x_old(end,2), x_old(end,3), 'dk', 'markerfacecolor', [59 119 8]./255, 'DisplayName', 'Old Target');
        plot3(x_new(:,1), x_new(:,2), x_new(:,3), 'm-','DisplayName', 'New Halo Orbit');
        plot3(x_new(1,1), x_new(1,2), x_new(1,3), 'ok', 'markerfacecolor', 'm', 'DisplayName', 'New Halo Initial Point');
        plot3(x_new(end,1), x_new(end,2), x_new(end,3), 'dk', 'markerfacecolor', 'm', 'DisplayName', 'New Target');
        hold off
        grid on
        set(gca,'DataAspectRatio',[1 1 1]);
        legend('FontSize',15)
        xlabel('x')
        ylabel('y')
        zlabel('z')
        view([56 23])
        %title("Old and new target halo orbits")
    else
        plot_fig = [];
    end
    
    %% Output stuff
    
    target_state_new = reshape(x_new(end,1:6),[],1);
    target_state_diff = target_state_new - target_state_old;
    
    target_info = struct('target_state',target_state_new,'Az',Az_km_new,'tau',tau_new,'target_diff',target_state_diff,'plot',plot_fig);
    
end