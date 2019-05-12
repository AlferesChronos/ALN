#include <vector>   // classe vector
using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/* Capçaleres de les funcions (estan implementades en altres arxius). */
double res_Inf (Matriu& R, int n);
Matriu product (const Matriu& A, const Matriu& B);


void residu (Matriu& A, Matriu& X, Matriu& Id, int n, double resInf) {

	// CÀLCUL DE R = AX-Id 
	
	Matriu R(n, Vector(n));
    
	Matriu P = product(A, X);
    
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) R[i][j] = P[i][j] - Id[i][j];
	}

	// NORMA SUBINFINIT DEL RESIDU
	resInf = res_Inf(R, n);
}
