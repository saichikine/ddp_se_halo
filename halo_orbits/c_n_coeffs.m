function c_n = c_n_coeffs(mu, gamma, L_point_string, varargin)
    % Computes c_n coefficients for L1 or L2
    
    %% Input checking
    if nargin == 3
        n = 4;
    elseif nargin == 4
        n = varargin;
    else
        error('Check number of arguments.')
    end
    
    if ~isstring(L_point_string)
        error('Third argument must be a string.')
    end
    
    if (~strcmp(L_point_string,'L1') && ~strcmp(L_point_string,'L2'))
        error('Third argument must be either "L1" or "L2".')
    end
    
    %% Actual stuff
    
    c_n = NaN(1,4);
    
    for i = 1:n
        if strcmpi(L_point_string,"L1")
            c_n(i) = 1/gamma^3*((1)^i*mu + (-1)^i*((1-mu)*gamma^(i+1))/((1 - gamma)^(i+1)));
        elseif strcmpi(L_point_string,"L2")
            c_n(i) = 1/gamma^3*((-1)^i*mu + (-1)^i*((1-mu)*gamma^(i+1))/((1 + gamma)^(i+1)));
        else
            error('How did this happen? The programmer messed up.')
        end
    end
    
end
        