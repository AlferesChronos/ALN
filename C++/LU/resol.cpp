using namespace std;

double *vector(int);
int eraseVector(double *);
void swap_doubles(double& ,double&);

void resol(double **a, double *x, double *b, int n, int *perm) {
	double *aux = vector(n);
	for (int i = 0; i < n; ++i) aux[i] = b[perm[i]];
	//resolem LUx=Pb en dues parts, Ly=Pb i Ux=y:
    //part triangular inferior, Ly=Pb
    double *y = vector(n);
    y[0] = aux[0];
    for (int i = 1; i < n; ++i) {
		double resy = aux[i];
		for (int j = 0; j < i; ++j) resy -= a[i][j]*y[j];
		y[i] = resy;
	}
    //part triangular superior, Ux=y
    x[n-1] = y[n-1]/a[n-1][n-1];
    for (int i = n-2; i > -1; --i) {
        double resx = y[i];
        for (int j = n-1; j > i; --j) resx -= a[i][j]*x[j];
        resx /= a[i][i];
        x[i] = resx;
    }
    eraseVector(y);
}
