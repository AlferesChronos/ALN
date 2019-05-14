// matrius.cc

double *vector(int n) {
  // vector: reserva espai en memòria per a un vector de n
  // components reals de doble precisió.
  double *v;
  v = new double [n]();
  return v;
}

double esborraVector(double *v) {
  // esborraVector: allibera l'espai en memòria prèviament
  // reservat per un vector v de n components de doble precisió.
  // Remarca: observem que no cal especificar la dimensió de v.
  delete [](v);
  v=0;
  return 1;
}

double **matriu(int n, int m) {
  // matriu: reserva espai en memòria per a una matriu n x m de
  // doble precisió. Remarca: les files i columnes es comencen a
  // numerar des del 0.
  double **a;
  a = new double* [n]();
  for (int i = 0; i < n; i++)
    a[i] = new double [m]();
  return a;
}

int esborraMatriu(double **a, int n) {
  // esborraMatriu: allibera l'espai en memòria prèviament reservat
  // per a una matriu amb components reals de doble precisió n x m,
  // Remarca: observem que només cal indicar el nombre de files de
  // la matriu.
  if (a != 0) {
    for (int i=n; i-- > 0;)
      if (a[i] != 0) delete [] (a[i]);
    delete [](a);
  }
  a=0;
  return 1;
}
