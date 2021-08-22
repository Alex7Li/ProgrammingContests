# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 100'000'000;

struct PushRelabel {
    struct Edge {
        int dest, back;
        ll f, c;
    };
    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge *> cur;
    vector<vi> hs;
    vi H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
    void addEdge(int s, int t, ll cap, ll rcap = 0) {
        if (s == t) return;
        g[s].push_back({t, sz(g[t]), 0, cap});
        g[t].push_back({s, sz(g[s]) - 1, 0, rcap});
    }
    void addFlow(Edge &e, ll f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f;
        e.c -= f;
        ec[e.dest] += f;
        back.f -= f;
        back.c += f;
        ec[back.dest] -= f;
    }
    ll calc(int s, int t) {
        int v = sz(g);
        H[s] = v;
        ec[t] = 1;
        vi co(2 * v);
        co[0] = v - 1;
        rep(i, 0, v) cur[i] = g[i].data();
        for (Edge &e : g[s]) addFlow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back();
            hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    for (Edge &e : g[u])
                        if (e.c && H[u] > H[e.dest] + 1)
                            H[u] = H[e.dest] + 1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i, 0, v) if (hi < H[i] && H[i] < v)
                                --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
                    addFlow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }
    bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int w, h;
        cin >> w >> h;
        int d, f, b;
        cin >> d >> f >> b;
        vector<string> grid(h);
        for (int i = 0; i < h; ++i) {
            cin >> grid[i];
        }
        PushRelabel flow(h * w + 2);
        int water = h * w;
        int ground = h * w + 1;
        auto gind = [h](int i, int j) {
            return i + h * j;
        };
        for (int i = 0; i < h; ++i) {
            flow.addEdge(water, gind(i, 0), INF);
            flow.addEdge(water, gind(i, w - 1), INF);
            flow.addEdge(water, gind(i, 0), grid[i][0] == '#' ? 0 : f);
            flow.addEdge(water, gind(i, w - 1), grid[i][w - 1] == '#' ? 0 : f);
        }
        for (int j = 1; j < w - 1; ++j) {
            flow.addEdge(water, gind(0, j), INF);
            flow.addEdge(water, gind(h - 1, j), INF);
            flow.addEdge(water, gind(0, j), grid[0][j] == '#' ? 0 : f);
            flow.addEdge(water, gind(h - 1, j), grid[h - 1][j] == '#' ? 0 : f);
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(grid[i][j] == '#') {
                    flow.addEdge(water, gind(i, j), d);
                } else {
                    flow.addEdge(gind(i, j), ground, f);
                }
                if (i - 1 >= 0) {
                    flow.addEdge(gind(i, j), gind(i - 1, j), b, b);
                }
                if (j - 1 >= 0) {
                    flow.addEdge(gind(i, j), gind(i, j - 1), b, b);
                }
            }
        }
        ll ans = flow.calc(water, ground);
        cout << ans << endl;
    }
    return 0;
}