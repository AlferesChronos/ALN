function [x,res,iter] = overRelaxation(A,b,x0,w,nmax,tol)

P=(1/w)*diag(diag(A))+tril(A,-1);
n=size(P,1);
B=P\(P-A);
c=P\b;
x=x0;

for i=1:nmax
    x=B*x+c;
    res=norm(A*x-b);
    iter=i;
    if res < tol
        break
    end
end

end

