#include <vector>  // classe vector
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/*
	RESOLUCIÓ D'UN ÚNIC SISTEMA USANT LES FUNCIONS LU I RESOL
*/

int lu (Matriu& A, int n, Vector& perm, double tol);
void resol (Matriu& A, Vector& x, Vector& b, int n, Vector& perm);

//   A: matriu A
//   x: vector d'incògnites
//   b: terme independent del sistema lineal
//   n: dimensió de la matriu
// tol: tolerància admesa sobre els pivots per decidir si la matriu A és singular o no
int sistema (Matriu& A, Vector& x, Vector& b, int n, double tol) {
	
	// DESCOMPOSICIÓ LU

	/** Declaració moderna del vector de permutacions. */
	Vector perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i; 

	/** La variable p indica 0 si la matriu A és singular. */
	int p = lu(A, n, perm, tol);

	if (p == 0) return 0;

	// RESOLUCIÓ DEL SISTEMA

	/** Resolem el sistema. */
	resol(A, x, b, n, perm);

	return p;
}