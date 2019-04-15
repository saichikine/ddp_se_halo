function terminal_cost = terminal_cost(traj)

    terminal_cost = -traj.stage{end}.state(7); % maximize final mass
end