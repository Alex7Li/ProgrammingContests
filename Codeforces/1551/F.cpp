# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
# define MOD 1'000'000'009LL
# define MAX_SIZE 102

ll waysToChooseK(vi &v, int k) {
    vvi dp(v.size() + 1, vi(v.size(), 0));
    if (k >= dp.size()) {
        return 0;
    }
    for (int i = 0; i < dp[0].size(); ++i) {
        dp[1][i] = v[i];
    }
    for (int i = 2; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            for (int l = 0; l < j; ++l) {
                dp[i][j] = (dp[i][j] + dp[i - 1][l] * v[j]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < dp[k].size(); ++j) {
        ans = (ans + dp[k][j]) % MOD;
    }
    return ans;
}
void dfs(int from, vi &dist, vvi &g, vi &counts) {
    counts[dist[from]]++;
    for (int to : g[from]) {
        if (dist[to] == -1) {
            dist[to] = dist[from] + 1;
            dfs(to, dist, g, counts);
        }
    }
}
ll solve(vvi &g, int root, int k) {
    vi dist(g.size(), -1);
    vvi counts(g[root].size(), vi(g.size(), 0));
    dist[root] = 0;
    for (int i = 0; i < g[root].size(); ++i) {
        dist[g[root][i]] = 1;
        dfs(g[root][i], dist, g, counts[i]);
    }
    ll ans = 0;
    for (int i = 0; i < counts[0].size();) {
        vi d;
        for (int j = 0; j < counts.size(); ++j) {
            if (counts[j][i]) {
                d.push_back(counts[j][i]);
            }
        }
        ans = (ans + waysToChooseK(d, k)) % MOD;
        i++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi a = {2, 3, 4};
    assert(waysToChooseK(a, 2) == 26);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int k, n;
        cin >> n >> k;
        vvi g(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ll ans = 0;
        if (k == 1) {
            ans += n;
        } else if (k == 2) {
            ans += (n * (n - 1)) / 2;
        } else {
            for (int root = 0; root < n; ++root) {
                ans = (ans + solve(g, root, k)) % MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}