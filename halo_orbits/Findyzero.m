function [value,isterminal,direction] = Findyzero(t,X)

% Events ? The function is of the form
% 
% [value,isterminal,direction] = events(t,y)
% value, isterminal, and direction are vectors for which the ith element corresponds to the ith event function:
% 
% value(i) is the value of the ith event function.
% isterminal(i) = 1 if the integration is to terminate at a zero of this event function, otherwise, 0.
% direction(i) = 0 if all zeros are to be located (the default), +1 if only zeros where the event function is increasing, and -1 if only zeros where the event function is decreasing.
% If you specify an events function and events are detected, the solver returns three additional outputs:
% 
% A column vector of times at which events occur
% Solution values corresponding to these times
% Indices into the vector returned by the events function. The values indicate which event the solver detected.
% If you call the solver as
% 
% [T,Y,TE,YE,IE] = solver(odefun,tspan,y0,options)
% the solver returns these outputs as TE, YE, and IE respectively. If you call the solver as
% 
% sol = solver(odefun,tspan,y0,options)
% the solver returns these outputs as sol.xe, sol.ye, and sol.ie, respectively.
% 
% For examples that use an event function, see Event Location and Advanced Event Location in the MATLAB Mathematics documentation.

   
    value = X(2);      % X(2) is y, so this event is flagged when y=0
    isterminal = 1;    % this means event is triggered when value=y=0
    direction = 0;     % all zeros, not just increasing or decreasing
end