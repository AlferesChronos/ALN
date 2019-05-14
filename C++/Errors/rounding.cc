#include<iostream>
#include<iomanip>
#include "errors.h"

int main(int argc, char *argv[])
{
	if (argc < 3) {
		std::cerr << "Error: no parameters. Use:" << std::endl;
		std::cout << "~$ rounding a t" << std::endl;
 		exit(-1);
	}	
	double a = static_cast<double>(atof(argv[1]));
	int t = atoi(argv[2]);
	std::cout << std::scientific;
  std::cout << std::setprecision(15);
	std::cout << "a            = " << a << std::endl;
	std::cout << std::setprecision(t-1);
	std::cout << "a (chopping) = " << chop(a,t) << std::endl;
	std::cout << "a (approx. ) = " << approx(a,t) << std::endl;
	return 0;
}
