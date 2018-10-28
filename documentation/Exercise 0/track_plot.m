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
median_x(end+1)=median_x(1);
median_y(end+1)=median_y(1);
load('pos_car_simulation.mat')
place=2878;%2884
x_pos_car_reduced=x_pos_car.Data(1:place);
y_pos_car_reduced=y_pos_car.Data(1:place);
figure(1)
axis([-150 250 -400 500]);
grid on
hold on

plot(x_in,y_in,'k-');
plot(x_out,y_out,'k-');
plot(median_x, median_y,'r--');

how_often_more=floor(length(x_pos_car.Data(1:2984))/length(median_x));
for i=1:length(median_x)
    pos=i*how_often_more;
    x_pos_car_clean(i)=x_pos_car.Data(pos);
    y_pos_car_clean(i)=y_pos_car.Data(pos);
end

%error
x_pos_interpolated=interp1(linspace(1,length(x_pos_car_reduced),length(median_x)),median_x,1:length(x_pos_car_reduced)+1,'spline');
y_pos_interpolated=interp1(linspace(1,length(y_pos_car_reduced),length(median_x)),median_y,1:length(y_pos_car_reduced)+1,'spline');
% u_neu=interp1(t_alt,u_alt,t_neu,'spline' )
x_pos_interpolated=x_pos_interpolated(1:end-1);
y_pos_interpolated=y_pos_interpolated(1:end-1);
%plot(x_pos_interpolated, y_pos_interpolated,'r--');
plot(-y_pos_car_clean,x_pos_car_clean,'bx');


%%

x_car=-y_pos_car_reduced;
x_track=x_pos_interpolated';
y_car=x_pos_car_reduced;
y_track=y_pos_interpolated';

%%

for i=1:length(x_track)
    %x_mean(i)=norm(x_track-x_car);
    %y_mean(i)=norm(y_track-y_car);
    dist_2norm(i)=norm(sqrt((x_track-x_car).*(x_track-x_car)+(y_track-y_car).*(y_track-y_car)));
    x_track=[x_track(2:end);x_track(1)];
    y_track=[y_track(2:end);y_track(1)];
end
[a,b]=min(dist_2norm);
%[a,b2]=min(y_mean)
%b=1456
%for i=1:b
%    x_car=[x_car(end);x_car(1:end-1)];
%    y_car=[y_car(end);y_car(1:end-1)];
%end
for i=1:b
    x_track=[x_track(2:end);x_track(1)];
    y_track=[y_track(2:end);y_track(1);];
end
%%
%hold on
%plot(x_pos_interpolated,y_pos_interpolated)
%plot(-y_pos_car.Data,x_pos_car.Data)
%close
figure(2)
hold on
%plot(x_car,y_car)
%plot(x_track,y_track)
dist=sqrt((x_track-x_car).*(x_track-x_car)+(y_track-y_car).*(y_track-y_car));
plot(x_pos_car.Time(1:place),dist);
xlabel('time')
ylabel('distance to track')
%plot(y_car)
%plot(y_track)

