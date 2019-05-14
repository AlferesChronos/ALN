#include <iostream> // variables cout, cin, cerr, ...
#include <fstream>  // classes ifstream, ofstream, ...
#include <iomanip>  // funció setw()
#include <vector>   // classe vector

using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/* Capçaleres de les funcions (estan implementades en altres arxius). */
int inversa (Matriu& A, Matriu& X, int n, double tol);
void residu (Matriu& A, Matriu& X, Matriu& Id, int n, double resInf);

double res_1 (Matriu& R, int n);
double res_Inf (Matriu& R, int n);

/* Variables globals. */
#define FOUT "out.txt"  // Nom del fitxer de sortida.
#define tol  10E-2      // Tolerància admesa.
#define dec_pan 5       // Nombre de decimals quan s'imprimeix per pantalla
#define dec_fit 15      // Nombre de decimals quan es guarden valors en un fitxer

int main (int argc, char *argv[]) {

	// DETECCIÓ D'ERRORS EN L'ENTRADA

	/** Comprovació que s'ha indicat el nom del fitxer amb les dades. */
	if (argc < 2) { 
		cerr << "Hi ha un error: cal indicar el fitxer amb les dades." << endl;
		cerr << "Exemple d'ús: main fitxer_amb_les_dades" << endl;
		exit (-1);
	}

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

	/** Tanquem el fitxer de dades. */
	fitxerDades.close();
	
	/** Comprovació si l'usuari vol calcular l'error associat a la solució */
	bool res = false;
	if (argc > 2 and *argv[2] == '1') {
		res = true;
		
	}
    Matriu A_copia = A;
    
	// RESOLUCIÓ DEL SISTEMA AX=I
	
	/** Declaració moderna de la matriu de solucions X. */
	Matriu X(n, Vector(n, 0));

	/** Es troba la inversa resolent n sistemes lineals, la variable i indica 0 si la matriu A és singular. */
	i = inversa(A, X, n, tol);

	if (i == 0) {
		cerr << "Hi ha un error: la matriu A és singular." << endl;
		exit(-1);
	}

	// CÀLCUL DE LA NORMA DEL RESIDU (sub2 i subinfinit)
	
	/* Creem la matriu identitat de dimensió n per tal de calcular el residu. */
	Matriu Id(n, Vector(n, 0));
	for (int i = 0; i < n; ++i) Id[i][i] = 1;
	
	/* Calculem les normes 2 i infinit del residu. */
	double resInf = 0;
	if (res) residu(A_copia, X, Id, n, resInf);

	// ESCRIPTURA DELS RESULTATS PER CONSOLA

	cout << scientific << setprecision(dec_pan);
	cout << "El resultat és: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ' ' << X[i][j];
		}
		cout << endl;
	}
    
    /** Comprovació que la matriu resultant és la inversa */
	if (res) {
		cout << "Amb les corresponents normes del residu: " << endl;
		cout << "Norma subinfinit: " << resInf << endl;
	}
    
    // CÀLCUL DEL NÚMERO DE CONDICIO SUB1 i SUBinf
    
    cout << "Nombre de condició sub1 de la matriu A: "; 
    cout << res_1(A_copia, n)*res_1(X, n) << endl;
    
    cout << "Nombre de condició subinf de la matriu A: ";
    cout << res_Inf(A_copia, n)*res_Inf(X, n) << endl;

	// ESCRIPTURA DELS RESULTATS EN UN FITXER

	/** Declarem fitxerResultats com un objecte de la classe ofstream. */
	ofstream fitxerResultats; 

	/** Obrim el fitxer per escriure. */
	fitxerResultats.open(FOUT,ofstream::out);

	/** Comprovació que s'ha pogut obrir el fitxer. */
	if (fitxerResultats.fail()) { 
		cerr << "Hi ha un error: no s'ha pogut obrir el fitxer per escriure." << endl;
		exit (-1);
	}

	/** Sortida dels resultats. */
	fitxerResultats << scientific << setprecision(dec_fit);
	for (i = 0; i < n; i++) {
		fitxerResultats << X[i][0];
		for (int j = 0; j < n; ++j) {
			fitxerResultats << ' ' << X[i][j];
		}
		fitxerResultats << endl;
	}

	/** Tanquem el fitxer on hem guardat els resultats. */
	fitxerResultats.close(); 

	// NOTA 1: no cal esborrar els vectors ja que el programa ja s'ha acabat i la memoria s'allibera sola
	// NOTA 2: gràcies al compilador, fer return 0 al final o no fer-lo és el mateix.
}
