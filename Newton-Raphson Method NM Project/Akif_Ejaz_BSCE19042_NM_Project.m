%Implement Newton-Raphson method using MATLAB to compute the drag coefficient c needed
%for a parachutist of mass m = First Two Digits of Your Registration Number ÷ 2 kg to have a
%velocity of Second Last Digit of Your Registration Number + 40 m/s after free falling for time t =
%Last Digit of your Registration Number + 5 secs. Note: The acceleration due to gravity is 9.81
%m/s 2

% roll_no = 19042; 

m = 19/2;         %m = First Two Digits of Your Registration Number ÷ 2
v = 4 + 40;       %velocity of Second Last Digit of Your Registration Number + 40 m/s
t = 2 + 5;        %time t = Last Digit of your Registration Number + 5 secs
gravity = 9.8;

%Setting x as symbolic variable that representing c 
syms x;

% Input Section
%v(t) = g*m/c *(1- exp(-(c/m)*t) );          % orignal equation of v
y = gravity*m/x *( 1 - exp(-(x/m)*t) ) - v;  % equation for estimating c


a = 3;        %a = input('Enter initial guess: ');
e = 0.0001;  %e = input('Tolerable error: ');
N = 100;      %N = input('Enter maximum number of steps: ');
funct = [];
error = [];

% Initializing step counter
step = 1;

% Finding derivate of given function
g = diff(y,x);

% Finding Functional Value
fa = eval(subs(y,x,a));
while abs(fa)> e
    
    fa = eval(subs(y,x,a));
    ga = eval(subs(g,x,a));
    if ga == 0
        disp('ERROR: Division by zero.');
        break;
    end
    b = a - fa/ga;
    fprintf('step num=%d\t\tApproximated value=%f\t\tFunction Value When f(a)=%f\n',step,a,fa);
    a = b;
    if step>N
        disp('ERROR: Not convergent ! TRY CHANGE THE INITIAL GUESS a ');
        break;
    end

funct(step) = a;                    % saving the value of step in a vector
error(step) =((1.31-a)/1.31)*100;   % vector for error at every iteration
step = step + 1;
end

fprintf('Approximated Value for f(c) is %f\n', a);

% true value plot
x_axis = 0:1:step-2;
tem = 1.31;
const = @(x_axis)(tem).*x_axis.^(0);
plot(x_axis, const(x_axis),'--','linewidth',2); hold on;

% calculated numerically
x_axis = 0:1:step-2;   % axis for plot
plot(x_axis,funct,'linewidth',2);

xlabel("Step n"); ylabel("Approx. value of func");
title("Plot of True Value & Approximated Values Over Steps");
legend('true value','approx value');

%%  Error Plot
figure;
x_axis = 0:1:step-2;   % axis for plot
plot(x_axis,error,'linewidth',2);
title("Error from NR Method for f(c) ");
xlabel("Step n"); ylabel("Error");

