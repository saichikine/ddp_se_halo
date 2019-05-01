function freqs = halo_third_order_freqs(c_n)

    % Gives omega_p and omega_v for third-order Halo orbit approximation in
    % CR3BP
    
    c2 = c_n(2);
    
    wp = sqrt((2 - c2 + sqrt(9*c2^2 - 8*c2))/2);
    wv = sqrt(c2);
    
    freqs = struct('wp',wp,'wv',wv);
    
end