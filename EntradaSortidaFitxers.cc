#include <iostream> // variables cout, cin, cerr, ...
#include <fstream>  // classes ifstream, ofstream, ...
#include <iomanip>  // setprecision
#include <vector>   // classe vector

using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;
typedef vector<Vector> Matriu;

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

	// Fem el mateix pel vector b, 
    // ATENCIÓ: En algunes pràctiques el vector és opcional
	
    /**  m: número de components diferents de 0 del vector b. */
	fitxerDades >> m;
	
	Vector b(n, 0);

	/** Llegim i guardem els components del vector b. */
	for (int k=0; k<m; k++) fitxerDades >> i >> b[i];

	/** Tanquem el fitxer de dades. */
	fitxerDades.close();
	
	
	// ESCRIPTURA DELS RESULTATS PER CONSOLA
  
    /** Precisió */
    cout << scientific << setprecision(15);
    
	/** Ja saps com, amb cout << */
    cout << "Exemple: " << A[0][0] << " " << b[0] << endl;

	// ESCRIPTURA DELS RESULTATS EN UN FITXER

	/** Declarem fitxerResultats com un objecte de classe ifstream. */
	ofstream fitxerResultats; 

	/** Obrim el fitxer per escriure. */
	fitxerResultats.open("NomExemple.txt",ofstream::out);

	/** Comprovació que s'ha pogut obrir el fitxer. */
	if (fitxerResultats.fail()) { 
		cerr << "Hi ha un error: no s'ha pogut obrir el fitxer per escriure." << endl;
		exit (-1);
	}

	/** Sortida dels resultats. */
  
    /** Precisió */
	fitxerResultats << scientific << setprecision(15);
  
    /** Aquí el que hagi de sortir, amb fitxerResultats >> */
  
    fitxerResultats << A[0][0] << " " << b[0] << endl;
  
	/** Tanquem el fitxer on hem guardat els resultats. */
	fitxerResultats.close(); 
}
