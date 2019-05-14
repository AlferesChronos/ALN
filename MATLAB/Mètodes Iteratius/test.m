clearvars
load 'matrix150.mat'
prec=1.0e-12;
nmaxit=3000;

fprintf('%20s%8s\n','res/res0','iter')
n=size(A,1);
x0=rand(n,1);
[solJacobi,rho,res,iter] = jacobi(A,b,x0,nmaxit,prec);
fprintf('%-10s%10.4e%8d\n','Jacobi',res,iter)
[solJacobi,rho,res,iter] = gaussS(A,b,x0,nmaxit,prec);
fprintf('%-10s%10.4e%8d\n','Gauss-S.',res,iter)
w=0.93;
[solJacobi,rho,res,iter] = overRelaxation(A,b,x0,w,nmaxit,prec);
fprintf('%-10s%10.4e%8d\n','SOR',res,iter)