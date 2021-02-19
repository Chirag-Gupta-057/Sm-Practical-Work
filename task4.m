%{
    Calculation of central values for lists(mean,median,mode,variance,standard deviation, coefficient of correlation)
%}

a = [1,2,3;4,5,6;7,8,9]
b = [9,8,7;6,5,4;3,2,1]
disp("mean")
disp(mean(a,3))
disp("median")
disp(median(a,3))
disp("mode")
disp(mode(a,3))
disp("variance")
disp(var(a,0,3))
disp("standard deviation")
disp(std(a,0,3))
disp("coefficient of correlation b/w a and b matrices")
disp(corrcoef(a,b))