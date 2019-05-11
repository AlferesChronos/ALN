#include <vector>   // classe vector
using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/* Capçaleres de les funcions (estan implementades en altres arxius). */
double res_2 (Vector& r, int n);
double res_Inf (Vector& r, int n);

void residu (Matriu& A, Vector& x, Vector& b, int n, double res2, double resInf) {

	// CÂLCUL DE r = Ax-b 
	Vector r(n);
	for (int i = 0; i < n; ++i) {
		r[i] = -b[i];
		for (int j = 0; j < n; ++j) r[i] += A[i][j]*x[j];
	}

	// NORMA SUB2 DEL RESIDU
	res2 = res_2(r, n);

	// NORMA SUBINFINIT DEL RESIDU
	resInf = res_Inf(r, n);
}
