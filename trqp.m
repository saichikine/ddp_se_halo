function [s_out, H_out, bool_TRQP_failure] = trqp(H, g, delta, M)
%#codegen

    max_iter = 100;
    counter = 0;

    H_in = H;
    g_in = g;

    k_easy = 1e-10;
    g = reshape(g,length(g),1);
    H_out = H*0;
    s_out = g*0;

    SinvT = chol(M,'lower');
    ST = inv(SinvT);
    S = ST.';
    g = ST*g;
    H = ST*H*S;

    bool_TRQP_failure = false;

    % TRQP algorithm 7.3.6
    % find model minimizer when eigensolution is cheap
    working = 1;

    % Check for blowup
    try
        [v,l] = eig(H,'vector');
    catch
        H_out = eye(size(H_in))*1e16;
        s_out = zeros(size(g));
        warning('H blew up in TRQP');
        bool_TRQP_failure = true;
        return
    end

    min_eig = min(l);
    max_eig = max(l);
    lambda_p = 0;

    if abs(max_eig) > 1/k_easy
        bool_TRQP_failure = true;
    %             H_out = 1e16*eye(size(H_in));
    %             s_out = zeros(size(g));
        return
    end

    if min_eig < 1e-15 % n.d
        lambda = min_eig;
        lambda_p = max(-lambda*1.01, 1e-15);
    end % zero eigenvalue

    H_tilde = H + lambda_p*eye(size(H));
    
    try
        L = chol(H_tilde,'lower');
    catch
        bool_TRQP_failure = true;
        return
    end
    s = -(L*L')\g;

    % Step 3
    if norm(s) <= delta
    %             if lambda_p == 0 || norm(s) == delta
        if lambda_p == 0 || (norm(s)-delta) < k_easy*delta
            working = 0;
        else
            [v,l] = eig(H_tilde,'vector');
            [min_eig, col] = min(l);
            u = v(:,col);
            a = u'*u;
            b = 2*s'*u;
            c = s'*s - delta^2;
            alpha1 = (-b + sqrt(b^2 - 4*a*c))/(2*a);
            alpha2 = (-b - sqrt(b^2 - 4*a*c))/(2*a);
            s1 = s + alpha1*u;
            s2 = s + alpha2*u;
            q1 = g'*s1 + s1'*H*s1/2;
            q2 = g'*s2 + s2'*H*s2/2;
            if q1 < q2
                alpha = alpha1;
            else
                alpha = alpha2;
            end
            s = s + u*alpha;
            working = 0;
        end
    end

    while working && counter < max_iter
        % Step 4
        if abs(norm(s) - delta) <= k_easy*delta
            break
        end

        % Step 5
        w = L\s;
        lambda_p = lambda_p + (norm(s)-delta)/delta*(norm(s)/norm(w))^2;

        % Step 6
        H_tilde = H + lambda_p*eye(size(H));
        L = chol(H_tilde,'lower');
        s = -(L*L')\g;

        counter = counter+1;
    end
    if counter >= max_iter
        if ~(abs(norm(s) - delta) <= 10*k_easy*delta)
            bool_TRQP_failure = true;
            warning("TRQP iteration limit exceeded; model minimzer not satisfactory.");
        end
    end

    H_out = SinvT*H_tilde*SinvT.';      
    s_out = S*s;
           
end
