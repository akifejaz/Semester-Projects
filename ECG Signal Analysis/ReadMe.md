# Report of ECG Analysis Project
### Abstract:

_______ Electrocardiogram (ECG) represents the electrical activity of the human heart. It is a graph of voltage versus time of the electrical activity of the heart using electrodes placed on the skin. ECG signal is composed of 5 waves - P, Q, R, S and T, e.g., Fig 1.  In this project we are going to detects human heart rate in beats per minute (bpm) using only R wave. As the heart rate is the very important human health status information. The heart rate is used in many applications like in medical diagnosis, spots application for the measurement of stress and for fitness test purposes etc. the heart beat rate can be figured out using ECG signal. There are various ways to compute heart beat rate from ECG signal. There are many algorithms presents for heart beat detection but we are going to use Autocorrelation Method and Threshold method for computing the heat rate.

![image](https://user-images.githubusercontent.com/81078376/131811929-be96e68f-64b5-47ff-a2a6-151c36a207a1.png)

### Methodology:

From the sample signal wave (in Fig 1) we can see there are 5 different spots we can use to detect wave. If somehow, we detect one we can take reference of that and spot all the other points

In ECG signal. One nice approach is to focus on the R-Wave. Most of the time we try to find R-Waves in signal and then count all that, its supper simple. There are many techniques we can locate R-Waves, like Correlation, Auto-Correlation and threshold settings of signals. One of the simplest methods to do so, is threshold setting, In this method we set a threshold value and loop through the signal every time signal value reaches our threshold or greater we encounter that a R-Wave and at last we count and sum up all which gives total number of R-Wave in Signal, Explained in Fig 2 the dotted line shows the Threshold value.

The second method is said correlation and if we take correlation of signal with itself (both arguments are same signal) it said as Auto-Correlation.  In this method we take the one period signal from the ECG signal and do Correlation of that with the original signal. The output after Auto-Correlation is something really interesting. We can understand Correlation in simple words as, Correlation means association - more precisely it is a measure of the extent to which two variables are related. There are three possible results of a correlational study: a Positive Correlation, a Negative Correlation, and No Correlation. A positive Correlation means the increase of one signal at certain points (on x-axis_) and other signal also increase at certain points the resultant will be increased or let say amplitude add up at that points (on x-axis_) and the negative correlation is then vise versa. 

![image](https://user-images.githubusercontent.com/81078376/131812117-0b017107-5933-4e48-af85-fab321f5cb7a.png)
![image](https://user-images.githubusercontent.com/81078376/131812134-d2bbef4b-9871-471f-ba39-916a5fd5a963.png)

You can see in the Fig 3 and Fig 4, I have performed simple convolution over ECG signal it is basically the easiest way to find number of R-Waves, like you just need to count how many times convolution happens or in simple words how many times small part of signal matches over the original signal. 

After successfully, finding the number of R-Wave now comes some calculations part in which we have to calculate the bpm using the details of Signal Duration, Frequency and Number of R-Waves. We can easily generate general formula for it, Let’s understand this by sample data, as If we have 10 seconds ECG signal and there are 12 R-Waves in 10 seconds, then the bpm will be simply the 6*12 = 72 bpm. In general form it can be represent as,

![image](https://user-images.githubusercontent.com/81078376/131812254-dbdd3e63-4f3c-4913-a00e-1a01180ae500.png)

RWaves = Waves we get after convolution or threshold method
Time = Is the duration of ECG signal in seconds

### Data: 

The data set we used in this project is taken from online resources with format “.mat” MATLAB files, having original ownership associated with “http://www.physionet.org”. The ECG signals were from 45 patients: 19 female (age: 23-89) and 26 male (age: 32-89). The ECG signals contained 17 classes: Normal sinus Rhythm, Pacemaker Rhythm, and 15 types of cardiac dysfunctions (for each of which at least 10 signal fragments were collected). All ECG signals were recorded at a sampling frequency of 360 [Hz] and a gain of 200 [adu / mV]. For the analysis, 1000, 10-second (3600 samples) fragments of the ECG signal (not overlapping) were randomly selected

### Results: 

The final goal was to find bpm (beats per minute) and it is in somehow integer value. The same formula is used to calculate bpm after R-Wave as given in “Methodology” section. We have tested some signals with both the methods Threshold & Correlation and the results are similar but Correlation Method overall gives better and accurate results then Threshold method. 

