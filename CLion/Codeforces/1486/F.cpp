# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// i1 != i2
int lca_h(int i1, int i2, vector<vi> &parents, vi &height, vector<vector<pii>> &pairsSeen) {
    if (i1 == i2) {
        pairsSeen[i1].push_back({-1, -1});
        return i1;
    }
    if (height[i1] != height[i2]) {
        if (height[i1] < height[i2]) {
            swap(i1, i2);
        }
        for (int i = parents[i1].size() - 1; i >= 0; i--) {
            if (height[parents[i1][i]] > height[i2]) {
                i1 = parents[i1][i];
                while(i > parents[i1].size()){
                    i--;
                }
            }
        }
        if (parents[i1][0] == i2) {
            pairsSeen[i2].push_back({-1, i1});
            return i2;
        }
        i1 = parents[i1][0];
        assert(height[i1] == height[i2]);
    }
    for (int i = parents[i1].size() - 1; i >= 0; i--) {
        if (parents[i1][i] != parents[i2][i]) {
            i1 = parents[i1][i];
            i2 = parents[i2][i];
            while(i > parents[i1].size()){
                i--;
            }
        }
    }
    if (i1 != i2) {
        int lca = parents[i1][0];
        pairsSeen[lca].push_back({min(i1, i2), max(i1, i2)});
        i1 = lca;
        i2 = lca;
    }
    return i1;

}

void dfs(int ind, vector<vi> &edges, vector<vi> &parents, vi &height) {
    trav(next, edges[ind]) {
        if (height[next] == -1) {
            height[next] = height[ind] + 1;
            parents[next].push_back(ind);
            for (int i = 1; (1 << i) <= height[next]; i++) {
                parents[next].push_back(parents[parents[next][i - 1]][i - 1]);
            }
            dfs(next, edges, parents, height);
        }
    }
}

// Count edges which pass from the parent into this node:
// Any such path ends below or at this node,
// so it's #paths ending below or at - # paths starting below or at.
ll countVertical(int from, vector<vi> &edges, vi &h, vector<ll> &starts, vector<ll> &ends,
              vector<ll> &counts) {
    ll endsMinusStarts = ends[from]-starts[from];
    trav(to, edges[from]) {
        if (h[to] > h[from]) {
            endsMinusStarts +=
                    countVertical(to, edges, h, starts, ends, counts);
        }
    }
    counts[from] = endsMinusStarts;
    return endsMinusStarts;
}

ll countFromVertex(vi &edges, vector<pii> &pairsSeen) {
    map<int, int> timesEdgeSeen;
    trav(e, edges) {
        timesEdgeSeen[e] = 0;
    }
    sort(pairsSeen.begin(), pairsSeen.end());
    ll same = 0;
    ll doubleCount = 0;
    rep(j, 0, pairsSeen.size()) {
        if (pairsSeen[j].second == -1) {
            continue;
        }
        timesEdgeSeen[pairsSeen[j].second]++;
        if (pairsSeen[j].first == -1) {
            continue;
        }
        if (j > 0 && pairsSeen[j] == pairsSeen[j - 1]) {
            same++;
            doubleCount += same - 1;
        } else {
            same = 1;
        }
        timesEdgeSeen[pairsSeen[j].first]++;
    }
    ll count = (pairsSeen.size() * (pairsSeen.size() - 1LL)) / 2LL;
    trav(p, timesEdgeSeen) {
        // don't count pairs which have something in common
        count -= (p.second * (p.second - 1LL)) / 2LL;
    }
    // if two pairs have both things in common, then we just double counted.
    count += doubleCount;
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vi> edges(n, vi(0));
    rep(j, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        edges[--u].push_back(--v);
        edges[v].push_back(u);
    }
    vector<vi> parents(n, vi(0));
    vi height(n, -1);
    height[0] = 0;
    dfs(0, edges, parents, height);
    vector<ll> starts(n);
    vector<ll> ends(n);
    vector<vector<pii>> pairsSeen(n);
    int m;
    cin >> m;
    rep(j, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int la = lca_h(u, v, parents, height, pairsSeen);
        starts[la]++;
        if (la != u && la != v) {
            starts[la]++;
            ends[u]++;
            ends[v]++;
        } else if (la == u) {
            ends[v]++;
        } else {
            ends[u]++;
        }
    }
    vector<ll> counts(n, 0);
    countVertical(0, edges, height, starts, ends, counts);
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        trav(pair, pairsSeen[j]) {
            if (pair.first != -1) {
                counts[pair.first]--;
            }
            if (pair.second != -1) {
                counts[pair.second]--;
            }
        }
        trav(pair, pairsSeen[j]) {
            ans += counts[j];
            if (pair.first != -1) {
                ans -= counts[pair.first];
            }
            if (pair.second != -1) {
                ans -= counts[pair.second];
            }
        }
        trav(pair, pairsSeen[j]) {
            if (pair.first != -1) {
                counts[pair.first]++;
            }
            if (pair.second != -1) {
                counts[pair.second]++;
            }
        }
    }
    rep(i, 0, n) {
        ans += countFromVertex(edges[i], pairsSeen[i]);
    }
    cout << ans << endl;
    return 0;
}
