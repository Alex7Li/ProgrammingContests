# include <bits/stdc++.h>
// Farily hard DP
// https://atcoder.jp/contests/agc046/tasks/agc046_b
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
# define MOD 998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // Ways to build a i by j grid with exactly 1 black in the top row
    vector<vi> ways1Top = vector<vi>(c + 1, vi(d + 1, 0));
    // Ways to build a i by j grid with 0 or many blacks in the top row.
    vector<vi> waysOther = vector<vi>(c + 1, vi(d + 1, 0));
    waysOther[a][b] = 1;
    vi aPow = vi(3001, 1);
    vi amPow = vi(3001, 1);
    for (int i = 1; i < aPow.size(); i++) {
        aPow[i] = (aPow[i - 1] * a) % MOD;
        amPow[i] = (amPow[i - 1] * (a - 1)) % MOD;
    }
    for (int j = b + 1; j <= d; j++) {
        ll locs = j - b;
        ways1Top[a][j] = (amPow[locs - 1] * locs) % MOD;
        waysOther[a][j] = (aPow[locs] - ways1Top[a][j]) % MOD;
    }
    for (int i = a + 1; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            // If we add a new row on top of a [i-1][j] grid, coloring any of the
            // j columns, then the top row has exactly 1 black. This suffices to create
            // all configurations with exactly 1 black, since removing the top row when
            // there is exactly 1 black results in a valid configuraiton.
            ways1Top[i][j] += (j * (ways1Top[i - 1][j] + waysOther[i - 1][j])) % MOD;
            // If we add a new column to the right of a [i][j-1] grid, and color
            // one of the bottom i-1 rows, then we don't change if there is
            // exactly 1 black.
            waysOther[i][j] += ((i - 1) * waysOther[i][j - 1]) % MOD;
            // If we color the top row, though, it will ensure there are more than 1 blacks
            // on the top row.
            waysOther[i][j] += (ways1Top[i][j - 1] + waysOther[i][j - 1]) % MOD;
            ways1Top[i][j] %= MOD;
            waysOther[i][j] %= MOD;
        }
    }
    cout << (waysOther[c][d] + ways1Top[c][d] + 2 * MOD)%MOD << endl;
    return 0;
}