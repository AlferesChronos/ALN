//sumshg.cc: sum of the 15 first terms of the Riemann series corresponding
// to p=2.
#include<iostream>
#include<iomanip>
#include "errors.h"

//using namespace std;

int main()
{
  int k,n=15;
  double a, sum=0.0e0;
  for (int i=1; i<=n; i++) {
    a=static_cast<double>(i*i);
    a=chop(a,3);
    a=1.e0/a;
    a=chop(a,3);
    sum+=a;
    sum=chop(sum,3);
  }
  std::cout << std::scientific;
  std::cout << "Sum in 'natural' (decreasing) order, with t=3: S15 = "
            << std::setprecision(2)
            << sum << std::endl;

  sum=0.0e0;
  for (int i=n; i>0; i--) {
    a=static_cast<double>(i*i);
    a=chop(a,3);
    a=1.0e0/a;
    a=chop(a,3);
    sum+=a;
    sum=chop(sum,3);
  }
  std::cout << "Sum in 'reverse' (increasing) order, with t=3: S15 = "
            << std::setprecision(2)
            << sum << std::endl;

  sum = 0.0e0;
  for (int i=n; i>0; i--) {
    a=1.e0/(i*i);
    sum+=a;
  }
  std::cout << "Sum in 'reverse' order, with t=16 (d.p.): S15 = "
            << std::setprecision(15)
            << sum << std::endl;

  return 0;
}
