# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
vector<vector<int>> sq;

bool solve(int i, int j) {
    i++;
    if (i == n) {
        i = 0;
        j++;
    }
    vector<bool> ok(n, true);
    rep(z, 0, i) {
        ok[sq[z][j]] = false;
    }
    rep(z, 0, j) {
        ok[sq[i][z]] = false;
    }
    rep(z, 0, n) {
        if (ok[z]) {
            sq[i][j] = z;
            if (j == n-1 && i == n-1) {
                int trace = 0;
                rep(l, 0, n) {
                    trace += sq[l][l] + 1;
                }
                if (trace == k) {
                    return true;
                }
            } else if (solve(i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 1, t + 1) {
        cin >> n >> k;
        cout << "Case #" << tt << ": ";
        sq = vector<vi>(n, vi(n, 0));
        if (solve(-1, 0)) {
            cout << "POSSIBLE" << "\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << sq[i][j] + 1 ;
                    if(j!=n-1){
                        cout << " ";
                    }
                }
                cout << "\n";
            }
        } else {
            cout << "IMPOSSIBLE" << "\n";
        }
    }
    return 0;
}