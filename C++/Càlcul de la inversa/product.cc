#include <vector>   // classe vector
using namespace std;

/* Simplificació del llenguatge i la comprensió del codi. */
typedef vector<double> Vector;
typedef vector<Vector> Matriu;


Matriu product (const Matriu& A, const Matriu& B) {
    
    int n = A[0].size();
    
    Matriu P(n, Vector(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                P[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    
    return P;
}
