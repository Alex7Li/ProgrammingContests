# include <bits/stdc++.h>
//https://codeforces.com/gym/102511/problem/E
// solved it on the first submission!!
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<set<int>> edges;

struct NECount {
    unsigned int nodes, edges;

    NECount operator+(NECount const &o) {
        return NECount{nodes + o.nodes, edges + o.edges};
    }
};

struct DESigns {
    vector<set<int>> locations;

    string toString() {
        string out = "";
        int count = 0;
        for (unsigned int i = 0; i < locations.size(); i++) {
            for (auto j : locations[i]) {
                count++;
                out.append(to_string(i + 1));
                out.append(" ");
                out.append(to_string(j + 1));
                out.append("\n");
            }
        }
        return to_string(count) + "\n" + out;
    }

    void addSign(int st, int end) {
        assert(locations[st].find(end) == locations[st].end());
        locations[st].insert(end);
    }

    void destroySignsFrom(int st) {
        locations[st].clear();
    }
};

void removeEdge(int a, int b) {
    edges[a].erase(b);
    edges[b].erase(a);
}

/*
 * Given a node with exactly 1 edge from it, remove this node and move roadblocks
 * forwards.
 */
void solve(int cur, DESigns &signs) {
    int nxt = *edges[cur].begin();
    removeEdge(cur, nxt);
    assert(edges[cur].size() == 0);
    signs.destroySignsFrom(cur);
    signs.addSign(nxt, cur);
    if (edges[nxt].size() == 1) {
        solve(nxt, signs);
    } else if (edges[nxt].size() == 0) {
        signs.destroySignsFrom(nxt);
    }
}

/*
 * Return (number of nodes, number of edges) for the connected component
 * containing i.
 */
NECount count(int i, vector<int> &seen) {
    seen[i] = 1;
    NECount ans{1, edges[i].size()};
    trav(nxt, edges[i]) {
        if (!seen[nxt]) {
            NECount c = count(nxt, seen);
            ans = ans + c;
        }
    }
    return ans;
}

/*
 * Update the seen matrix and figure out where you want the dead end signs
 */
void updateSignsAndSeenOnTree(int i, vector<int> &seen, DESigns &signs) {
    assert(seen[i] == 1);
    seen[i] = 2;
    if (edges[i].size() == 1) {
        signs.addSign(i, *edges[i].begin());
    }
    trav(nxt, edges[i]) {
        if (seen[nxt] == 1) {
            updateSignsAndSeenOnTree(nxt, seen, signs);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    edges = vector<set<int>>(n, set<int>());
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        w--;
        edges[v].insert(w);
        edges[w].insert(v);
    }
    // edge case: connected component is tree
    vector<int> seen(n, 0);
    DESigns ans{vector<set<int>>(n)};
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            NECount c = count(i, seen);
            assert(c.edges / 2 + 1 >= c.nodes);
            if (c.edges / 2 + 1 == c.nodes) {
                updateSignsAndSeenOnTree(i, seen, ans);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        assert(seen[i]);
        if (seen[i] == 1 && edges[i].size() == 1) {
            solve(i, ans);
        }
    }
    cout << ans.toString();
    return 0;
}