% Spacecraft Class

classdef spacecraft
    properties
        mass % [kg]
        max_thrust % [mN]
        Isp % [s] specific impulse
        Ve % [m/s] exhaust velocity
    end
    
%     methods
%         function spacecraft = set.Ve(spacecraft,Isp)
%             spacecraft.Ve = Isp*9.80665;
%         end
%     end
end