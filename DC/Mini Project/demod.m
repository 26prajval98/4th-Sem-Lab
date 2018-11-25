function dsig = demod(y)        % function demod returning dsig

	dsig = [];                  % representing the demodulated signal
	
	for x = 1:size(y,2)         % Using BPSK logic after adiition of noise
		if( y(:,x) > 0 )        % If y(x) is > 0 then from BPSK logic its demodulated part must be 1
			dsig =[dsig 1];     
            elseif (y(:,x) < 0)     % If y(x) is < 0 then from BPSK logic its demodulated part must be 0
    			dsig =[dsig 0];
        else                    % If somehow it is 0 then choose randomly
            if rand(1,1) >= 0.5
                dsig = [dsig 1];
            else
                dsig = [dsig 0];
            end
		end
    end
end
