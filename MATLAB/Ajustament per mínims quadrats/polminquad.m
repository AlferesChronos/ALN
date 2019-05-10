% Aproximació per un polinomi pel mètode dels mínims quadrats
%
% POLMINQUAD: Calcula l'aproximació polinomial de les dades de x i y pel
% mètode de mínims quadrats.
%
% INPUT:
%     x: vector d'abcisses.
%     y: vector d'ordenades.
%     grau: grau del polinomi que es vol.
%     plt: (opcional) nombre de punts a utilitzar per dibuixar la gràfica de
%     l'aproximació.
%
% OUTPUT:
%     coefs: vector de coeficients del polinomi aproximador.
%     norm2res: norma-2 del residu, ||A*coefs-y||_2, on A és la matriu formada
%     per les últimes grau+1 columnes de la matriu de Vandermonde generada pel
%     vector x.
%
% Imprimeix per pantalla la norma-infinit de Q'*Q-Id, anomenada
% residu_Q_ortogonal.

function [coefs, norm2Res] = polminquad(x, y, grau, plt)
% Per posar els vectors en columna
x = x(:);
y = y(:);

% i) Construïm la matriu de Vandermonde associada a x
A = vander(x);
m = size(A, 1);

if m-grau <= 0
    error('Grau del polinomi invàlid, calen més dades.')
end

A = A(:,m-grau:m);

% ii) Descomposició A = QR
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

% iii) Comprovació que Q és ortogonal
norma_residu = norm(Q'*Q - eye(n), inf)

% iv) Solucionem el sistema triangular
coefs = zeros(n, 1);
b = Q'*y;
coefs(n) = b(n)/R(n, n);
for k=n-1:-1:1
    coefs(k) = (b(k)-R(k, k+1:n)*coefs(k+1:n))/R(k,k);
end
norm2Res = norm(A*coefs-y, 2);

% v) Mostrem una gràfica si plt
if (nargin == 4)
    xx = linspace(x(1), x(end), plt);
    plot(x, y, 'bo')
    hold on
    yy = polyval(coefs, xx);
    plot(xx, yy, 'r-')
    title('Mínims quadrats')
    xlabel('x')
    ylabel('y')
    legend('punts', 'polinomi')
    hold off
end

end
