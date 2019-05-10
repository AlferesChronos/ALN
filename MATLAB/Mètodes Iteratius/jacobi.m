function [x,res,iter] = jacobi(A,b,x0,nmax,tol)

P=diag(diag(A));
n=size(P,1);
B=eye(n)-P\A;
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

