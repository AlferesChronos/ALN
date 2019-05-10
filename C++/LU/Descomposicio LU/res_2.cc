#include <vector>   // classe vector
#include <cmath>    // funció sqrt (arrel quadrada)
using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;

/* Funció que calcula norma sub2 d'un vector (de dimensió n) r */
double res_2 (Vector& r, int n) {
	double norm = 0;
	for (int i = 0; i < n; ++i) norm += r[i]*r[i];

	return sqrt(norm);
}