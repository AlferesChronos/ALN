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
    A = getCoefficientMatrix(x, grau);

    % ii) Descomposició A = QR
    [Q, R] = qrdecomp(A); % veure a baix

    % iii) Comprovació que Q és ortogonal
    norma_residu = norm(Q'*Q - eye(grau + 1), inf);
    fprintf("Residue of Q'Q - I: %g\n", norma_residu)

    % iv) Solucionem el sistema triangular
    opts.UT = true;  % per indicar a linsolve que és R triangular sup.
    coefs = linsolve(R, Q'*y, opts);
    norm2Res = norm(A*coefs - y);

    % v) Mostrem una gràfica si plt
    if (nargin == 4)
        makePlot(x, y, coefs, plt)
    end
end


% Get the coefficient matrix for the normal equations
function A = getCoefficientMatrix(x, degree)
    if length(x) <= degree
        error('Grau del polinomi invàlid, calen més dades.')
    end
    
    A = vander(x);
    A = A(:, (end - degree):end);
end

% Simple QR decomposition by modified Gram-Schmidt
function [Q, R] = qrdecomp(A)
    n = size(A, 2);
    Q = A;
    R = zeros(n);
    
    for i = 1:n
        v = Q(:,i);
        for j = 1:(i - 1)
            u = Q(:,j);
            R(j,i) = dot(v, u)/dot(u, u);  % MGS (dot with current v)
            v = v - R(j,i)*u;
        end
        R(i,i) = norm(v);
        Q(:,i) = v/R(i,i);
    end
end


% Subroutine to plot the given points and the calculated polynomial 
% (sampled at plt equidistant points)
function makePlot(x, y, coefs, plt)
    xpol = linspace(min(x), max(x), plt);
    ypol = polyval(coefs, xpol);

    hold on
    plot(xpol, ypol, 'r-');
    plot(x, y, 'bo');
    title('Mínims quadrats')
    xlabel('x')
    ylabel('y')
    legend('polinomi', 'punts')
    hold off
end
