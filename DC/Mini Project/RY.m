function y = RY(x,SNRdB)

    % y=awgn_noise(x,SNR) adds AWGN noise vector to signal 'x' to generate a
    % resulting signal vector y of specified SNR in dB

    L=length(x);
    SNR = 10^(SNRdB/10);                        % SNR coneversion from SNRdB
    Esym=sum(abs(x).^2)/(L);                    % Calculate actual symbol energy
    N0=Esym/SNR;                                % Find the noise spectral density
    h = 1/sqrt(2)*[randn(1,L) + 1i*randn(1,L)]; % Rayleigh 
    n = 1/sqrt(2)*[randn(1,L) + 1i*randn(1,L)]; % AWGN at receiver
    
    z = h.*x + n*(10^(-SNRdB/20));              % Rayleigh fading
    y = z./h;                                   % Equalize the signal 
    
    y = real(y);                                % Output is real part of y 
end
