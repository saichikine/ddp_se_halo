function X_dot = CR3BP(t, X, mu)

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

    % STM for CR3BP is 
    % A(t) = | 0 | I |
    %        |g' | 2O|
    % where 2O  = [0 1 0;-1 0 ;0 0 0]; and g' is partial deriv matrix

    A = Jacobian(x,y,z,xdot,ydot,zdot,mu);

    STM_dot = A*reshape(X(7:end), 6,[]);

    X_dot = [X(4:6); xdotdot; ydotdot; zdotdot; reshape(STM_dot,[],1)];

end