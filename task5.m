function [A1 A2 D Tp Ev] = sriesv( T, lam, l1, l2 )
% Two Servers in Series Q Simulation for total time T;
% input parameter lam for exponential arrivals
% input parameters l1, l2 for server time distributions
% output arrays A1, A2, D for server arrival, departure times
% output Tp for overtime and Ev for event list
t = 0; na = 0; nd = 0; n1 = 0; n2 = 0; j = 0;
ta = -log(rand)/lam; t1 = inf; t2 = inf;
while ta <= T % time left
if ta <= min( t1, t2 ) % new arrival
t = ta; n1 = n1 + 1; na = na + 1;
ta = t - log(rand)/lam; A1(na) = t;
if n1 == 1, t1 = t + G(l1); end
elseif t1 <= t2 % departure from Q1
t = t1; n1 = n1 - 1; n2 = n2 + 1; A2(na-n1) = t;
if n1 > 0, t1 = t + G(l1); else, t1 = inf; end
if n2 == 1, t2 = t + G(l2); end
else % departure from Q2
t = t2; n2 = n2 - 1; nd = nd + 1; D(nd) = t;
if n2 > 0, t2 = t + G(l2); else, t2 = inf; end
end, j = j + 1; Ev(j,:) = [ n1 n2 t ];
end % no more arrivals
5
%
% sriesv continued
%
while n1 > 0 % empty Q1
if t1 <= t2, t = t1; n1 = n1 - 1; n2 = n2 + 1;
if n1 > 0, t1 = t + G(l1); else, t1 = inf; end
if n2 == 1, t2 = t + G(l2); end, A2(na-n1) = t;
else, t = t2; n2 = n2 - 1; nd = nd + 1; D(nd) = t;
if n2 > 0, t2 = t + G(l2); else, t2 = inf; end
end, j = j + 1; Ev(j,:) = [ n1 n2 t ];
end % Q1 is empty
while n2 > 0 % empty Q2
t = t2; n2 = n2 - 1; nd = nd + 1; D(nd) = t;
if n2 > 0, t2 = t + G(l2); else, t2 = inf; end
j = j + 1; Ev(j,:) = [ n1 n2 t ];
end % Q2 is empty, find Tp
Tp = max(t-T,0);
% end sriesv
function Y = G(a), Y = -log(rand)/a; % Exponential(a) RV