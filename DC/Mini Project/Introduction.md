# Introduction

&nbsp;&nbsp;&nbsp;&nbsp;Digital to Analog conversion is a process of transforming a digital signal into its corresponding analog signal. Digital signals having discrete amplitudes at discrete time instants are converted into a continuous analog signal both in case of amplitude and time in this process. In analog transmission, the sending device produces a high-frequency signal that acts as a base for the information signal called the carrier signal or carrier frequency. The receiving device is tuned to the frequency of the carrier signal that it expects from the sender. Digital information then changes the carrier signal by modifying one or more of its characteristics (amplitude, frequency, or phase). This kind of modification is called modulation (shift keying).

## Phase Shift Keying

&nbsp;&nbsp;&nbsp;&nbsp;In phase shift keying (PSK), the phase of a carrier is changed according to the modulating waveform which is a digital signal. In BPSK, the transmitted signal is a sinusoid of fixed amplitude. It has one fixed phase when the data is at one level and when the data is at the other level, phase is different by 180 degree. A Binary Phase Shift Keying (BPSK) signal can be defined as

![equation 1](Images/1.gif) &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;, where 0 &le; t &le; T

where **b(t) = +1 or -1**,  **fc**  is the carrier frequency, and _T_ is the bit duration. The signal has a power **P = A<sup>2</sup>/2**, so that **A = <span>&radic;<span style="text-decoration: overline">2P</span></span>**, where **A** represents the peak value of sinusoidal carrier.

Thus the above equation can be written as

![equation 2](Images/2.png)

![equation 3](Images/3.png)

![equation 4](Images/4.png)
&nbsp;&nbsp;&nbsp;&nbsp;, where  E = PT is the energy contained in the bit duration.

![signal 1](Images/signal1.png) &nbsp;
![signal 2](Images/signal2.jpg)

**Figure.1** shows  the BPSK signal for bit sequence 1001,

The received signal has the form &nbsp; ![equation 7](Images/7.png) &nbsp; , where &Theta; is the phase shift introduced by the channel. The signal **b(t)** is recovered in the **demodulator**. If **synchronous demodulation** is used, the waveform **cos(2&pi;f<sub>c</sub>t + &Theta;)** is required at the demodulator. Carrier recovery scheme in the demodulator is shown in Figure.2.

![BPSK modulator and demodulator](Images/BPSKmodem.jpg)

**Figure.2** BPSK modulator and demodulator

The recovered carrier is multiplied with the received signal to generate

![equation 8](Images/8.png)

Assuming that integral number of carrier cycles is present in bit duration **T<sub>b</sub>** , voltage **v<sub>0</sub>(kT<sub>b</sub>)** and the bit synchronizer in Figure.2 knows the end of a bit interval and beginning of the next, the output  voltage **v<sub>0</sub>(kT<sub>b</sub>)** at the output of the integrate and dump circuit is:

![equation 9](Images/9.png)

If the channel is noisy, some of the demodulated bits will be in error.

**Bit Error Rate and E<sub>b</sub>/N<sub>0</sub> :**

&nbsp;&nbsp;&nbsp;&nbsp;Signal to noise ratios and E<sub>b</sub>/N<sub>0</sub> figures are parameters that are more associated with radio links and radio communications systems. In terms of this, the bit error rate, BER, can also be defined in terms of the probability of error or POE. To determine this, three other variables are used. They are the error function, erf, the energy in one bit, E<sub>b</sub>, and the noise power spectral density (which is the noise power in a 1 Hz bandwidth), N<sub>0</sub>.

The energy per bit, E<sub>b</sub>, can be determined by dividing the carrier power by the bit rate and is a measure of energy with the dimensions of Joules. N<sub>0</sub> is a power per Hertz and therefore this has the dimensions of power (joules per second) divided by seconds). Looking at the dimensions of the ratio E<sub>b</sub>/N<sub>0</sub> all the dimensions cancel out to give a dimensionless ratio. It is important to note that POE is proportional to E<sub>b</sub>/N<sub>0</sub> and is a form of signal to noise ratio.

It is possible to define the bit error rate in terms of a probability of error.

![equation 10](Images/10.gif)

where:

erfc = error function

E<sub>b</sub> = energy in one bit

N<sub>0</sub> = power spectral density (noise in 1Hz bandwidth).

It is important to note that E<sub>b</sub>/N<sub>0</sub> is a form of signal to noise ratio.

The energy per bit, E<sub>b</sub> can be determined by dividing the carrier power by the bit rate. As an energy measure, E<sub>b</sub> has the unit of Joules. N<sub>0</sub> is a measure of power (joules per second) per Hz, and as a result E<sub>b</sub>/N<sub>0</sub> is a dimensionless term and can be expressed simply as a ratio.

The error probability is seen to fall off monotonically with an increase in distance between the signals.