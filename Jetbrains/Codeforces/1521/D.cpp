# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dfs(vector<unordered_set<int>> &adj, int root, vector<bool> &seen) {
    seen[root] = true;
    for (int nxt: adj[root]) {
        if (!seen[nxt]) {
            return dfs(adj, nxt, seen);
        }
    }
    return root;
}


void remove_adj2(vector<unordered_set<int>> &adj, vector<unordered_set<int>> &adj2, int e, queue<int> &rem) {
    if (adj[e].size() <= 2) {
        for (auto it2 = adj2[e].begin(); it2 != adj2[e].end();) {
            int nxt = *it2;
            adj2[nxt].erase(e);
            it2 = adj2[e].erase(it2);
            if (adj2[nxt].size() <= 1) {
                rem.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<unordered_set<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x - 1].insert(y - 1);
            adj[y - 1].insert(x - 1);
        }
        // forest of nodes with degree at least 3
        vector<unordered_set<int>> adj2(n);
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() > 2) {
                for (auto e: adj[i]) {
                    if (adj[e].size() > 2) {
                        adj2[i].insert(e);
                    }
                }
            }
        }
        queue<int> rem;
        for (int i = 0; i < n; ++i) {
            if (adj2[i].size() <= 1) {
                rem.push(i);
            }
        }
        vector<pii> removals;
        while (!rem.empty()) {
            int st = rem.front();
            rem.pop();
            // remove from this degree 3 node, starting with other degree 3 nodes
            for (auto it = adj2[st].begin(); it != adj2[st].end() && adj[st].size() > 2;) {
                int e = *it;
                removals.emplace_back(e, st);
                // remove the edge
                adj[st].erase(e);
                adj[e].erase(st);
                it = adj2[st].erase(it);
                adj2[e].erase(st);
                remove_adj2(adj, adj2, e, rem);
                if (adj2[e].size() <= 1) {
                    rem.push(e);
                }
            }
            remove_adj2(adj, adj2, st, rem);
            // remove any extra edges
            for (auto it = adj[st].begin(); adj[st].size() > 2;) {
                removals.emplace_back(*it, st);
                adj[*it].erase(st);
                it = adj[st].erase(it);
                assert(it != adj[st].end());
            }
        }
        vector<pii> components;
        vector<bool> seen(n, false);
        for (int i = 0; i < n; ++i) {
            assert(adj[i].size() <= 2);
            if (adj[i].size() <= 1 && !seen[i]) {
                int end = dfs(adj, i, seen);
                components.emplace_back(i, end);
            }
        }
        vector<pii> adds(components.size() - 1);
        for (int i = 0; i < components.size() - 1; ++i) {
            adds[i] = {components[i].second, components[i + 1].first};
        }
        assert(adds.size() == removals.size());
        cout << adds.size() << "\n";
        for (int i = 0; i < adds.size(); ++i) {
            cout << removals[i].first + 1 << " " << removals[i].second + 1 << " " <<
                 adds[i].first + 1 << " " << adds[i].second + 1 << "\n";
        }
    }
    return 0;
}