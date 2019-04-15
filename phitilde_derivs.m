function phitilde_derivs = phitilde_derivs(traj)
    % Returns partials of augmented lagrangian phitilde
    
    %Psi = traj.compute_constraintvec(traj);
    % Zeros since augmented lagrangian is only function of stuff at end,
    % and this is wrt to initial state
    augphixp = 0;
    augphiwp = 0;
    augphixpxp = 0;
    augphiwpwp = 0;
    augphixpwp = 0;
    
    phitilde_derivs = struct('augphixp',augphixp,'augphiwp',augphiwp,'augphixpxp',augphixpxp,'augphiwpwp',augphiwpwp,'augphixpwp',augphixpwp);
    
end
    
    
    