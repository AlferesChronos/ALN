#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define b "inputb"

int inverse(int n,double **a) {
    ofstream of;
    for (int i = 0; i < n; ++i) {
        string file = b.append(to_string(i));
        of.open(b,ofstream::out);
        of << 1 << endl;
        of << i << ' ' << 1 << endl;
        of.close();
    }
}
