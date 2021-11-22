# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll search(int start, vector<vi> &adj, vi &army) {
    // (-size, index)
    priority_queue<pii> Q;
    vector<bool> seen(army.size());
    ll count = 0;
    Q.push({-army[start], start});
    while (!Q.empty()) {
        pii cur = Q.top();
        Q.pop();
        if (!seen[cur.second] && (-cur.first < count || cur.second == start)) {
            seen[cur.second] = true;
            count -= cur.first;
            for (auto nxt: adj[cur.second]) {
                Q.push({-army[nxt], nxt});
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N;
    cin >> M;
    vector<vi> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi size(N);
    for (int i = 0; i < N; ++i) {
        cin >> size[i];
    }
    ll ans = search(0, adj, size);
    cout << ans << "\n";
    return 0;
}