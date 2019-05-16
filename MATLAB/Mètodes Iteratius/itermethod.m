function [x, res, iter] = itermethod(A,b,G, c, x0, nmax, tol)
% ITERMETHOD  subroutine common to all iterative methods for linear
%             systems
%
%   [X, RES, ITER] = ITERMETHOD(A, B, G, C, X0, NMAX, TOL)  iterates
%                    x^(k+1) = Gx^k + C until either the norm of the
%                    residual Ax - B is less than TOL or NMAX iterations
%                    are reached.
%

    x = x0(:);
    res0 = norm(b-A*x);
    
    for iter = 1:50
        x = G*x + c;
        res = norm(A*x - b, inf)/res0;
        if res < tol; return; end
    end
    
    for iter = 50:nmax
        x = G*x + c;
        if mod(iter, 10) == 0
            res = norm(A*x - b, inf)/res0;
            if res < tol; return; end
        end
    end
    
    warning('no convergence in %d iterations\n', nmax)
    
end