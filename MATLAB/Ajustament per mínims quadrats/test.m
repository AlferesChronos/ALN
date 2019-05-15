function [coefs, norm2Res] = test(n, deg)
% TEST  Test per la funció polminquad.
%
%   [COEFS, NORM2RES] = TEST(N, DEG)  crea N + 1 punts
%   equiespaiats entre x = 0 i x = 2*pi tals que y = sin(x) mes una 
%   perturbació aleatòria, i crida polminquad(x, y, DEG, 100). Guarda els 
%   resultats (els coeficients i la norma del residu) a COEFS i NORM2RES
%   respectivament.
%

    x = linspace(0, 2*pi, n + 1);
    y = sin(x) + 0.4*rand(1, n + 1);
    close
    [coefs, norm2Res] = polminquad(x', y', deg, 100);
end