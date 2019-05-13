function X_dot = CR3BP_fast(t, X, mu)

    % Reshape to column vector
    X = reshape(X,length(X),[]);

    % Positions
    x = X(1);
    y = X(2);
    z = X(3);

    % Velocities
    xdot = X(4);
    ydot = X(5);
    zdot = X(6);

    % Distances to primaries
    r1 = sqrt((x+mu)^2 + y^2 + z^2); 
    r2 = sqrt((x-1+mu)^2 + y^2 + z^2); 

    % Accelerations 
    xdotdot = 2*ydot + x -(1-mu)*((x+mu)/(r1^3)) - mu*(x-1+mu)/(r2^3);
    ydotdot = -2*xdot + y - (1-mu)*(y/(r1^3)) - mu*(y)/(r2^3);
    zdotdot = -(1-mu)*(z)/(r1^3) - mu*(z)/(r2^3);

    X_dot = [X(4:6); xdotdot; ydotdot; zdotdot];

end