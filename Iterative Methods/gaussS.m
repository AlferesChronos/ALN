function [x,res,iter] = gaussS(A,b,x0,nmax,tol)

P=diag(diag(A))+tril(A,-1);
n=size(P,1);
B=-P\triu(A,1);
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

