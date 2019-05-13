function [x,rho,res,iter] = jacobi(A,b,x0,nmax,tol)

tol=1.0e-12;
D=diag(A);
if min(abs(D))<tol %check for zeros on the diagonal
    error('Error: valors a la diagonal amb valor absolut < %e',tol)
end

P=diag(diag(A));
n=size(P,1);
B=eye(n)-P\A;
b=b(:);
c=P\b;
x=x0(:);
rho=max(abs(eig(B)));

for iter=1:nmax
    x=B*x+c;
    res=norm(A*x-b);
    if res < tol
        break
    end
end

iter = -nmax;
fprintf('Error: no hi ha hagut convergència en %d iteracions\n',nmax)

end

