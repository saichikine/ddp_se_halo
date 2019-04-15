function h = compute_h(traj)

    h = 0;
    
    for k = 1:traj.num_stages
        h = h + traj.stage_cost(traj.stage{k}.state, traj.stage{k}.u, traj.w);
    end
    
    h = h + traj.terminal_cost(traj);
    
end