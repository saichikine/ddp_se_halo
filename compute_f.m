function f = compute_f(traj)

    Psi = traj.compute_constraintvec(traj);
    f = norm(Psi);
    
end
    
    