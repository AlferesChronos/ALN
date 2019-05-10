#include <vector> // classe vector
#include <cmath>  // funció abs
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/*
	DESCOMPOSICIÓ LU USANT PIVOTATGE PARCIAL ESGLAONAT
*/

bool pivotatge_parcial_esglaonat (Matriu& A, int k, int n, Vector& perm, int p, const double tol);

//    A: la matriu A
//    n: dimenisió de la matriu 
// perm: vector de permutacions
//  tol: tolerància admesa sobre els pivots per decidir si la matriu A és singular o no
int lu (Matriu& A, int n, Vector& perm, double tol) {

	/** La variable p és 1 si s'ha fet un nombre parell de permutacions i -1 si senar. */
	int p = 1;

	for (int k = 0; k < n; ++k) {
		for (int i = k+1; i < n; ++i) {
			/** Intercanvi de files, retorna 0 si la matriu és singular. */
			if (not pivotatge_parcial_esglaonat(A, k, n, perm, p, tol)) return 0;

			/** Esglaonament, els resultats es guarden a la mateixa matriu A. */
			A[i][k] = A[i][k]/A[k][k];
			for (int j = k+1; j < n; ++j) A[i][j] = A[i][j]-A[i][k]*A[k][j];
		}
	}

	return p;
}

/*  Funció que realitza el pivotatge parcial esglaonat,	és a dir, intercanvia la fila k amb
	max_(k<=i<=n) abs(a_ik/s_i) on s_i = max_(k<=j<=n) abs(a_ij) */ 
//  k: primera fila a considerar
//  p: variable que canvia de signe si s'ha realitzat alguna permutació
bool pivotatge_parcial_esglaonat(Matriu& A, int k, int n, Vector& perm, int p, const double tol) {
	/**   m: valor màxim actual */
	double m = 0;
	/** max: ìndex del valor màxim actual. */
	int max;

	/** Càlcul del màxim. */
	for (int i = k; i < n; ++i) {
		/** Càlcul previ de la s_i. */
		double s = 0;
		for (int j = k; j < n; ++j) if (abs(A[i][j]) > s) s = abs(A[i][j]);

		// Control d'errors: si s = 0, A és singular
		if (s < tol) return false;

		/** Actualització de m i max. */
		if (abs(A[i][k]/s) > m) {m = abs(A[i][k]/s); max = i;}
	}	

	// Control d'errors: si m = 0, A és singular
	if (m < tol) return false;

	/** Permutació, si cal, de les files de la matriu i el vector de permutacions. */
	if (max != k) { 
		swap(A[k], A[max]);
		swap(perm[k], perm[max]);
		p *= -1;
	}

	return true;
}