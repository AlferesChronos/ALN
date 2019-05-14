clearvars
close all
x=[0.25;0.50;0.75;1.00;1.25;1.50;1.75];
y=[0.40;0.50;0.90;1.28;1.60;1.66;2.02];
xx=linspace(x(1),x(end),301);
m=size(x,1);
M=vander(x);

format long e
%(a)
deg=1;
deg
n=deg+1;
A=M(:,m-deg:m);
Q=A;
R=zeros(n);

% Modified GS:
%k=1;
R(1,1)=norm(Q(:,1),2);
Q(:,1)=Q(:,1)/R(1,1);
R(1,2:n)=Q(:,1)'*Q(:,2:n);
Q(:,2:n)=Q(:,2:n)-Q(:,1)*R(1,2:n);
%k=2
R(2,2)=norm(Q(:,2),2);
Q(:,2)=Q(:,2)/R(2,2);
Q,R
a=solveTS(R,Q'*y)

% plot
yy=polyval(a,xx);
figure()
plot(xx,yy,'-',x,y,'o')
axis equal
xlabel('x')
ylabel('y')
title(['LSF polynomial approximation, deg. ',int2str(deg)])

%(b)
deg=2;
deg
n=deg+1;
A=M(:,m-deg:m);
Q=A;
R=zeros(n);

%G-S modificat:
%k=1;
R(1,1)=norm(Q(:,1),2);
Q(:,1)=Q(:,1)/R(1,1);
R(1,2:n)=Q(:,1)'*Q(:,2:n);
Q(:,2:n)=Q(:,2:n)-Q(:,1)*R(1,2:n);
%k=2;
R(2,2)=norm(Q(:,2),2);
Q(:,2)=Q(:,2)/R(2,2);
R(2,3:n)=Q(:,2)'*Q(:,3:n);
Q(:,3:n)=Q(:,3:n)-Q(:,2)*R(2,3:n);
%k=3;
R(3,3)=norm(Q(:,3),2);
Q(:,3)=Q(:,3)/R(3,3);
Q,R
a=solveTS(R,Q'*y)

%plot
yy=polyval(a,xx);
figure()
plot(xx,yy,'-',x,y,'o')
axis equal
xlabel('x')
ylabel('y')
title(['LSF polynomial approximation, deg. ',int2str(deg)])

%Interpolation polynomial
p=polyfit(x,y,m-1);
yy=polyval(p,xx);
figure()
plot(xx,yy,'-',x,y,'o')
axis equal
xlabel('x')
ylabel('y')
title(['Interpolation polynomial (degree ', int2str(m-1), ')'])