# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pil;
typedef vector<int> vi;

ll dfs(int st, int from, vector<vector<pii>> &edges) {
    ll up = 0;
    ll maxIn = 0;
    ll sumIn = 0;
    ll cost = 0;
    trav(next, edges[st]) {
        if (next.first != from) {
            maxIn = max(maxIn, 0LL + next.second);
            sumIn += next.second;
            cost += dfs(next.first, st, edges);
        } else {
            maxIn = max(maxIn, 0LL + next.second);
            sumIn += next.second;
            up = next.second;
        }
    }
    ll costD = maxIn * 2 - sumIn;
    if (costD < 0) {
        costD = sumIn % 2;
    }
    /*
    cost += sumIn + up;
    ll unmatched = maxIn - (sumIn - maxIn);
    if (unmatched < 0) {
        unmatched = sumIn % 2;
    }
    ll matched = sumIn - unmatched;
    cost -= matched;
    cost -= min(up, unmatched);
    */
    return cost + costD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pii>> edges(n);
    rep(i, 0, n - 1) {
        int u, v, p;
        cin >> u >> v >> p;
        edges[u].push_back(pii(v, p));
        edges[v].push_back(pii(u, p));
    }
    ll score = dfs(0, 0, edges);
    cout << score/2 << endl;
    return 0;
}