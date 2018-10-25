%% prepare the data
% load the track data and sort for x- and y-values
load('track.mat');
x = data(1:3:end);
y = data(2:3:end);

% outer track limit
x_out = x(1:2:end);
y_out = y(1:2:end);
x_out(1:3:end) = [];
y_out(1:3:end) = [];

% inner track limit
x_in = x(2:2:end);
y_in = y(2:2:end);
x_in(1:3:end) = [];
y_in(1:3:end) = [];

% calculate the center line
median_x = (x_in + x_out)/2;
median_y = (y_in + y_out)/2;

%% plot
figure
axis([-150 250 -400 500]);
grid on
hold on

plot(x_in,y_in,'k-');
plot(x_out,y_out,'k-');
plot(median_x, median_y,'r--');
plot(0,0,'bx');