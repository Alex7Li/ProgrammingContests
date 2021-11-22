# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll INF = LLONG_MAX / 16;

bool connected(vector<vi> vector);

ll MST(vector<vector<pii>> &adj) {
    int n = adj.size();
    //weight, to
    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() != n - 1) {
            Q.push({1, i});
        }
    }
    vector<bool> seen(n);
    if (Q.empty()) {
        seen[0] = true;
        for (pii x: adj[0]) {
            Q.push({-x.first, x.second});
        }
    }
    // assume nonexistant weights are 1.
    ll tc = 0;
    while (!Q.empty()) {
        pii cur_edge = Q.top();
        Q.pop();
        if (!seen[cur_edge.second]) {
            for (pii x: adj[cur_edge.second]) {
                Q.push({-x.first, x.second});
            }
            tc -= cur_edge.first;
        }
    }
    return tc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // min edge in fixed MST, number of free outgoing edges, index of min edge
    vector<pair<ll, pii>> w(n, pair<ll, pii>(INF, pii(n - 1, -1)));
    vector<vector<pii>> adj(n);
    ll zor = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w2;
        cin >> u >> v >> w2;
        u--;
        v--;
        if (w[u].first < w2) {
            w[u].first = max(w[u].first, (ll) w2);
            w[u].second.second = v;
        }
        if (w[v].first < w2) {
            w[v].first = max(w[v].first, (ll) w2);
            w[v].second.second = u;
        }
        w[u].second.first--;
        w[v].second.first--;
        zor ^= w2;
        adj[u].push_back({w2, v});
        adj[v].push_back({w2, u});
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [w](int a, int b) {
        return w[a] > w[b];
    });
    int free = count_if(w.begin(), w.end(), [](pair<ll, pii> p) {
        return p.second.first != 0;
    });
    // case 1: First weight is huge, rest are 1
    int uAdd = w[0].second.second;
    int lostFree = w[0].second.first == 1;
    ll wAdd = zor ^((free - lostFree) % 2);
    adj[0].push_back({wAdd, uAdd});
    adj[uAdd].push_back({wAdd, 0});
    ll tc = MST(adj);
    // reset of case 1
    adj[0].pop_back();
    adj[uAdd].pop_back();

    // min edge in fixed MST, number of free outgoing edges, index of min edge
    // vector<pair<ll, pii>> w(n, pair<ll, pii>(INF, pii(n - 1, -1))); ll zor
    // case 2: all weights are in the MST
    if (m > n * (n - 1) / 2 - n) {
        for (int i = 31; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                //todo
            }
        }
    }
    cout << tc;
    return 0;
}

bool connected(vector<vi> &adj) {
    unsigned int n = adj[0].size();
    vector<bool> seen(n, false);
    seen[0] = true;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (auto next : adj[now]) {
            if (!seen[next]) {
                seen[next] = true;
                Q.push(next);
            }
        }
    }
    return all_of(seen.begin(), seen.end(), [](bool x) { return x; });
}
