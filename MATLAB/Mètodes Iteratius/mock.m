clearvars
warning off
load M2.mat
prec=1.0e-12;
nmaxit=10;
w = 0.9;
x0 = b;

fprintf('%10s\t %18s\t %18s\t %8s\n', '', 'norm', 'res/res0', 'iter')
[x,res,iter] = jacobi(A,b,x0,nmaxit,prec);
fprintf('%-10s\t %.12e\t %.12e\t %8d\n','Jacobi',norm(x, inf),res,iter)
[x,res,iter] = gaussSiedel(A,b,x0,nmaxit,prec);
fprintf('%-10s\t %.12e\t %.12e\t %8d\n','Gauss-S.',norm(x, inf),res,iter)
[x,res,iter] = overRelaxation(A,b,x0,w,nmaxit,prec);
fprintf('%-10s\t %.12e\t %.12e\t %8d\n','SOR',norm(x, inf),res,iter)