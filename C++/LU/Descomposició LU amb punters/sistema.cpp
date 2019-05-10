using namespace std;

int lu(double **,int,int *,double);
void resol(double **,double *,double *,int,int *);

int sistema(double **a, double *x, double *b, int n, double tol) {
	int *perm = new int[n];
	for (int i = 0; i < n; ++i) perm[i] = i;
	int sing = lu(a,n,perm,tol);
    if (sing == 0) return 0;
    resol(a,x,b,n,perm);
	return sing;
}
