# include <bits/stdc++.h>
//TEMPLATE
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);
    int ct = 0;
    // find greedy match
    for (int i = 0; i < w.size(); ++i) {
        for (int j = 0; j < w[0].size(); ++j) {
            if (w[i][j] && mc[j] == -1) {
                mc[j] = i;
                mr[i] = j;
                ct++;
                break;
            }
        }
    }
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (mr[i] == -1 && FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

bool dfs(vector<vi> &r, vector<vi> &g, int x, int y, int c) {
    queue<pii> q;
    q.push({x, y});
    vector<pii> dir = {{0,  1},
                       {0,  -1},
                       {1,  0},
                       {-1, 0}};
    r[x][y] = c;
    bool edge = false;
    vector<pii> passed;
    passed.push_back({x, y});
    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        int x2 = top.first;
        int y2 = top.second;
        if (x2 == 0 || y2 == 0 || x2 == r.size() - 1 || y2 == r[0].size() - 1) {
            edge = true;
        }
        for (pii d: dir) {
            int x3 = top.first + d.first;
            int y3 = top.second + d.second;
            if (x3 >= 0 && y3 >= 0 && x3 < r.size() && y3 < r[0].size()) {
                if (r[x3][y3] == -1 && g[x3][y3] == g[top.first][top.second]) {
                    r[x3][y3] = c;
                    q.push({x3, y3});
                    passed.emplace_back(x3, y3);
                }
            }
        }
    }
    if (edge) {
        for (auto &p: passed) {
            if (r[p.first][p.second] == c) {
                r[p.first][p.second] = -2;
            }
        }
    }
    // return true if this region touches the edge
    return edge;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = (int) (s[j] - '0');
        }
    }
    // first: label all regions
    vector<vi> regions(n, vi(m, -1));
    int ans = 0;
    int c0 = 0;
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (regions[i][j] == -1) {
                if (a[i][j] == 1) {
                    if (dfs(regions, a, i, j, c1)) {
                        ans++;
                    } else {
                        c1++;
                    }
                } else {
                    if (dfs(regions, a, i, j, c0)) {
                        ans++;
                    } else {
                        c0++;
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cerr << regions[i][j] << " ";
        }
        cerr << "\n";
    }*/
    // construct graph
    vector<vi> adj(c0, vi(c1, 0));
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            if (a[i][j] != a[i + 1][j]) {
                int rj = regions[i][j];
                int rj1 = regions[i + 1][j];
                if (rj != -2 && rj1 != -2) {
                    if (a[i][j] == 0) {
                        adj[rj][rj1] = 1;
                    } else {
                        adj[rj1][rj] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size() - 1; ++j) {
            if (a[i][j] != a[i][j + 1]) {
                int rj = regions[i][j];
                int rj1 = regions[i][j + 1];
                if (rj != -2 && rj1 != -2) {
                    if (a[i][j] == 0) {
                        adj[rj][rj1] = 1;
                    } else {
                        adj[rj1][rj] = 1;
                    }
                }
            }
        }
    }

    vi r(c0, -1);
    vi r2(c1, -1);
    int match_size = 0;
    if (c0 != 0 && c1 != 0) {
        match_size = BipartiteMatching(adj, r, r2);
    }
    ans = ans + match_size;
    cout << ans << endl;
    return 0;
}
