# include <bits/stdc++.h>
//https://codeforces.com/contest/1302/problem/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<vi> a(n, vi(m, 0));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    vector<int> maxRow = (vi(n, 0));
    vector<int> minCol = (vi(m, INT32_MAX));
    vector<bool> rowDup(n, false), colDup(m, false);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (maxRow[i] == a[i][j]) {
                rowDup[i] = true;
            } else if (maxRow[i] < a[i][j]) {
                rowDup[i] = false;
                maxRow[i] = a[i][j];
            }
            if (minCol[j] == a[i][j]) {
                colDup[j] = true;
            } else if (minCol[j] > a[i][j]) {
                colDup[j] = false;
                minCol[j] = a[i][j];
            }
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] == maxRow[i] && a[i][j] == minCol[j] && !rowDup[i] && !colDup[j]) {
                cout << i + 1 << " " << j + 1 << endl;
                exit(0);
            }
        }
    }
    cout << 0 << " " << 0 << endl;
    return 0;
}