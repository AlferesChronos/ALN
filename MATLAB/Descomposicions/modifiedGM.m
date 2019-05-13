function [Q, R] = modifiedGM(A)

% Descomposició A = QR
n = size(A, 2);
Q = A;
R = zeros(n);

for k = 1:n-1
    R(k, k) = norm(Q(:, k));
    Q(:, k) = Q(:, k)/R(k, k);
    R(k, k+1:n) = Q(:, k)'*Q(:, k+1:n);
    Q(:, k+1:n) = Q(:, k+1:n) - Q(:, k)*R(k, k+1:n);
end
R(n, n) = norm(Q(:, n));
Q(:, n) = Q(:, n)/R(n, n);

end
