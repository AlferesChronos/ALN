function [ invA ] = Inversa( Q, R )
% A*X = Id -> X = A^-1

[n, m] = size(Q);
Id = eye(n);

if DiagDet(R) == 0
    invA = zeros(n);
    return
end

invA = (Q*R) \ Id;

end
