function [x,rho,res,iter] = overRelaxation(A,b,x0,w,nmax,prec)
% FUNCTION [x,rho,res,iter] = overRelaxation(A,b,x0,w,nmax,prec)
% JACOBI. Resolution of a linear system Ax = b using over-relaxation 
%         iterative metod
%                       x^(k+1)= B_OR x^(k) + c_OR
%         with
%                B_OR = INV(D+w*L)*((1-w)*D-w*U), 
%                c_OR = w*INV(D+w*L)*b
% INPUT
%    A: real n x n matrix. Matrix of the linear system. 
%    b: real vector with n components. r.h.s. of the linear system. 
%   x0: starting approximation of the solution.
%    w: real value. Over-relaxation parameter. 
% nmax: integer value. Maximum number of iterates allowed. 
%       If after nmax iterates, the normalised residue is still bigger 
%       than the precision prec (see below), the function stops, gives 
%       back the control to the calling process and outputs the last 
%       computed value of the approximated solution, x^(nmax), and the 
%       residual, res.
% prec: real value. Threshold of the normalised residual. 
%       So, if the approximation produced by the kth iterate, x^(k), 
%       yields res:= |b - A*x^(k)|_Inf/|b - A*x^(0)|_Inf < prec, then the 
%       method stops and returns the approximate solution, x^(k), the last
%       computed residue, res, and the number of iterations performed,
%       iter (see the OUTPUT parameters).
% OUTPUT
%    x: real vector with n components. If the method converges, it gives 
%       the solution up to the given precision; if not, x is just the 
%       approximation reached after k = nmax iterates.
%  rho: spectral radius of the corresponding iteration matrix.
%  res: real value. Last computed normalised residual (see the INPUT).
% iter: integer value. Number of iterations actually performed. If no 
%       convergence is reached in nmax iterates, then iter = -nmax. 
%
% 2019 Equip Docent ALN
%

tol=1.0e-12;
D=diag(A);
if min(abs(D))<tol %check for zeros on the diagonal
    error('error: values on the diagonal with abs. val < %e',tol)
end

x = x0(:);
b = b(:);
res0 = norm(b-A*x);
D = diag(D);
L = D+w*tril(A,-1);
U = (1-w)*D-w*triu(A,1);
B = L\U;
c=L\b;
c=w*c;
rho=max(abs(eig(B)));
for iter=1:nmax
    x = B*x+c;
    res = norm(b-A*x)/res0;
    %fprintf('%3d %24.15e %14.15e\n',iter,norm(x,Inf),res); % just for test
    if (res < prec) 
        return
    end
end
iter = -nmax;
fprintf('Warnig: no convergence in %d iterations\n',nmax)

end %end of FUNCTON overRelaxation