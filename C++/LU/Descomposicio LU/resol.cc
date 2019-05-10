#include <vector> // classe vector
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/*
	RESOLUCIÓ D'UN SISTEMA LINEAL Ax = b

	on la matriu A és no singular i la tenim factoritzada LU
*/

//    A: la matriu A descomposada LU
//    b: terme independent del sistema lineal
//    n: dimensió del sistema
// perm: vector de permutació de la descomposició de A en LU
void resol (Matriu& A, Vector& x, Vector& b, int n, Vector& perm) {

	/** Primer es permuta el vector de termes indepents: Pb = c */
	Vector c(n);
	for (int i = 0; i < n; ++i)	c[i] = b[perm[i]];

	/* Es resol LUx = Pb = c, resolemt dos sistemes triangulars:
		Ly = c
		Ux = y
	Els dos amb cost computacional o(n^2)  */

	/** Sistema triangular inferior amb 1 a la diagonal principal. */
	Vector y(n);
	for (int i = 0; i < n; ++i) {
		y[i] = c[i];
		for (int j = 0; j < i; ++j) y[i] -= A[i][j]*y[j];
	}
	
	/** Sistema triangular superior. */
	for (int i = n-1; i >= 0; --i) {
		x[i] = y[i];
		for (int j = i+1; j < n; ++j) x[i] -= A[i][j]*x[j];
		x[i] /= A[i][i];
	}
}