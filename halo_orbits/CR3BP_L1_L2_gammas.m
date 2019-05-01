function gamma = CR3BP_L1_L2_gammas(mu)
    % Computes gamma_1, gamma_2 for CR3BP
    
    L_points = lagrangePoints(mu);
    
    gamma_1 = abs((1-mu) - L_points(1,1));
    gamma_2 = abs((1-mu) - L_points(1,2));
    
    gamma = struct('one',gamma_1,'two',gamma_2);
    
end