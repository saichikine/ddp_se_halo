function traj = initialize(traj)

    nx = traj.nx;
    nu = traj.nu;
    nw = traj.nw;
    nl = traj.nl;
    
    %traj.lambda = zeros(nl,1);
    
    Psi = traj.compute_constraintvec(traj);
    
    traj.stage{end}.ER = 0;
    traj.stage{end}.JX_star = [traj.lambda + 2*traj.penalty_sigma*Psi; -1; zeros(3,1)];
    traj.stage{end}.Jl_star = Psi;
    traj.stage{end}.JXX_star = zeros(nx+nu+nw, nx+nu+nw);
    traj.stage{end}.JXX_star(1:nl,1:nl) = 2*traj.penalty_sigma*eye(nl);
    traj.stage{end}.Jll_star = zeros(nl,nl);
    traj.stage{end}.JXl_star = [eye(nl); zeros(nx+nu+nw-nl,nl)];
    
%     traj.J_nom = traj.compute_J(traj);
%     traj.f_nom = traj.compute_f(traj);
%     traj.h_nom = traj.compute_h(traj);
    
end