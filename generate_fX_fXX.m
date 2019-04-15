% Finds expressions for dynamics jacobian fX and dynamics tensor fXX and
% writes to file
% Includes mass dynamics

%%
clear; close all; clc;

%% Setup

nx = 7;
nu = 3;
nX = nx + nu;
syms x y z xdot ydot zdot xddot yddot zddot m ux uy uz mu r1 r2 Tmax c

% ux, uy, uz are thrust vector components, not accel vector components

% Distances from particle/spacecraft to primaries
r1 = sqrt((x+mu)^2 + y^2 + z^2); 
r2 = sqrt((x-1+mu)^2 + y^2 + z^2);

% CR3BP Dynamics
xddot = 2*ydot + x -(1-mu)*((x+mu)/(r1^3)) - mu*(x-1+mu)/(r2^3) + (Tmax*ux/m);
yddot = -2*xdot + y - (1-mu)*(y/(r1^3)) - mu*(y)/(r2^3) + (Tmax*uy/m);
zddot = -(1-mu)*((z)/(r1^3)) - mu*(z)/(r2^3) + (Tmax*uz/m);
state = [x,y,z,xdot,ydot,zdot,m,ux,uy,uz];
u_epsilon = [1e-8; 1e-10; 1e-12; 1e-16];
mdot = -Tmax*sqrt(ux^2 + uy^2 + uz^2 + u_epsilon(1))/c;

f = [xdot ydot zdot xddot yddot zddot mdot 0 0 0];

%% Compute fX and write elements to file
fX_sym = jacobian(f, state); % equivalent to looping through i and j and doing diff(f(i),state(j)) (verified)

fidfX = fopen('fX.m','w');
fprintf(fidfX,'function fX = fX(X, c, mu, Tmax)\n');
fprintf(fidfX,'\tx = X(1);\n \ty = X(2);\n \tz = X(3);\n \txdot = X(4);\n \tydot = X(5);\n \tzdot = X(6);\n \tm = X(7);\n \tux = X(8);\n \tuy = X(9);\n \tuz = X(10);\n\n');
for i = 1:nX
   for j = 1:nX
      fprintf(fidfX,'\tfX(%i,%i) = %s;\n',i,j,char(fX_sym(i,j)));
   end
   fprintf(fidfX,'\n');
end
fprintf(fidfX,'end');
fclose(fidfX);

%% Compute fXX tensor

% for i = 1:nX
%     for j = 1:nX
%         fXX(i,j,:) = gradient(fX(i,j), state);
%     end
% end

fXX_sym = sym(NaN([nX nX nX]));
for i = 1:nX
    fXX_sym(i,:,:) = hessian(f(i),state);
%     for j = 1:nX
%         for k = 1:nX
%             fXX_sym(i,j,k) = diff(diff(f(i),state(j)),state(k)); %
%             checked, these approaches are equivalent
%         end
%     end
end
%% Write elements of fXX to file

fidfXX = fopen('fXX.m','w');
fprintf(fidfXX,'function fXX = fXX(X, c, mu, Tmax)\n');
fprintf(fidfX,'\tx = X(1);\n \ty = X(2);\n \tz = X(3);\n \txdot = X(4);\n \tydot = X(5);\n \tzdot = X(6);\n \tm = X(7);\n \tux = X(8);\n \tuy = X(9);\n \tuz = X(10);\n\n');
for i = 1:nX
    for j = 1:nX
        for k = 1:nX
            fprintf(fidfXX,'\tfXX(%i,%i,%i) = %s;\n',i,j,k,char(fXX_sym(i,j,k)));
        end
        fprintf(fidfXX,'\n');
    end
    fprintf(fidfXX,'\n\n');
end
% fprintf(fidfXX,'\tfXX = tensor(fXX); %% Convert to tensor\n');
fprintf(fidfXX,'end');
fclose(fidfXX);

fprintf('Done writing files. Have a good day :)\n');