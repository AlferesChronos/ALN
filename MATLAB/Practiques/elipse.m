clearvars
close all

% Matriu 2x2 de components aleatoris
A = rand(2);
% Vector de 401 nombres equiespaiats entre 0 i tau
theta = linspace(0, 2*pi, 401);
% x, y són els punts de la circumferencia
x = cos(theta);
y = sin(theta);
% z són els compontents d'una elipse
z = A*[x;y];

% Fem la descomposició SVD
[U, S, V] = svd(A);
% Guardem les coses que volem aquí
eix = zeros(2,3);
% Els eixos de la elipse son U1 i U2 escalats sigma1 i sigma2
eix(:,2) = U(:, 1)*S(1, 1);
eix(:,3) = U(:, 2)*S(2, 2);

% ----------- GRAFIQUES --------------------
hold on
axis equal

% Circumferencia
plot(x, y, 'r-')

% Elipse
plot(z(1, :), z(2, :), 'b-')

% Eixos de la elipse
plot(eix(1, [1, 2]), eix(2, [1, 2]), 'k-');
plot(eix(1, [1, 3]), eix(2, [1, 3]), 'k-');

hold off