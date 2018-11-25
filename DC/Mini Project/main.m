% main file

% input for modulation is x_inp
x_input = input('Enter Signal for modulation\n');
[y] = modulationBPSK(x_input);                  % Modulation

% demodulation input is y
disp('Demodulated signal is:');                 % Demodulation
sig = demod(y);

disp(sig);

while true 
    disp('1: BER_th vs BER_simu for AWGN channel');
    disp('2: BER_th vs BER_simu for Rayleigh channel');
    disp('3: BER_th vs SNR BPSK QPSK 8-PSK 16-PSK');
    disp('4: BER_th vs SNR BPSK AWGN and Rayleigh');
    
    choice = input(['Enter Choice' newline]);
    
    switch(choice)
        case 1
            comparision_1();    % if choice is 1 execute comparision_1
        case 2
            comparision_2();    % if choice is 2 execute comparision_2
        case 3
            comparision_3();    % if choice is 3 execute comparision_3
        case 4
            comparision_4()     % if choice is 4 execute comparision_4
            
        otherwise               % else break the loop 
            break;
    end
    
end
