function [A, b] = readSystem(filename)
% READSYSTEM  llegeix una matriu A i un vector b a partir d'un
%             arxiu de text en el format de la pràctica 1
%
%   [A, B] = READSYSTEM(FILENAME) llegeix una matriu A nxn i un
%   vector B nx1 de l'arxiu FILENAME, on FILENAME és un string amb
%   el nom de l'arxiu.

fileID = fopen(filename, 'r');
n = fscanf(fileID, '%u', 1);

A = readMatrix(n, fileID);
b = readVector(n, fileID);

end


function A = readMatrix(n, fileID)
    m = fscanf(fileID, '%u', 1);
    data = fscanf(fileID, '%u %u %f', [3, m]);
    indices = uint32(data(1:2,:));
    data = data(3, :);
    
    A = zeros(n);
    A(n*indices(1, :) + indices(2, :) + 1) = data;
end

function b = readVector(n, fileID)
    k = fscanf(fileID, '%u', 1);
    data = fscanf(fileID, '%u %f', [2, k]);
    indices = uint32(data(1,:)) + 1;
    data = data(2, :);
    
    b = zeros(n, 1);
    b(indices) = data;
end
