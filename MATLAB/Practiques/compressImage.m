clearvars
close
clc

A=imread('koshka.jpg');
A=rgb2gray(A); % Convert color image to B/W
[m,n]=size(A);
storageA=m*n;
A=double(A);

r = rank(A);

[U,S,V]=svd(A);
k=[1,2,10,15,100];
storage=k;
q=length(k);
total=m*n; %*ones(1,q);

for i=1:q
    X=U(:,1:k(i))*S(1:k(i),1:k(i))*(V(:,1:k(i)))';
    storage(i)=k(i)*(m+n+1);
    ratio(i) = 100*storage(i)/total; %(i);
    figure(i)
    imshow(uint8(X));
    str=sprintf('#Singular values: %d (de %d)',k(i),r);
    title(str);
    fprintf('#SV: %d (of %d). Intro to continue...\n',k(i),r);
    pause
end

fprintf('#Components (pixels in B/W) of the image: %d (%d x %d)\n', ...
    storageA, m, n)
fprintf('%5s%15s%12s\n','#SV','#Components','Ratio (%)');
fprintf('%5d%15d%12.2f\n',[k; storage; ratio]);

q=q+1;
figure(q)
imshow(uint8(A));
title('Original photography in B/W');

display('Intro to close all windows...');
pause
close(1:q);

fprintf('Important Notice: ')
fprintf('No animals were harmed in the making of this script.\n')