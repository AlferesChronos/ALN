#include <vector>   // classe vector
using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/* Capçaleres de les funcions (estan implementades en altres arxius). */
double res_2 (Matriu& R, int n);
double res_Inf (Matriu& R, int n);
void product (const Matriu& A, const Matriu& B, Matriu& P);


void residu (Matriu& A, Matriu& X, Matriu& Id, int n, double res2, double resInf) {

	// CÀLCUL DE R = AX-Id 
	Matriu R(n, Vector(n));
	Matriu P(n, Vector(n));
	product(A,X,P);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) R[i][j] = P[i][j]-Id[i][j];
	}

	// NORMA SUB2 DEL RESIDU
	res2 = res_2(R, n);

	// NORMA SUBINFINIT DEL RESIDU
	resInf = res_Inf(R, n);
}
