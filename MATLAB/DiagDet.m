function [det] = DiagDet(R)
% DIAGDET   Aquesta funció calcula el determinant d'una matriu diagonal (o triangular)
% R mitjançant el producte d'elements de la diagonal.

n = size(R);
det = 1;

for i = 1:n
    a = R(i, i);
    if a == 0
        det = 0
        return
    end
    det = det*a;
end

end
