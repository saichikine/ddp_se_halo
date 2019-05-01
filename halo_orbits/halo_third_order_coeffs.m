function coefficients = halo_third_order_coeffs(c_n)

    % Compute annoying long list of third-order coefficients for halo
    % orbits
    
    %% Unpack
    c1 = c_n(1);
    c2 = c_n(2);
    c3 = c_n(3);
    c4 = c_n(4);
    
    %% Freqs
    lambda = sqrt((c2 + sqrt(9*c2^2 - 8*c2)))/2;
    wp = sqrt((2 - c2 + sqrt(9*c2^2 - 8*c2)))/2;
    wv = sqrt(c2);
    
    kappa = (wp^2 + 1 + 2*c2)/(2*wp);
    
    %% Coeffs
    a_mat = zeros(3,4);
    b_mat = zeros(3,2);
    d_mat = zeros(3,2);
    d_vec = zeros(2,1);
    s_vec = zeros(2,1);
    l_vec = zeros(2,1);
    
    d1 = 3*lambda^2/kappa*(kappa*(6*lambda^2 - 1) - 2*lambda);
    d2 = 8*lambda^2/kappa*(kappa*(11*lambda^2 - 1) - 2*lambda);

    a21 = 3*c3*(kappa^2 - 2)/(4*(1+2*c2));
    a22 = 3*c3/(4*(1+2*c2));
    a23 = -3*c3*lambda/(4*kappa*d1)*(3*kappa^3*lambda - 6*kappa*(kappa - lambda) + 4);
    a24 = -3*c3*lambda/(4*kappa*d1)*(2 + 3*kappa*lambda);

    b21 = -3*c3*lambda/(2*d1)*(3*kappa*lambda - 4);
    b22 = -3*c3*lambda/d1;

    d21 = -c3/(2*lambda^2);

    a31 = -9*lambda/(4*d2)*(4*c3*(kappa*a23 - b21) + kappa*c4*(4 + kappa^2)) + ...
        (9*lambda^2 + 1 - c2)/(2*d2)*(3*c3*(2*a23 - kappa*b21) + c4*(2 + 3*kappa^2));
    a32 = -9*lambda/(4*d2)*(4*c3*(3*kappa*a24 - b22) + kappa*c4) - ...
        (-3*(9*lambda^2 + 1 - c2))/(2*d2)*(c3*(kappa*b22 + d21 - 2*a24) - c4);

    b31 = 3/(8*d2)*8*lambda*(3*c3*(kappa*b21 - 2*a23) - c4*(2 + 3*kappa^2)) + ...
        3/(8*d2)*(9*lambda^2 + 1 + 2*c2)*(4*c3*(kappa*a23 - b21) + kappa*c4*(4 + kappa^2));
    b32 = 9*lambda/d2*(c3*(kappa*b22 + d21 - 2*a24) - c4) + ...
        3*(9*lambda^2 + 1 + 2*c2)/(8*d2)*(4*c3*(kappa*a24 - b22) + kappa*c4);

    d31 = 3/(64*lambda^2)*(4*c3*a24 + c4);
    d32 = 3/(64*lambda^2)*(4*c3*(a23 - d21) + c4*(4 + kappa^2));

    s1 = (2*lambda*(lambda*(1+kappa^2) - 2*kappa))^(-1)*(3/2*c3*(2*a21*(kappa^2 - 2) - a23*(kappa^2 + 2) - 2*kappa*b21) - 3/8*c4*(3*kappa^4 - 8*kappa^2 + 8));
    s2 = (2*lambda*(lambda*(1+kappa^2) - 2*kappa))^(-1)*(3/2*c3*(2*a22*(kappa^2 - 2) - a24*(kappa^2 + 2) + 2*kappa*b22 + 5*d21) + 3/8*c4*(12 - kappa^2));

    l1 = -3/2*c3*(2*a21 + a23 + 5*d21) - 3/8*c4*(12 - kappa^2) + 2*lambda^2*s1;
    l2 = 3/2*c3*(a24 - 2*a22) + 9/8*c4 + 2*lambda^2*s2;
    
    %% Assign
    a_mat(2,1) = a21;
    a_mat(2,2) = a22;
    a_mat(2,3) = a23;
    a_mat(2,4) = a24;
    a_mat(3,1) = a31;
    a_mat(3,2) = a32;
    
    b_mat(2,1) = b21;
    b_mat(2,2) = b22;
    b_mat(3,1) = b31;
    b_mat(3,2) = b32;
    
    d_mat(2,1) = d21;
    d_mat(3,1) = d31;
    d_mat(3,2) = d32;
    
    s_vec(1) = s1;
    s_vec(2) = s2;
    
    l_vec(1) = l1;
    l_vec(2) = l2;
    
    d_vec(1) = d1;
    d_vec(2) = d2;
    
    coefficients = struct('a',a_mat,'b',b_mat,'d',d_mat,'s12',s_vec,'l12',l_vec,'d12',d_vec);
    
end
    