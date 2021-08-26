# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> ans;

ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

void solve_scc(vi &scc, vector<vector<pii>> &g) {
    set<int> sccset;
    for (int &i : scc) {
        sccset.insert(i);
    }
    queue<int> Q;
    ll tGCD = 0;
    map<int, ll> dist;
    set<int> seen;
    Q.push(scc[0]);
    seen.insert(scc[0]);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (pii next: g[cur]) {
            if (sccset.find(next.first) != sccset.end()) {// path still in scc
                ll d = dist[cur] + next.second;
                if (seen.find(next.first) != seen.end()) { // already a path
                    tGCD = gcd(tGCD, d - dist[next.first]);
                } else {
                    Q.push(next.first);
                    seen.insert(next.first);
                }
                dist[next.first] = d;
            }
        }
    }
    for (int i : scc) {
        ans[i] = tGCD;
    }
}

// code from kactl
vi val, comp, z, cont;
int Time, ncomps;

template<class G>
int dfs(int j, G &g) {
    int low = val[j] = ++Time, x;
    z.push_back(j);
    for (auto e : g[j])
        if (comp[e.first] < 0)
            low = min(low, val[e.first] ?: dfs(e.first, g));
    if (low == val[j]) {
        do {
            x = z.back();
            z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        solve_scc(cont, g);
        cont.clear();
        ncomps++;
    }
    return val[j] = low;
}

void scc(vector<vector<pii>> &g) {
    int n = g.size();
    val.assign(n, 0);
    comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i, 0, n) if (comp[i] < 0) dfs(i, g);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].push_back({b, l});
    }
    ans = vector<ll>(n + 1);
    scc(g);
    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int v, s, t;
        cin >> v >> s >> t;
        ll total_gcd = gcd(t, ans[v]);
        if (s % total_gcd == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}