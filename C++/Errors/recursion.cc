#include<iostream>
#include<cmath>
#include<iomanip>

int main()
{
  int n=21, m=27;
  float pi, invpi, J[21], L[27];
  pi = 4.0*atan(1.0); //static_cast<float>(M_PI);
  invpi = 1.0/pi;

  std::cout << "Forward recurrence" << std::endl;
  J[0]=2.0/pi;
  std::cout << std::scientific << std::setprecision(6);
  std::cout << std::setw(4) << 0
            << std::setw(14) << J[0] << std::endl;
  for (int k=2; k<n; k+=2) {
    J[k]= 1.0/pi - k*(k-1)*J[k-2]/pi/pi;
    std::cout << std::setw(4) << k
              << std::setw(14) << J[k] << std::endl;
  }

  std::cout << std::endl << "Backward recurrence" << std::endl;
  L[m-1] = 0.0;
  std::cout << std::setw(4) << m-1
            << std::setw(14) << L[m-1] << std::endl;
  for (int k=m-1; k>0; k-=2) {
    L[k-2]= pi*pi*(invpi - L[k])/k/(k-1);
    std::cout << std::setw(4) << k-2
              << std::setw(14) << L[k-2] << std::endl;
  }

  return 0;
}
