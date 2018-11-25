% performance comparison of BPSK, QPSK, 8-PSK and 16-PSK
clc;
close all;

SNRdB=-4:1:24;                                      % SNRdB ranging from -4 to 24
SNR=10.^(SNRdB/10);
colors={'k-s','g','r-h','c-s'};
index=1;                                            % for keeping track of colors
 
% BPSK
BPSK = 0.5*erfc(sqrt(SNR));                                    % BPSK formula using matlab error function erfc for AWGN channel
plotHandle=plot(SNRdB,log10(BPSK),char(colors(index)));        % define plotHandle
set(plotHandle,'LineWidth',1.5);
hold on;
 
index=index+1;
 
% M-PSK
m=2:1:4;                                            % m = [2 3 4]
M=2.^m;                                             % M = [4 8 16]
for i=M
    k=log2(i);
    berErr = 1/k*erfc(sqrt(SNR*k)*sin(pi/i));                   % formula for bit error rate AWGN channel for M-PSK using general formula
    plotHandle=plot(SNRdB,log10(berErr),char(colors(index)));
    set(plotHandle,'LineWidth',1.5);
    index=index+1;
end

% plot start

legend('BPSK','QPSK','8-PSK','16-PSK');                         % Settings legends                  

axis([-4 24 -8 0]);                                             % Setting axis
set(gca,'XTick',-4:1:24);                                            
ylabel('Probability of BER Error - log10(Pb)');                 % Y and X label
xlabel('Eb/N0 (dB)');

title('Probability of BER Error log10(Pb) Vs Eb/N0');           % Graph title
grid on;
