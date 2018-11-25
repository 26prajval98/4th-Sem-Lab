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
SNRdB = 0:1:43;                 % SNR in dB
SNR = 10.^(SNRdB/10);           % SNRdb to SNR

for k = 1:length(SNRdB)         % BER (error/bit) calculation for different SNR
    y = RY(s,SNRdB(k));         % add noise to signal after Rayleigh fading ( wireless-medium )
    error = 0;
    for c = 1:1:num_bit
        if (y(c)>0&&data(c)==0)||(y(c)<0&&data(c)==1)   % calculating total error i.e number of bits changed after transmission 
            error = error+1;
        end
    end
    error = error / num_bit;                            % Calculate error/bit
    m(k) = error;                                       % m is the array for that SNRdB value
end

figure(2);
semilogy(SNRdB,m,'mx-','linewidth',2),grid on,hold on;  %plotting simulation

BER_th = 0.5.*(1-sqrt(SNR./(SNR+1)));                   % BER_th from its formula
semilogy(SNRdB,BER_th,'r','linewidth',2);               % plotting BER_th

title('Bit Error Rate vs SNR (Eb/N0) for Binary PSK modulation Rayleigh Medium');   %Graph labelling and legends
xlabel('SNR(dB)');
ylabel('BER');
legend('simulation','theoretical');
