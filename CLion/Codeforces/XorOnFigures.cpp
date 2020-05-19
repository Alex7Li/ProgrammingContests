# include <bits/stdc++.h>
//https://codeforces.com/contest/1270/problem/I
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, t, n;
    cin >> k;
    n = 1 << k;
    vector<vector<ll>> grid(n, vector<ll>(n, 0ll));
    rep(i, 0, n) {rep(j, 0, n) {
            cin >> grid[i][j];
    }}
    cin >> t;
    vector<long> x(t, 0ll), y(t, 0ll);
    rep(i, 0, t) {
        cin >> x[i] >> y[i];
    }
    for (int i = t - 1; i >= 0; --i) {
        x[i] = (x[i] - x[0] + n) % n, y[i] = (y[i] - y[0] + n) % n;
    }
    rep(loop, 0, k) {
        vector<vector<ll>> newGrid(n, vector<ll>(n, 0ll));
        rep(i, 0, n) {rep(j, 0, n) {rep(p, 0, t) {
                    newGrid[(x[p] + i) % n][(y[p] + j) % n] ^= grid[i][j];
        }}}
        rep(p, 0, t) {
            x[p] = (x[p] << 1) % n, y[p] = (y[p] << 1) % n;
        }
        grid = newGrid;
    }
    int count = 0;
    rep(i, 0, n) { rep(j, 0, n) { count += (grid[i][j] != 0); }}
    cout << count;
    return 0;
}