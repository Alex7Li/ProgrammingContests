# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void print_grid(vector<vector<char>> &g) {
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            cout << g[i][j];
        }
        cout << endl;
    }
}
void solve(int n, int m, int k) {
    vector<vector<char>> g(n, vector<char>(m, 'z'));
    char l1 = 'a', l2 = 'b';
    int r = 0, c = 0;
    if (n % 2 == 1) {
        r++;
        for (int i = 0; i + 1 < m; i += 2) {
            g[0][i] = l1;
            g[0][i + 1] = l1;
            k--;
            swap(l1, l2);
        }
    }
    assert((n - r) % 2 == 0);
    bool pos = true;
    if (k < 0 || k % 2 != 0 || (k > 0 && m == 1)) {
        pos = false;
    } else {
        l1 = 'c', l2 = 'd';
        while (k != 0) {
            if (c + 1 >= m) {
                c = 0;
                r += 2;
                l1 = 'c', l2 = 'd';
            }
            if (r + 1 >= n) {
                pos = false;
                break;
            }
            g[r][c] = g[r][c + 1] = l1;
            g[r + 1][c] = g[r + 1][c + 1] = l2;
            k -= 2;
            c += 2;
            swap(l1, l2);
        }
        l1 = 'e', l2 = 'f';
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'z') {
                    char out = (i / 2 + j) % 2 ? l1 : l2;
                    g[i][j] = g[i + 1][j] = out;
                }
            }
        }
    }
    if (pos) {
        cout << "YES" << endl;
        print_grid(g);
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
    }
//    for (int n = 2; n < 100; ++n) {
//        for (int m = 1; m < 100; ++m) {
//            if (n * m % 2 == 1) {
//                continue;
//            }
//            for (int k = 0; k <= (n * m) / 2; ++k) {
//                cout << n << " " << m << " " << k << endl;
//                solve(n, m, k);
//            }
//        }
//    }
    return 0;
}