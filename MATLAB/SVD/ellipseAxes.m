function [ymax, ymin] = ellipseAxes(A)
%ELLIPSEAXES Max/min axes of the ellipsoid formed by the 
%            image of the unit disk.
%   
%   [YMAX, YMIN] = ELLIPSEAXES(A) finds the image with maximal
%   norm of a vector in the unit circle (under the L2-norm) and
%   stores it in YMAX. Viceversa for YMIN (image with minimal norm).
%

[U, S, ~] = svd(A);
ymax = U(:,1)*S(1,1);
ymax = ymax*sign(ymax(1));
ymin = U(:,end)*S(end,end);
ymin = ymin*sign(ymin(1));

end

