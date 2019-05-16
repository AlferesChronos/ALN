#include "funcions.h"

using namespace std;

// returns the index of the row to be swapped (scaled partial pivoting)
int pivoting (matriu& A, int index){
	int n = A.size();
    int answer = -1;
    double maximum = -1;

    for (int i = index; i < n; ++i){

    	double maxrow = abs(A[i][index]);
    	for (int j = index + 1; j < n; ++j) maxrow = max(maxrow, abs(A[i][j]));

        double element = abs(A[i][index]/maxrow);

        if (element > maximum){
            maximum = element;
            answer = i;
        }
    }

    return answer;
}


// Completes the "row -th" step of the method of Gauss 
void Gauss (matriu& A, int row){
	int n = A.size();

    for (int i = row + 1; i < n; ++i){
        A[i][row]/=A[row][row];

        for (int j = row + 1; j < n; ++j)
          A[i][j] -= A[i][row] * A[row][j];
    }
}

// Decomposes a in the Pa = LU form
int lu (matriu& A, vector <int>& perm){
	int n = A.size();
    int swaps = 0;

    for (int i = 0; i < n; ++i) perm[i] = i;

    for (int i = 0; i < n - 1; ++i){
        int pivot = pivoting(A, i);

        if (pivot != i){ //girem les files

         	swap(A[i], A[pivot]);
    		swap(perm[i], perm[pivot]);

          	++swaps;
        }

        if (abs(A[i][i]) < epsilon) return 0;
        
        Gauss(A, i);
    }

    return 2*((swaps+1) % 2) - 1;
}

//given A and b computes x such that Ax = b;
vec solve(const matriu& A, const vec& b){
	int n = A.size();
	
	vec x(n, 0);
	vector <int> perm (n, 0);

	matriu LU = A;

	lu(LU, perm);

	// B = Pb
	vec B = vec(n);
	for (int i = 0; i < n; ++i) B[i] = b[perm[i]];

	// Ly = B
	for (int i = 0; i < n; ++i){
		x[i] = B[i];

		for (int j = 0; j < i; ++j){
			x[i] -= x[j]*LU[i][j];
		}
	}

	// Ux = y
	for (int i = n-1; i >= 0; --i){
		for (int j = n-1; j > i; --j){
			x[i] -= x[j]*LU[i][j];
		}

		x[i] /= LU[i][i];
	}

	return x;
}



matriu inverse (const matriu& A){
	int n = A.size();
	vector <int> perm(n, 0);
	matriu LU = A;
	int okay = lu(LU, perm);

	if (not okay) {
		cout << "El determinant es 0, la inversa peta!!" << endl;
		return A;
	}

	matriu inv = A;

    for (int i = 0; i < n; ++i){
    	vec e(n, 0);
    	e[i] = 1;
      
    	inv[i] = solve(A, e);
    }

    return transpose(inv);
}

double determinant(const matriu& A){
	int n = A.size();
	vector <int> perm(n, 0);
	
	matriu LU = A;

	double answer = lu(LU, perm);
	for (int i = 0; i < n; ++i) answer *= LU[i][i];

	return answer;
}

matriu multiply(const matriu& A, const matriu& B){
	int n = A.size(), m = A[0].size(), p = B.size(), q = B[0].size();

	if (m != p) {
		cout << "Les dimensions no quadren!! les matrius son " << n << " x " << m << " i " << p << " x " << q << endl;
		return A;
	}

	matriu ans(n, vec(q, 0));

	for (int i = 0; i < n; ++i){
        for (int j = 0; j < q; ++j){
            for (int k = 0; k < m; ++k) ans[i][j] += A[i][k] * B[k][j];
        }
    }

    return ans;
}

// it expresses a vector as a matriu (column vector)
matriu transform(const vec& b){
	int n = b.size();

	matriu ans(n, vec(1, 0));

	for (int i = 0; i < n; ++i) ans[i][0] = b[i];
	return ans;
}


matriu add (const matriu& A, const matriu& B){ //Given two matrices computes their sum
	int n = A.size(), m = A[0].size(), p = B.size(), q = B[0].size();

	if (n != p or m != q) {
		cout << "Les dimensions no quadren!! les matrius son " << n << " x " << m << " i " << p << " x " << q << endl;
		return A;
	}

    matriu ans = A;

    for (int i = 0; i < p; ++i){
        for (int j = 0; j < q; ++j) ans[i][j] += B[i][j];
    }

    return ans;
}

matriu subtract (const matriu& A, const matriu& B){ //Given two matrices computes their difference
    int n = A.size(), m = A[0].size(), p = B.size(), q = B[0].size();

	if (n != p or m != q) {
		cout << "Les dimensions no quadren!! les matrius son " << n << " x " << m << " i " << p << " x " << q << endl;
		return A;
	}

    matriu ans = A;

    for (int i = 0; i < p; ++i){
        for (int j = 0; j < q; ++j) ans[i][j] -= B[i][j];
    }

    return ans;
}

matriu transpose(const matriu& A){
	int n = A.size(), m = A[0].size();

	matriu ans(m, vec(n));

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			ans[j][i] = A[i][j];
		}
	}

	return ans;
}

double norm_one(const matriu& A){
	int n = A.size(), m = A[0].size();

	double ans = 0;

	for (int i = 0; i < n; ++i){
		double column = 0;
		for (int j = 0; j < m; ++j) column += abs(A[j][i]);

		ans = max(ans, column);
	}

	return ans;
}


double norm_inf(const matriu& A){
	int n = A.size(), m = A[0].size();

	double ans = 0;

	for (int i = 0; i < n; ++i){
		double row = 0;
		for (int j = 0; j < m; ++j) row += abs(A[i][j]);

		ans = max(ans, row);
	}

	return ans;
}

double norm_two(const vec& b){
	double ans = 0;
	int n = b.size();

	for (int i = 0; i < n; ++i) ans += b[i]*b[i];
	return sqrt(ans);
}

double condition_one(const matriu& A){
	return norm_one(A) * norm_one(inverse(A));
}


double condition_inf(const matriu& A){
	return norm_inf(A) * norm_inf(inverse(A));
}

void print_matriu(const matriu& A){
	int n = A.size(), m = A[0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j){
			cout << A[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}

void print_matlab(const matriu& A){
	int n = A.size(), m = A[0].size();

	cout << "A = [";

	for (int i = 0; i < n; ++i) {
		if (i) cout << ";";

		for (int j = 0; j < m; ++j){
			if (j) cout << ",";
			cout << A[i][j];
		}
	}

	cout << "]" << endl;
}

matriu identity(int n){
	matriu ans(n, vec(n, 0));
	for (int i = 0; i < n; ++i) ans[i][i] = 1;
	return ans;
}

double norm_one_vector (const vec& b){
	double ans = 0;
	int n = b.size();
	for (int i = 0; i < n; ++i) ans += abs(b[i]);
	return ans;
}

vec vector_sum (const vec& u, const vec& v) {
	int n = u.size(), m = v.size();
	
	if (n != m) {
		cout << "Les dimensions no quadren!! Les dimensions són " << n << " i " << m << '.' << endl;
		return u;
	}
		
	vec res(n, 0);
	for (int i = 0; i < n; ++i) res[i] = u[i] + v[i];
	
	return res;
}

double trace (const matriu& A) {
	int n = A.size();
	double t = 0;
	for (int i = 0; i < n; ++i) t += A[i][i];
	return t;
}
