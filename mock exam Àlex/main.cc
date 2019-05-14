#include <vector>  // classe vector
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matriu;

double res_Inf (Matriu& R, int n);
double res_1 (Matriu& R, int n);
void inversa(Matriu& A, Matriu& X, int n, double tol);
Matriu product(Matriu& A, Matriu& B);

#define tol  10E-5

void examen(Matriu& A, Matriu& invA, int n) {
    ofstream test;
    test.open("cond.txt",ofstream::out);
    //double r1A= res_1(A, n),r1i= res_1(invA, n),riA = res_Inf(A, n),rii = res_Inf(invA, n);
    //cout << r1A << endl << r1i << endl << riA << endl << rii << endl;
    double cond_1 = res_1(A, n)*res_1(invA, n);
    //cout << cond_1 << endl;
    double cond_Inf = res_Inf(A, n)*res_Inf(invA, n);
    //cout << cond_Inf << endl;
    test << scientific << setprecision(15);
    test << "Nombre de condició:" << endl << "-Norma 1: " << cond_1 << endl << "-Norma infinit: " << cond_Inf << endl;
    test.close();
}

int main(int argc, char *argv[]) {
    /** Declarem fitxerDades com un objecte de la classe ifstream. */
	ifstream fitxerDades; 

	/** Obrim el fitxer per llegir. */
	fitxerDades.open(argv[1], ifstream::in);

	/** Comprovació que s'ha pogut obrir el fitxer. */
	if (fitxerDades.fail()) { 
		cerr << "Hi ha un error: no s'ha pogut obrir el fitxer de dades." << endl;
		exit (-1);
	}

	// LECTURA DE LES DADES

	// n: dimensió de la matriu A (nxn) i de b (nx1).
	// m: número de components diferents de 0 de la matriu A.
	int n, m;
	fitxerDades >> n >> m;

	/** Declaració moderna d'una matriu. */
	Matriu A(n, Vector(n, 0));

	/** Llegim i guardem els components de la matriu A.  */
	int i, j;
	for (int k = 0; k < m; ++k) fitxerDades >> i >> j >> A[i][j];
    fitxerDades.close();
    
    Matriu invA(n, Vector(n, 0));
    inversa(A, invA, n, tol);
    Matriu P = product(A,invA);
    cout << res_Inf(P, n) << endl;
    examen(A, invA, n);
}
