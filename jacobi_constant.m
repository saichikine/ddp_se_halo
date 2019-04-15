function C = jacobi_constant(X, mu)

    r1 = sqrt((X(1)+mu)^2 + X(2)^2 + X(3)^2);
    r2 = sqrt((X(1)-1+mu)^2 + X(2)^2 + X(3)^2);
    
    C = X(1)^2 + X(2)^2 + 2*(1-mu)/r1 + 2*mu/r2 - (X(4)^2 + X(5)^2 + X(6)^2);
end