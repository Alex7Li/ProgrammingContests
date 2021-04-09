# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
# define MOD 1000000007

bool ok(int i, int j) {
    if (i > 0 && j > 0 && i < 3 && j < 3) {
        return true;
    }
    return false;
}

ll choose(ll n, ll k) {
    ll p = 1;
    for (int i = k + 1; i <= n; ++i) {
        p *= i;
    }
    for (int i = 1; i <= n - k; i++) {
        p /= i;
    }
    return p;
}

ll dfs(vector<vi> &graph, int st, int k,
       vector<int> &seen) {
    ll ways = 0;
    set<int> banned;
    int next = -1;
    trav(nxt, graph[st]) {
        if (seen[nxt] != 0) {
            banned.insert(nxt);
        } else {
            next = nxt;
        }
    }
    for (int i = 1; i <= k; i++) {
        seen[st] = i;
        if (banned.find(i) == banned.end()) {
            trav(next, graph[st]) {
                ways += next == -1 ? 1 : dfs(graph, next, k, seen);
            }
        }
    }
    seen[st] = 0;
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<vi> grid(3, vi(3, -1));
        int ind = 0;
        rep(i, 0, 3) {
            string s;
            cin >> s;
            rep(j, 0, 3) {
                if (s[j] == 'x') {
                    grid[i][j] = ind++;
                }
            }
        }
        vector<vi> g;
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                if (grid[i][j] != -1) {
                    vi v;
                    if (ok(i - 1, j) && grid[i - 1][j] != -1) {
                        v.push_back(grid[i - 1][j]);
                    }
                    if (ok(i - 2, j) && grid[i - 2][j] != -1) {
                        v.push_back(grid[i - 2][j]);
                    }
                    if (ok(i, j - 1) && grid[i][j - 1] != -1) {
                        v.push_back(grid[i][j - 1]);
                    }
                    if (ok(i, j - 2) && grid[i][j - 2] != -1) {
                        v.push_back(grid[i][j - 2]);
                    }
                    if (ok(i + 1, j) && grid[i + 1][j] != -1) {
                        v.push_back(grid[i + 1][j]);
                    }
                    if (ok(i + 2, j) && grid[i + 2][j] != -1) {
                        v.push_back(grid[i + 2][j]);
                    }
                    if (ok(i, j + 1) && grid[i][j + 1] != -1) {
                        v.push_back(grid[i][j + 1]);
                    }
                    if (ok(i, j + 2) && grid[i][j + 2] != -1) {
                        v.push_back(grid[i][j + 2]);
                    }
                    g.push_back(v);
                }
            }
        }
        ll ans = 0;
        rep(k, 1, g.size()) {
            vi seen = vector<int>(g.size(), 0);
            ans = (ans + choose(n, k) * dfs(g, 0, k, seen)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}

