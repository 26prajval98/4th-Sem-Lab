% Performance of BPSK in Rayleigh medium
clear;
close all;
num_bit = 1000000;              % number of bit
data = rand(1,num_bit);         % random bit generation (1 or 0) to create data of num_bit length

for i = 1:num_bit               % Generation of digital signals from randomly generated numbers   
    if(data(i)>0.5)
        data(i) = 1;    
    else
        data(i) = 0;
    end
end

s = 2*data-1;                   % conversion of data for BPSK modulation
SNRdB = 0:1:20;                 % SNR in dB
SNR = 10.^(SNRdB/10);           % SNRdb to SNR

figure(2);

BER_thA = (1/2)*erfc(sqrt(SNR));                                % BER_thA from its formula
semilogy(SNRdB,BER_thA,'mx-','linewidth',2),grid on,hold on;    % plotting BER_th AWGN

BER_thR = 0.5.*(1-sqrt(SNR./(SNR+1)));                   % BER_thR from its formula
semilogy(SNRdB,BER_thR,'r','linewidth',2);               % plotting BER_th Rayleigh

title('Bit Error Rate vs SNR (Eb/N0) for Binary PSK modulation Rayleigh Medium and AWGN medium');   %Graph labelling and legends
xlabel('SNR(dB)');
ylabel('BER');
legend('AWGN','Rayleigh');
