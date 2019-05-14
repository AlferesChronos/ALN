!fibonacci.f90
!Powers of the golden mean's inverse.
program fibonacci
  integer, parameter:: N=30
  integer:: k
  real (kind=4):: phi, phi1
  real (kind=4), dimension(0:2):: phi2, phi3
  data phi2(0),phi3(0)/2*1.0/
  phi=(sqrt(5.0)-1.0)/2.0
  phi1=phi; phi2(1)=phi; phi3(1)=phi;
  k=1
  write(*,100)k,phi1,phi2(1),phi3(1)
  do k=2,N
     phi1=phi*phi1
     phi2(2)=phi2(0)*(1.0-phi)
     phi3(2)=phi3(0)-phi3(1)
     write(*,100)k,phi1,phi2(2),phi3(2)
     phi2(0)=phi2(1); phi2(1)=phi2(2)
     phi3(0)=phi3(1); phi3(1)=phi3(2)
  end do
100 format(I4,3E15.7)
  stop
end program fibonacci
