# include <bits/stdc++.h>
//
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef vector<int> vi;
const int INF = 1e9 + 5;

ll solve(int n, vector<vector<int>> &adj,
         int q, vi &u, vi &v, vi &l) {
    vector<vector<int>> d = adj;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // edge i->j must have weight M[i][j] or less to be useful
    vector<vi> M(n, vi(n, 0));
    for (int i = 0; i < q; ++i) {
        M[u[i]][v[i]] = l[i];
        M[v[i]][u[i]] = l[i];
    }
    // https://codeforces.com/blog/entry/88963?#comment-774185
    vector<vi> M2 = M;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                M2[i][k] = max(M2[i][k], M[i][j] - d[k][j]);
            }
        }
    }
    vector<vi> M3 = M2;
    for (int s = 0; s < n; ++s) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                M3[s][k] = max(M3[s][k], M2[i][k] - d[s][i]);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj[i][j] <= M3[i][j]) {
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> adj(n, vi(n, INF));
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    rep(i, 0, n) {
        adj[i][i] = 0;
    }
    int q;
    cin >> q;
    vi u(q);
    vi v(q);
    vi l(q);
    rep(i, 0, q) {
        cin >> u[i] >> v[i] >> l[i];
        u[i]--;
        v[i]--;
    }
    cout << solve(n, adj, q, u, v, l) << "\n";
    return 0;
}