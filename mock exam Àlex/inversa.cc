#include <vector>  // classe vector
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/*
	TROBEM LA INVERSA USANT LES FUNCIONS LU I RESOL
*/

int lu (Matriu& A, int n, Vector& perm, double tol);
void resol (Matriu& A, Vector& x, Vector& b, int n, Vector& perm);

//   A: matriu A
//   X: matriu candidata a ser la inversa d'A
//   n: dimensió de la matriu
// tol: tolerància admesa sobre els pivots per decidir si la matriu A és singular o no

//~ void swap(double& a, double& b) {
    //~ double c = a;
    //~ a = b;
    //~ b = c;
//~ }

//~ void transpose(Matriu& A) {
    //~ for (int i = 0; i < (int)A.size(); ++i) {
        //~ for (int j = i+1; j < (int)A[0].size(); ++j) swap(A[i][j],A[j][i]);
    //~ }
//~ }

void zeros(Vector& v) {
    for (int i = 0; i < (int)v.size(); ++i) v[i] = 0;
}

void inversa (Matriu& A, Matriu& X, int n, double tol) {
	
	// DESCOMPOSICIÓ LU

	/** Declaració moderna del vector de permutacions. */
	Vector perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;
	/** La variable p indica 0 si la matriu A és singular. */
	int p = lu(A, n, perm, tol);
	if (p == 0) return;

	// RESOLUCIÓ DE N SISTEMES

	/** Resolem el sistema per cada vector de la base canònica i posem els resultats a X. */
	Vector b(n, 0);
    Vector x(n, 0);
	for (int i = 0; i < n; ++i) {
		b[i] = 1;
		resol(A, x, b, n, perm);
        X[i] = x;
        zeros(x);
		b[i] = 0;
	}
    //~ transpose(X);
}
