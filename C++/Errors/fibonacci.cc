// fibonaci.cc: powers of the golden mean's inverse
#include<iostream>
#include<iomanip>
#include<cmath>

int main()
{
  const int n=30;
  int k;
  float phi1,phi2[3],phi3[3];
  float phi=(std::sqrt(5.0)-1.0)/2.0;

  std::cout << std::scientific;
  phi2[0]=phi3[0]=1.0;
  phi1=phi2[1]=phi3[1]=phi;
  k=1;
  std::cout << std::setw(4) << k << std::setw(15)
            << phi1 << std::setw(15)
            << phi2[1] << std::setw(15)
            << phi3[1] << std::endl;

  for(k=2; k<=n; k++) {
    phi1=phi*phi1;
    phi2[2]=phi2[0]*(1.0f-phi);
    phi3[2]=phi3[0]-phi3[1];
    std::cout << std::setw(4) << k << std::setw(15)
              << phi1 << std::setw(15)
              << phi2[2] << std::setw(15)
              << phi3[2] << std::endl;
    phi2[0]=phi2[1]; phi2[1]=phi2[2];
    phi3[0]=phi3[1]; phi3[1]=phi3[2];
  }

  return 0;
}
