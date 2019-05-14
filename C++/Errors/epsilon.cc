#include<iostream>
#include<cstdlib>
#include<cfloat>

using namespace std;

int main()
{
	float eps = 1.0;
	while (1.0f + eps > 1.0f) {
	       eps /= 2.0;
	}
	cout << "eps = " << 2*eps << endl;
	cout << "FLT_EPSILON = " << FLT_EPSILON << endl;

  double eps_ = 1.0e0;
  while (1.0e0d + eps_ > 1.0e0d) {
    eps_ /= 2.0e0d;
  }
 	cout << "eps_ = " << 2*eps_ << endl;
	cout << "DBL_EPSILON = " << DBL_EPSILON << endl;
	return 0;
}
