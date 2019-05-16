#ifndef funcions_h
#define funcions_h

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;
typedef vector <double> vec;
typedef vector <vec> matriu;

const double epsilon = 1e-12;
const double INF = 1.0/0.0;

// returns the index of the row to be swapped (using scaled partial pivoting)
int pivoting (matriu& A, int index);

// Completes the "row -th" step of the method of Gauss 
void Gauss (matriu& A, int row);

// Decomposes a matriu A in the PA = LU form
int lu (matriu& A, vector <int>& perm);

// Given a matriu A and b returns x such that Ax = b
vec solve(matriu A, vec b);

// Given a matriu A returns its inverse
matriu inverse(matriu A);

double determinant(matriu A);

matriu multiply(matriu A, matriu B);

// it expresses a vector as a matriu (column vector)
matriu transform(vec b);

matriu add (matriu A, matriu B);

matriu subtract (matriu A, matriu B);

matriu transpose(matriu A);

double norm_one(matriu A);

double norm_inf(matriu A);

double norm_two(vec b);

double condition_one(matriu A);

double condition_inf(matriu A);

void print_matriu(matriu A);

void print_matlab(matriu A);

matriu identity(int n);

double norm_one_vector (vec b);

#endif
