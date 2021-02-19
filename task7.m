ages = [10 + (90)*rand(5,2)];
ages = floor(ages);
frequency = [1 + 9*rand(5,2)];
frequency = floor(frequency);
disp("mean");
disp(mean(ages,2));
disp("median")
disp(median(ages,2))
disp("mode")
disp(mode(ages,2))
disp("variance")
disp(var(ages,0,2))
disp("standard deviation")
disp(std(ages,0,2))
disp("coefficient of correlation b/w a and b matrices")
disp(corrcoef(ages,frequency))

hist(ages,5)