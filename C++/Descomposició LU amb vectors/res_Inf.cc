#include <vector>   // classe vector
#include <cmath>  // funció abs
using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;

/* Funció que calcula norma subinfinit d'un vector (de dimensió n) r */
double res_Inf (Vector& r, int n) {
	int max;
	double m = 0;
	for (int i = 0; i < n; ++i) {
		if (abs(r[i]) > m) {
			m = abs(r[i]);
			max = i;
		}
	}

	return abs(r[max]);
}