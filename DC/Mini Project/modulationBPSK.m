function [y] = modulationBPSK(x_inp) % the input digital data   
    % Define transmitted signal 
    N=size(x_inp,2);                    % Number of bits, size of transmitted signal x_inp=[x_1 x_2 ... x_N]
    Tb = 0.001;                         % time period
    y = [];
    % Represent input signal as digital signal 
    x_bit=[];                       % used to represent digital signal
    nb=1/Tb;                        % bits to represent 1 bit in digital signal
    for n=1:1:N
        if x_inp(n)==1
           y = [y 1];
           x_bitt=ones(1,nb/2);             % nb number of 1s
           x_bitt=[x_bitt ones(1,nb/2)*-1];
        else
            y = [y -1];
            x_bitt=ones(1,nb/2).*-1;     % nb number of 0s
            x_bitt=[x_bitt ones(1,nb/2)];
        end
         x_bit=[x_bit x_bitt];      % append to x_bit
    end

    t1=Tb/nb : (Tb/nb) : nb*N*(Tb/nb); % time of the signal

    % plot graph and add legends 
    f1 = figure(1);
    set(f1,'color',[1 1 1]);
    subplot(3,1,1);
    plot(t1,x_bit,'lineWidth',2);grid on;
    axis([ 0 Tb*N -1.5 1.5]);
    ylabel('Amplitude(volt)');
    xlabel('Time(sec)');        % x and y labels
    title('Input signal as digital signal');
end
