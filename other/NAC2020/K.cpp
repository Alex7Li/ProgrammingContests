# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef vector<int> vi;
#define sz(x) (int)(x).size()

/*
BinaryLifting.h
Description: Calculate power of two jumps in a tree, to support fast upward
jumps and LCAs. Assumes the root node points to itself.
Time: construction O (N log N), queries O (log N)
 */
vector<vi> treeJump(vi &P) {
    int on = 1, d = 1;
    while (on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i, 1, d) rep(j, 0, sz(P))jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
    return jmp;
}

int jmp(vector<vi> &tbl, int nod, int steps) {
    rep(i, 0, sz(tbl))if (steps & (1 << i)) nod = tbl[i][nod];
    return nod;
}

int lca(vector<vi> &tbl, vi &depth, int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = sz(tbl); i--;) {
        int c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
    return tbl[0][a];
}
// end binary lifting

void makeDepth(vector<vi> &edge, int cur, int prev, vi &parent, vi &depth) {
    parent[cur] = prev;
    depth[cur] = depth[prev] + 1;
    for (auto v: edge[cur]) {
        if (v != prev) {
            makeDepth(edge, v, cur, parent, depth);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vi> edge(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int root = 0;
    vi parent(n);
    vi depth(n);
    makeDepth(edge, root, root, parent, depth);
    vector<vi> tbl = treeJump(parent);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int l = lca(tbl, depth, a, b);
        ll d = depth[a] + depth[b] - 2 * depth[l] + 1;
        ll ans = (d * (d - 1)) / 2LL + n;
        cout << ans << "\n";
    }
    return 0;
}