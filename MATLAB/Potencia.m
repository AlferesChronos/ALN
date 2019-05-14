function [vap, vep] = Potencia(A, x)
% POTENCIA  Aquesta funció calcula el valor propi més gran d'A en valor absolut pel mètode de la potència,
% i també calcula el vector propi corresponent.

tol = 1e-12;
prev = ones(size(x));

while norm(x - prev, 1) > tol
    prev = x;
    x = A*prev/norm(A*prev, 2);
end

vep = x;
vap = (vep.'*A*vep)/(vep.'*vep);

end
