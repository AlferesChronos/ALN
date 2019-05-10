function [coefs, norm2Res] = polminquad(x,y,grau,plt)
%POLMINQUAD    Calcula l'aproximació polinomial de les dades de x i y pel
%mètode de mínims quadrats.
%INPUT:
%x: vector d'abcisses.
%y: vector d'ordenades.
%grau: grau del polinomi que es vol.
%plt: (opcional) nombre de punts a utilitzar per dibuixar la gràfica de
%l'aproximació.
%OUTPUT:
%coefs: vector de coeficients del polinomi aproximador.
%norm2res: norma-2 del residu, ||A*coefs-y||_2, on A és la matriu formada
%per les últimes grau+1 columnes de la matriu de Vandermonde generada pel
%vector x.
%Imprimeix per pantalla la norma-infinit de Q'*Q-Id, anomenada
%residu_Q_ortogonal.
x=x(:);
y=y(:);
A=vander(x);
m=size(A,1); %nombre de files
A=A(:,m-grau:m);
n=size(A,2); %nombre de columnes=grau+1
Q=A; %dimensions m*(grau+1)
R=zeros(n); %dimensions (grau+1)*(grau+1)

%Descomposem A=QR
for k=1:n-1
    R(k,k)=norm(Q(:,k));
    Q(:,k)=Q(:,k)/R(k,k);
    R(k,k+1:n)=Q(:,k)'*Q(:,k+1:n);
    Q(:,k+1:n)=Q(:,k+1:n)-Q(:,k)*R(k,k+1:n);
end
R(n,n)=norm(Q(:,n));
Q(:,n)=Q(:,n)/R(n,n);
residu_Q_ortogonal = norm(Q'*Q-eye(n),inf)

%Solucionem el sistema triangular superior Ra=Q'*y, equivalent a M'*Ma=M'*y
coefs=zeros(n,1);
b=Q'*y;
n=size(R,1);
coefs(n)=b(n)/R(n,n);
for k=n-1:-1:1
    coefs(k)=(b(k)-R(k,k+1:n)*coefs(k+1:n))/R(k,k);
end
norm2Res=norm(A*coefs-y);

if (nargin==4)
    xx=linspace(x(1),x(end),plt);
    plot(x,y,'ro')
    hold on
    yy=polyval(coefs,xx);
    plot(xx,yy,'b-')
    title('Mínims quadrats')
    xlabel('x')
    ylabel('y')
    legend('punts','polinomi')
    hold off
end
end