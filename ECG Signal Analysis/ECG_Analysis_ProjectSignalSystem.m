%% Uploading File

%Upload ECG-File For Processing 
[file,path] = uigetfile('*.mat');
load(strcat(path,file));

if isequal(file,0)
   disp('User selected Cancel');
else
   disp(['User selected ', fullfile(path,file)]);
end
%% Plot The Orignal Signal


signal = [];
x_axis = 1:1:length(val);

for i=1 : length(val)
    
    signal(i)= val(i);
    
end

% figure;
subplot(2,2,1);
plot(x_axis,signal);
title("Graph of an ECG Signal");
xlabel("Samples/Frequency"); ylabel("Voltages");

%% Filtring the Signal (Low Pass Filter ) Blocking the HIgh frq. components

%Adding the Filter for Removing Hight Frequncy Component
%We need Low Pas Filter
sample_frq = 360 ;           %Samples Per Sec Given in Data Description
order_of_filter = 10; 
cut_of = 50;                 %any thing above 50Hz wll be removed

% [b,a] = butter(n,Wn,ftype) "Filter " ftype means low or high filter
% selction , n = order , Wn = cut_of/fs/2

[b,a] = butter(order_of_filter,cut_of/(sample_frq/2),'low');

%Find the Frequency response for filter 
[sig, cut_of] = freqz(b,a);             %sig = freq response of filter
% plot((1:1:512),abs(sig), 'r--');

% figure;
subplot(2,2,2);
plot((cut_of/pi*sample_frq/2),abs(sig), 'r--' );
title(" Low Pass Filter ");
xlabel(" Samples/Frequency "); ylabel(" Amplitude ");

%Filtering The Signal 
out_put_LOwPass = filter(b,a,signal);
% figure;

subplot(2,2,3);
plot(x_axis(50:3600),(out_put_LOwPass(50:3600)),'b');
title(" Filtered Signal ");
xlabel(" Samples/Frequency "); ylabel(" Voltages ");
%% High Pass Filter () Not Used But can be used For More Clear Signal 


%{
%Adding the Filter for Removing Low Frequncy Component We need HIgh Pas
%Filter
sample_frq = 360 ;           %Samples Per Sec Given in Data Description
order_of_filter = 10; 
cut_of = 4;                 %any thing below the 15Hz will be removed

% [b,a] = butter(n,Wn,ftype) "Filter " ftype means low or high filter
% selction , n = order , Wn = cut_of/fs/2

[b,a] = butter(order_of_filter,cut_of/(sample_frq/2),'low');

%Find the Frequency response for filter
[sig, cut_of] = freqz(b,a);
% plot((1:1:512),abs(sig), 'r--');
figure;
plot((cut_of/pi*sample_frq/2),abs(sig), 'r--' );

%Filtering The Signal
out_put_LOwPass = filter(b,a,signal);
figure;
plot(x_axis(50:3600),(out_put_LOwPass(50:3600)),'b');
%}
%% Identifying the R-Waves and Counting 

%Now Our signal is somwhow good to go for futher processing
%Now we have to identify R-Wave (Coz that help in calculate bpm)
%R-wave is always high , so we can simply identify using peaks

%pks = findpeaks(data)  | [pks,locs] = findpeaks(data)
% [pks,locs] = findpeaks(out_put_LOwPass);
% 
% plot(locs, pks); hold on
% plot(out_put_LOwPass);
y = (out_put_LOwPass);
x = (x_axis);

[Rvalues,locs_Rwave] = findpeaks(y,'MinPeakHeight',1000, 'MinPeakDistance',200);
%You can change values of 'MinPeakHeight' & 'MinPeakDistance' based on your
%data

% figure;
subplot(2,2,4);
plot(x,y);hold on 
plot(locs_Rwave,y(locs_Rwave),'rv')

% grid on
legend('ECG Signal','R waves')
xlabel('Samples')
ylabel('Voltage(mV)')
title('R wave in Filtered ECG Signal')

%% Calculate BPM 

% Calculation Of bpm Finally by the Peaks Results
% We will Simply Add up the Rwaves And Divide on time

total_samples = length(val);     %NO. of samples of ECG Signal 
time = 10 ;                      %Time Duration 
no_of_Rwave = length(locs_Rwave);        %R waves in given ECG Sample 

bpm = 6*no_of_Rwave;

disp('The bpm (beats per minute ) Would be '); display(bpm);





