# include <bits/stdc++.h>

using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<pair<int, ll>>> WeightedGraph; // (index, time_to_traverse_path)

ll INF = (ll) (1e18) + 100000;

WeightedGraph getResidual(WeightedGraph &g, ll &total_path_len) {
    int n = g.size();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
    Q.push({0, 0});
    WeightedGraph prev(n);
    vector<ll> visitT(n, INF);
    visitT[0] = 0;
    while (!Q.empty()) {
        auto x = Q.top();
        Q.pop();
        ll curT = x.first;
        int nodeInd = x.second;
        if (curT > visitT[nodeInd]) {
            continue; // We have found a shorter path already
        }
        trav(a, g[nodeInd]) {
            int nextInd = a.first;
            ll w = a.second;
            ll endT = curT + w;
            if (endT > visitT[nextInd]) {
                continue; // skip, not better
            }
            if (endT < visitT[nextInd]) {
                prev[nextInd].clear();
                visitT[nextInd] = endT;
                Q.push({endT, nextInd});
            }
            prev[nextInd].push_back({nodeInd, w});
        }
    }
    total_path_len = visitT[n - 1];
    // prev edges are all backwards
    WeightedGraph residual(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < prev[i].size(); ++j) {
            int from = i;
            int to = prev[i][j].first;
            ll w = prev[i][j].second;
            residual[to].push_back({from, w});
        }
    }
    return residual;
}

vector<int> findPaths(WeightedGraph &g, vector<ll> &log) {
    int n = g.size();
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> Q;
    Q.push({0, {1, 0}});
    vector<int> prev(n, -1);
    while (!Q.empty()) {
        auto x = Q.top();
        Q.pop();
        ll curT = x.first;
        int logInd = x.second.first;
        int nodeInd = x.second.second;
        if (log[logInd] == curT) {
            logInd++;
        }
        assert(curT < log[logInd]);
        assert(log[logInd - 1] <= curT);
        trav(a, g[nodeInd]) {
            int nextInd = a.first;
            ll w = a.second;
            ll endT = curT + w;
            if (endT > log[logInd]) {
                continue; // too long to work
            }
            if (prev[nextInd] == -1) {
                prev[nextInd] = nodeInd;
                Q.push({endT, {logInd, nextInd}});
            } else {
                prev[nextInd] = -2; // two or more paths
            }
        }
    }
    return prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    WeightedGraph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, h;
        cin >> u >> v >> h;
        u--;
        v--;
        g[u].push_back({v, h});
    }
    vector<ll> log;
    for (int i = 0; i < d; ++i) {
        ll t;
        cin >> t;
        log.push_back(t);
    }
    log.push_back(-1);
    sort(all(log));
    ll lastT;
    WeightedGraph goodEdges = getResidual(g, lastT);
    if (lastT < log[log.size() - 1]) {
        cout << 0 << "\n";
    } else {
        log.push_back(INF);
        log.push_back(INF);
        vi prev = findPaths(goodEdges, log);

        // If the distance to the last node is less than
        //  the last (non-inf) log entry, then we lose
        // also if there is no path we lose
        if (lastT < log[log.size() - 3] || prev[n - 1] == -1) {
            cout << 0 << "\n";
        } else {
            stack<ll> path;
            int end = n - 1;
            while (end > 0) {
                path.push(end);
                end = prev[end];
            }
            path.push(0);
            if (end == -2) {
                cout << 1 << "\n";
            } else if (end == -3) {
                cout << 0 << "\n";
            } else {
                cout << path.size() << "\n";
                while (!path.empty()) {
                    cout << (path.top() + 1) << "\n";
                    path.pop();
                }
            }
        }
    }
    return 0;
}
