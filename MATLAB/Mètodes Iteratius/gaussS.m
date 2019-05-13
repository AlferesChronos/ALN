function [x,rho,res,iter] = gaussS(A,b,x0,nmax,prec)

tol=1.0e-12;
D=diag(A);
if min(abs(D))<tol %check for zeros on the diagonal
    error('error: valors a la diagonal amb valor absolut < %e',tol)
end

x=x0(:);
b=b(:);

P=tril(A);
n=size(P,1);
B=-P\triu(A,1);
c=P\b;
rho=max(abs(eig(B)));

for iter=1:nmax
    x=B*x+c;
    res=norm(A*x-b);
    if res < prec
        return
    end
end

end

