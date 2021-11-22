# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 998244353;

ll solve(vector<vector<bool>> &g, vector<ll> inv2pow) {
    ll count = 0;
    for (int i = 0; i < g.size(); ++i) {
        int streak = 1;
        ll last = 0;
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j]) {
                streak++;
                count = (count + last) % MOD;
                if (streak % 2 == 0) {
                    last += inv2pow[streak];
                } else {
                    last -= inv2pow[streak];
                }
                last = last % MOD;
            } else {
                streak = 1;
                last = 0;
            }
        }
    }
    return (count + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(m, false));
    vector<vector<bool>> gT(m, vector<bool>(n, false));
    int ok = 0;
    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        for (int j = 0; j < m; ++j) {
            if (c[j] == 'o') {
                g[i][j] = true;
                gT[j][i] = true;
                ok++;
            }
        }
    }
    vector<ll> inv2pow(n + m + 1);
    inv2pow[0] = 1;
    for (int i = 1; i <= n + m; i++) {
        inv2pow[i] = (inv2pow[i - 1] * 499122177) % MOD;
    }
    ll ways = (solve(g, inv2pow) + solve(gT, inv2pow)) % MOD;
    for (int i = 0; i < ok; i++) {
        ways = (ways * 2) % MOD;
    }
    cout << ways;
    return 0;
}