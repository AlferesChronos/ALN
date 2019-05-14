#include<cmath>

double chop(double x, int t)
{
	double mantissa;
	int exponent;
	exponent = 1 + static_cast<int>(std::floor(std::log10(std::abs(x))));
  mantissa = static_cast<double>(std::trunc(x*std::pow(10.0e0d,t-exponent)));
	return(mantissa*std::pow(10.0e0d,exponent-t));
}

double approx(double x, int t)
{
	double mantissa;
	int exponent;
	exponent = 1 + static_cast<int>(std::floor(std::log10(std::abs(x))));
  mantissa = static_cast<double>(std::round(x*std::pow(10.0e0d,t-exponent)));
	return(mantissa*std::pow(10.0e0d,exponent-t));
}
