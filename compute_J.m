function J = compute_J(traj)

    % Computes cost for entire trajectory

    J = 0;
    for k = 1:traj.num_stages
        J = J + traj.stage_cost(traj.stage{k}.state,traj.stage{k}.u,traj.w);
    end
    J = J + traj.augmented_lagrangian(traj);
    
end
        