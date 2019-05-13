function [ det ] = DiagDet( R )
% Determinant d'una matriu diagonal (o triangular)
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
