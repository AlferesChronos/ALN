function [x,res,iter] = gaussSiedel(A,b,x0,nmax,prec)
% GAUSSSIEDEL Resolution of a linear system Ax = b using Gauss-Seidel 
%            iterative metod
%                          x^(k+1)= B_GS x^(k) + c_GS
%            with
%                          B_GS = -INV(D+L)*U, c_GS = INV(D+L)*b
% INPUT
%    A: real n x n matrix. Matrix of the linear system.
%    b: real vector with n components. r.h.s. of the linear system. 
%   x0: starting approximation of the solution.
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
%       covergence is reached in nitem iterates, the iter = -nmax; 
%
% 2019 Equip Docent ALN
%

checkDiag(A);
x0 = x0(:);
b = b(:);

[B, c] = getGaussSiedel(A, b);
[x, res, iter] = itermethod(A, b, B, c, x0, nmax, prec);

end %end of FUNCTION gaussS


function [B, c] = getGaussSiedel(A, b)
    L=tril(A);
    U=triu(A,1);
    c=L\b;
    B=-L\U;
end