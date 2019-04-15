function Psi = constraint_vec(traj,target_posvel)
    Psi = traj.stage{end}.state(1:6) - target_posvel;
end