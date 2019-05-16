function checkDiag(A)
%CHECKDIAG Check for null values on the diagonal of a matrix
%
    tol=1.0e-12;
    if min(abs(diag(A))) < tol %check for zeros on the diagonal
        error('error: values on the diagonal with abs. val < %e',tol)
    end
end

