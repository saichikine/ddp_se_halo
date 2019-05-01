function [s_out, H_out] = trqp(H, g, delta, method)
% Jonathan Aziz
% trust region subproblem algorithms

H_in = H;
g_in = g;

k_easy = 1e-10;
g = reshape(g,length(g),1);
H_out = H*0;
s_out = g*0;
if norm(H) > 1e9 || norm(g) > 1e9
    H_out = eye(size(H))*1e16;
    return
end
switch method % because skateboarding
    case 'Newton'
        
        % TRQP algorithm 7.3.6
        % find model minimizer when eigensolution is cheap
        working = 1;
        
        % Step 0 Is H p.d.?
        [v,l] = eig(H,'vector');
        [min_eig, col] = min(l);
        lambda_p = 0;

        if min_eig < 0 % n.d
            lambda = min_eig;
            lambda_p = max(-lambda*1.01, 1e-15);
        end % zero eigenvalue
                 
        H_tilde = H + lambda_p*eye(size(H));
                
        % remove singular directions
        idxs = find(abs(l)>1e-19*max(l)); % this is incorrect but im getting by for now
%         idxs = find(abs(l)>1e-9);
        H_tilde = H_tilde(idxs,idxs);
        H = H(idxs,idxs);
        g = g(idxs);
        L = chol(H_tilde,'lower');
        s = -(L*L')\g;
        
        if isempty(idxs)
            H_out = 1e16*eye(size(H_in)); %s_out already 0
            return
        end
            
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
                    s = s1;
                else
                    s = s2;
                end
                working = 0;
            end
        end
        
        while working
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
        end
        H_out(idxs,idxs) = H_tilde;      
        s_out(idxs) = s;
        
        % another check on singular directions
%         idxs = find(abs(diag(H_out))<1e-19);
%         H_out(idxs,idxs) = 1e16;
%         s_out(idxs) = 0;
    %%
    case 'SteihaugToint'
        %% Steihaug-Toint truncated conjugate gradient method
        %% initialization
        s = g*0;
        v = g; % M\g;
        p = -v;
        working = 1;
        shift = 1;
        H_tilde = H;
        while working
            % iterate
            kappa = p'*H*p;
            if kappa <= 0 %nonconvex model unbounded from below
                a = p'*p;
                b = 2*s'*p;
                c = s'*s - delta^2;
                sigma = (-b + sqrt(b^2 - 4*a*c))/(2*a);
                s = s + sigma*p;
                break;
            end
            
            alpha = g'*v/kappa;
            
            if norm(s+alpha*p) >= delta % exterior solution
                a = p'*p;
                b = 2*s'*p;
                c = s'*s - delta^2;
                sigma = (-b + sqrt(b^2 - 4*a*c))/(2*a);
                s = s + sigma*p;
                break;
            end
            
            g_last = g;
            v_last = v;
            s = s + alpha*p;
            g = g + alpha*H*p;
            v = g; % M\g
            Beta = (g'*v) / (g_last'*v_last);
            p = -v + Beta*p;
%             if norm(s) <= delta
%                 shift = 0;
%                 H_tilde = H;
%                 break;
%             end
            
        end % working
%         if shift
%             lambdas = 0*g;
%             for k = 1:length(size(H))
%                 lambdas(k) = 1/s(k)*(-g(k)-H(k,:)*s);
%             end
%             lambda = min(lambdas);
%             H_tilde = H + lambda*eye(size(H));
%         end
        
        %%
    case 'Lanczos'
        s = g*0;
        v = g; %M\g;
        gamma = sqrt(v'*g);
        p = -v;
        interior = 1;
        working = 1;
        while working
            alpha = (g'*v) / (p'*H*p);
            % obtain T (5.2.21)
            if interior && (alpha < 0 || norm(s+alpha*p) >= delta)
                interior = 0;
            elseif interior
                s = s + alpha*p;
            else
                % obtain h (7.5.58)
            end % if interior
            g_last = g;
            v_last = v;
            g = g + alpha*H*p;
            v = g; %M\g
            
            if interior
            end % if interior
            
            Beta = (g'*v)/(g_last'*v_last);
            p = -v + Beta*p;
            
        end % working
        
end
