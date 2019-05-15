function conv_plot = ddp_conv_plot(ddp_func_output)

    max_iters = length(ddp_func_output.J_hist)-1;
    iteration_data = linspace(0,max_iters,max_iters+1);
    J_hist = ddp_func_output.J_hist;
    f_hist = ddp_func_output.f_hist;

    conv_plot = figure
    hold on
    addToolbarExplorationButtons(gcf)
    yyaxis left
    DDP_f_plot = plot(iteration_data,f_hist,'o-','DisplayName','$$\|\psi\|$$');
    set(gca,'yscale','log')
    yyaxis right
    DDP_J_plot = plot(iteration_data,J_hist,'o-','DisplayName','J');
    set(gca,'yscale','linear')
    hold off
    title('Convergence Data')
    xlabel('Iteration Number')
    legend()
    grid on
    
end