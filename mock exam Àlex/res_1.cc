#include <vector>   // classe vector
#include <cmath>  // funció abs
using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/* Funció que calcula norma sub-1 d'una matriu (de dimensió n) R */
double res_1 (Matriu& R, int n) {
	double max = 0;
    
    for (int j = 0; j < n; ++j) {
        double actual = 0;
        for (int i = 0; i < n; ++i) {
            actual += abs(R[i][j]);
        }
        if (actual > max) max = actual;
    }
    
    return max;
}
