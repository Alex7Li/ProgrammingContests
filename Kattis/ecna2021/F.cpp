// Reduced row echelon form via Gauss-Jordan elimination
// with partial pivoting.  This can be used for computing
// the rank of a matrix.
//
// Running time: O(n^3)
//
// INPUT:    a[][] = an nxm matrix
//
// OUTPUT:   rref[][] = an nxm matrix (stored in a[][])
//           returns rank of a[][]

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// const double EPSILON = 1e-10;

typedef int T;
typedef vector<T> VT;
typedef vector<VT> VVT;

const int p = 37;

VT inverses{0, 1, 19, 25, 28, 15, 31, 16, 14, 33,
            26, 27, 34, 20, 8, 5, 7, 24, 35, 2, 13, 30, 32, 29,
            17, 3, 10, 11, 4, 23, 21, 6, 22, 9, 12, 18, 36};

int rref(VVT &a) {
    int n = a.size();
    int m = a[0].size();
    int r = 0;
    for (int c = 0; c < m - 1 && r < n; c++) {
        int j2 = r;
        for (int i = r + 1; i < n; i++)
            if (a[i][c] > a[j2][c]) j2 = i;
        if (a[j2][c] == 0) continue;
        swap(a[j2], a[r]);

        T s = inverses[a[r][c]];
        for (int j = 0; j < m; j++) a[r][j] = (a[r][j] * s) % p;
        for (int i = 0; i < n; i++)
            if (i != r) {
                T t = a[i][c];
                for (int j = 0; j < m; j++) a[i][j] = (a[i][j] + (p - a[r][j]) * t) % p;
            }
        r++;
    }
    return r;
}

int parse(char c) {
    int ans = -1;
    if (c == ' ') {
        ans = 36;
    } else if ((int) c >= (int) 'A') {
        ans = (int) c - (int) 'A';
    } else if ((int) c <= (int) '9') {
        ans = (int) c - (int) '0' + 26;
    }
    return ans;
}

int main() {
    string nstr, fi, se;
    getline(cin, nstr);
    int n = stoi(nstr);
    getline(cin, fi);
    getline(cin, se);
    const int len = fi.length();
    VT x(len), y(len);
    for (int i = 0; i < len; ++i) {
        x[i] = parse(fi.at(i));
        y[i] = parse(se.at(i));
    }

    bool has_solution = true;
    bool many_solution = false;
    VVT ans(n, VT(n));
    VVT mat(len / n, VT(n + 1));
    for (int out_row = 0; out_row < n; out_row++) {
        for (int i = 0; i < len; ++i) {
            mat[i / n][i % n] = x[i];
        }
        for (int i = 0; i < len / n; i++) {
            mat[i][n] = y[i * n + out_row];
        }
        int rank = rref(mat);
        if(rank < n){
            many_solution = true;
        }
        for (int i = 0; i < min(n, len / n); i++) {
            if (mat[i][i] == 0) {
                many_solution = true;
            }
        }
        for (int i = rank; i < len / n; i++) {
            if (mat[i][n] > 0) {
                has_solution = false;
            }
        }
        for (int i = 0; i < min(len / n, n); i++) {
            ans[out_row][i] = mat[i][n];
        }
    }
    if (!has_solution) {
        cout << "No solution";
    } else if (many_solution) {
        cout << "Too many solutions";
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    cout << '\n';
}