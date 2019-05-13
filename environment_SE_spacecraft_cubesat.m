% This file creates the environment and spacecraft and saves it
% NOTE: 
%
%
%
% SUN-EARTH SYSTEM
%
%
%
%

%% Let there be kites

earth = celestial_body;
earth.radius = 6378.13643; % [km]
earth.mu = 3.986e5; % [km^3/s^2]
 
moon = celestial_body;
moon.radius = 1738; % [km]
moon.mu = 4902.799; % [km^3/s^2]

sun = celestial_body;
sun.radius = 696000; % [km]
sun.mu = 1.327e11; % [km^3/s^2]

mu_ME = moon.mu/(moon.mu + earth.mu);
mu_SE = earth.mu/(earth.mu + sun.mu);

L_EM = 384400; % [km], Earth-Moon distance
L_SE = 149598023; % [km], Sun-Earth distance

L_points = lagrangePoints(mu_SE); 
x_L1 = L_points(1,1);
x_L2 = L_points(1,2);

G = 6.67408e-20;

%% Define spacecraft
g0 = 9.80665; % [m/s^2] g0 for Isp

% 6U cubesat (from ians paper)
cubesat = spacecraft;
cubesat.mass = 14; % [kg]
cubesat.max_thrust = 0.4; % [mN]
cubesat.Isp = 1250; % [s]
cubesat.Ve = cubesat.Isp*g0; % [m/s]

%%
% Normalization stuff (divide by these to get normalized versions)
LU = L_SE;
T_SU = 2*pi*sqrt(LU^3/(earth.mu+sun.mu));
DU = L_SE; % [km]
TU = 1/(2*pi/T_SU); % [s]
VU = DU/TU; % [km/s]
AU = DU/TU^2; % [km/s^2]
MU = cubesat.mass; % [kg]
FU = MU*DU/TU^2; % [kg*km/s^2] = [kN]
normalizers = struct('TU',TU,'VU',VU,'AU',AU,'FU',FU','MU',MU);

% Normalize quantities of interest
m_sc = cubesat.mass/MU;
exh_vel = cubesat.Ve/1000/VU; % convert to km/s, then to nondimensional velocities
max_thrust_mag = cubesat.max_thrust/1000/1000/FU; % convert to kN, then to nondimensional force units

%% Save workspace to .mat file

save('environment_SE_spacecraft_cubesat.mat')
fprintf('Environment and spacecraft variables saved to file.\n')