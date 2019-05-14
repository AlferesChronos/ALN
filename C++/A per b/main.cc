// main.cc
// Llegeix la matriu A i el vector b d'un fitxer, calcula el producte c=
// A*b i escriu el vector c en un altre fitxer. El nom del fitxer de dades
// s'ha passa com a paràmetre a la línia de comandes en executar el
// programa, i.e.,
//
// ~/sessio2$ ./main fitxer_amb_les_dades

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>

#define FOUT "out.txt"

// capçeleres de les funcions que es criden des de la funció main.
double *vector(int);
int esborraVector(double *);
double **matriu(int,int);
int esborraMatriu(double **, int);
int pr(double **, double *, double *, int);

using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 2) { // comprovem que hem indicat el nom del fitxer a la
                  // de comandes. En cas contrari, escriu un missatge
                  // d'error i surt del programa.
    cerr << "Error. Cal el fitxer amb les dades!" << endl;
    cerr << "Ús: main fitxer_amb_les_dades" << endl;
    exit (-1);
  }
  ifstream fitxerDades; // declarem fitxerDades com un objecte de la
                        // classe ifstream.

  fitxerDades.open(argv[1],ifstream::in); //obrim el fitxer per llegir.

  if (fitxerDades.fail()) { // comprovem que hem pogut obrir el fitxer
                            // per llegir la matriu i el vector. Si no,
                            // escriu un missatge d'error i es surt del
                            // programa.
    cerr << "Error. No s'ha pogut obrir el fitxer de dades." << endl;
    exit (-1);
  }

  // Lectura del fitxer de dades.
  int n,m,i,j;
  fitxerDades >> n;        // llegim les dimensions de la matriu i el
  fitxerDades >> m;        // nombre de components diferents de 0.
                           // Suposem que la matriu a és n x n i que
                           // el vector b té n components.

  cout << scientific << setprecision(9);

  cout << n << endl;
  cout << m << endl;

  double **a=matriu(n,n);  // declarem la matriu a. Cridem la funció
                           // matriu, definida al fitxer matrius.cc per
                           // a reservar espai en memòria. Nota: aquesta
                           // línia és equivalent a:
                           // double **a;
                           // a=matriu(n,n);

  for (int k=0; k<m; k++) { // llegim les components de la matriu a.
    fitxerDades >> i >> j >> a[i][j];
    cout << setw(4) << i << setw(4) << j << setw(18) << a[i][j] << endl;
  }

  fitxerDades >> m;        // llegim el nombre de components del vector b
                           // que són diferents de 0.
  cout << m << endl;

  double *b=vector(n);     // declarem el vector b. Cridem la funció
                           // vector, definida al fitxer matrius.cc per a
                           // reservar espai en memòria. Nota: aquesta
                           // línia és equivalent a:
                           // double *b;
                           // b=vector(n);

  for (int k=0; k<m; k++) { // llegim les components del vector b
    fitxerDades >> i >> b[i];
    cout << setw(4) << setw(4) <<  i << setw(18) << b[i] << endl;
  }

  fitxerDades.close(); // tanquem el fitxer de dades.

  // Producte c=A*b
  double *c=vector(n);     // declarem el vector c. Cridem la funció
                           // vector, definida al fitxer matrius.cc per a
                           // reservar espai en memòria. Nota: aquesta
                           // línia és equivalent a:
                           // double *c;
                           // c=vector(n);

  pr(a,b,c,n); //cridem a la funció pr que calcula el producte.

  ofstream fitxerResultats; // declarem fitxerResultats com un objecte
                            // de classe ifstream.

  fitxerResultats.open(FOUT,ofstream::out);
  if (fitxerResultats.fail()) { // comprovem que hem pogut obrir l'arxiu
                                // per a escriure el vector c. Si no,
                                // escriu un missatge d'error i surt del
                                // programa.
    cerr << "Error. No s'ha pogut obrir el fitxer per escriure." << endl;
    exit (-1);
  }

  // Sortida dels resultats. Escriptura a un altre fitxer.

  fitxerResultats << scientific << setprecision(15);
  for (i=0; i <n; i++)
    fitxerResultats << setw(4) << i << setw(24) << c[i] << endl;

  esborraMatriu(a,n); //Alliberem la memòria que havíem reservat per a la
  esborraVector(b);   //matriu i els vectors.
  esborraVector(c);

  fitxerResultats.close(); // Tanquem el fitxer on hem guardat els resultats.

  return 0;
}
