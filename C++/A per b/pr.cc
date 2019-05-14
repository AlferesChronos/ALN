// pr.cc
// Calcula el producte c = A*b de la matriu A (nxn) pel vector b (nx1).

int pr(double **a, double *b, double *c, int n)
{
  int i,j;
  for (i=0; i< n; i++) {
    c[i] = 0.0e0;
    for (j=0; j<n; j++)
      c[i] += a[i][j]*b[j];
  }
  return -1;
}
