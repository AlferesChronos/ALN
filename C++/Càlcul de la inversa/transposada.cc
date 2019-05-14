#include <vector>  // classe vector
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matriu;

/* Transposa una matriu quadrada M */
void transposa(Matriu& M) {
    
    int n = M[0].size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double aux = M[i][j];
            M[i][j] = M[j][i];
            M[j][i] = aux;
        }
    }
}
