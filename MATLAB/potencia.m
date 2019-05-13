function [vap, vep] = potencia(A, x)
% Mètode de la potència
tol = 1e-12;
prev = ones(size(x));

while norm(x - prev, 1) > tol
    prev = x;
    x = A*prev/norm(A*prev, 2);
end

vep = x;
vap = (vep.'*A*vep)/(vep.'*vep);
end
