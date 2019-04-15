function L_derivs = L_derivs(traj,k)

    nx = traj.nx;
    nu = traj.nu;
    nw = traj.nw;
    
    % All zeros since no local cost
    LX = zeros(nx+nu+nw,1);
    LXX = zeros(nx+nu+nw,nx+nu+nw);
    
    L_derivs = struct('LX',LX,'LXX',LXX);
    
end

    