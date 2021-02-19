m = [1000 + (5000)*rand(5,2)];
w = [6 + (9)*rand(5,2)];
 disp("Covariance:");
 disp(cov(m,w,0));
 disp("Correlation");
 disp(corr(m,w));
 
 
 plot(m);
 plot(w);