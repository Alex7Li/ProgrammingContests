# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#include <bits/extc++.h>
//Description: Min-cost max-flow. cap[i][j] != cap[j][i] is allowed; double
//edges are not. If costs can be negative, call setpi before maxflow, but note
//that negative cost cycles are not supported. To obtain the actual flow, look
//at positive values only.
const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;
    MCMF(int N) :
            N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
            seen(N), dist(N), pi(N), par(N) {}
    void addEdge(int from, int to, ll cap, ll cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }
    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0;
        ll di;
        __gnu_pbds::priority_queue<pair<ll, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});
        auto relax = [&](int i, ll cap, ll cost, int dir) {
            ll val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };
        while (!q.empty()) {
            s = q.top().second;
            q.pop();
            seen[s] = 1;
            di = dist[s] + pi[s];
            for (int i : ed[s])
                if (!seen[i])
                    relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            for (int i : red[s])
                if (!seen[i])
                    relax(i, flow[i][s], -cost[i][s], 0);
        }
        rep(i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
    }
    pair<ll, ll> maxflow(int s, int t) {
        ll totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            ll fl = INF;
            for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        rep(i, 0, N) rep(j, 0, N) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }
};

int d(pii p1, pii p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> male(n);
    vector<pii> female(n);
    for (int i = 0; i < n; ++i) {
        cin >> male[i].first >> male[i].second;
    }
    for (int i = 0; i < n; ++i) {
        cin >> female[i].first >> female[i].second;
    }
    MCMF mcmf(2 * (n + 1));
    for (int i = 0; i < n; ++i) {
        mcmf.addEdge(2 * n, i, 1, 0);
        mcmf.addEdge(i + n, 2 * n + 1, 1, 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mcmf.addEdge(i, j + n, 1, d(male[i], female[j]));
        }
    }
    pii flowRes = mcmf.maxflow(2 * n, 2 * n + 1);
    assert(flowRes.first == 2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(mcmf.flow[i][j + n]) {
                cout << (i + 1) << " " << (j + 1) << endl;
            }
        }
    }
    return 0;
}