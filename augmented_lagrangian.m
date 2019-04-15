function augmented_lagrangian = augmented_lagrangian(traj)
    Psi = traj.compute_constraintvec(traj);
    augmented_lagrangian = traj.terminal_cost(traj) + traj.lambda'*Psi + traj.penalty_sigma*norm(Psi)^2;
end