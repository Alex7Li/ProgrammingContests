#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
template<class k> // Same as ordered map almost
using ordered_set = __gnu_pbds::gp_hash_table<k, null_type>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<pair<int, ll>> vil;
typedef vector<vil> G;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

int parent(vi& cc, int a){
    if(cc[a] == a) return a;
    return cc[a] = parent(cc, cc[a]);
}

int merge(vi& cc, int a, int b,
    vector<unordered_set<int>>& left,
    vector<unordered_set<int>>& right,
    map<pii, long>& ans,
    ll cost){
    a = parent(cc, a);
    b = parent(cc, b);
    cc[a] = b;
    if(len(left[a]) > len(left[b])) swap(left[a], left[b]);
    if(len(right[a]) > len(right[b])) swap(right[a], right[b]);
    for(int x : left[a]) {
      if(right[b].count(x)) {
        left[a].erase(x);
        right[b].erase(x);
        ans[{left[a], right[b]}] = cost;
      }
    }
    for(int x : right[a]) {
      if(left[b].count(x)) {
        left[b].erase(x);
        right[a].erase(x);
        ans[{left[b], right[a]}] = cost;
      }
    }
    for(int x : left[a]) left[b].insert(x);
    for(int x : right[a]) right[b].insert(x);
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    G graph(n);
    rep(i, 0, m){
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      graph[u].push_back({v, w});
      graph[v].push_back({u, w});
    }
    vector<unordered_set<int>> left_queries;
    vector<unordered_set<int>> right_queries;
    rep(i, 0, n) {
      int a, b;
      left_queries.push_back({a});
      right_queries.push_back({b});
    }
    priority_queue<pli> Q;
    vector<pli> distance(n, {-1, -1});
    for(int i = 0; i < k; i++){
      int x;
      cin >> x;
      x--;
      Q.push({i, x});
      distance[i] = {0, 0};
    }
    while(!Q.empty()) {
      pli p = Q.top();
      Q.pop();
      int w = -p.first;
      int cur = p.second;
      for(auto e : graph[cur]) {
        int next = e.first;
        if(distance[next].first == -1) {
          int dist = -e.second;
          distance[next] = {-(w + dist), distance[cur].second};
          Q.push({w + dist, next});
        }
      }
    }
    G graph2(k);
    vector<pair<long, pii>> graph2_edges;
    vector<ll> ans(n);
    // for each edge in the graph, merge
    // into a spanning tree with cost based
    // on the distance array
    rep(ind1, 0, n) {
      for(pair<int, ll> j: graph[ind1]) {
        int ind2 = j.first;
        ll cost = j.second + distance[ind1].first + distance[ind2].first;
        graph2[distance[ind1].second].push_back({distance[ind2].second, cost});
        graph2_edges.push_back({cost, {distance[ind1].first, distance[ind2].second}});
      }
    }
    sort(graph2_edges.begin(), graph2_edges.end());
    vi cc(n);
    rep(i, 0, n) cc[i] = i;
    for(auto e : graph2_edges) {
      int a = e.second.first;
      int b = e.second.second;
      int pa = parent(cc, a);
      int pb = parent(cc, b);
      if(pa != pb) {
        merge(cc, a, b, left_queries, right_queries);
      }
    }

    return 0;
}