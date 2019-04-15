function bool_pos_def = is_pos_def(A)
    % Checks if matrix is positive definite
    % Returns logical true if positive definite, logical false if not
    
    [~,p] = chol(A);
    
    bool_pos_def = false;
    if ~p
        bool_pos_def = true;
    end
end