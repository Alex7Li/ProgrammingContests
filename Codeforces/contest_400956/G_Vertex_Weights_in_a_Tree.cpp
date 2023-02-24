#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

#ifdef LOCAL
#pragma GCC optimize("trapv")  // signed overflow => RE
#else
#pragma GCC target("arch=skylake")  // CF only
#endif

vi find_odd_cycle(vector<vi>& G) {
  queue<pii> Q;
  int n = G.size();
  vector<vi> prev(2, vi(n, -1));
  Q.push({0, 0});
  prev[0][0] = 0;
  while (!Q.empty()) {
    pii cur = Q.front();
    int goal_color = 1 - cur.first;
    for (int next : G[cur.second]) {
      if (prev[goal_color][next] == -1) {
        prev[goal_color][next] = cur.second;
        Q.push({goal_color, next});
      }
    }
    Q.pop();
  }
  if(prev[1][0] == -1){
    return {};
  }
  // We have found an odd cycle.
  deque<int> cycle;
  int type = 1;
  int index = 0;
  do {
    index = prev[type][index];
    cycle.push_back(index);
    type ^= 1;
  } while (index != 0);
  // We have not yet enforced that this cycle is simple.
  while(cycle[0] == cycle[cycle.size() - 2]){
    cycle.pop_front();
    cycle.pop_back();
  }
  vi cycle_nodes(cycle.size());
  for(int i = 0; i < cycle.size(); i++){
    cycle_nodes[i] = cycle[i];
  }
  return cycle_nodes;
}
/*
 If there is a solution, then there is a solution with no
 even cycles. So if there are no odd cycles (bipartite),
 then we can reduce to a tree (by taking bfs edges)
 and then greedily determine if it is possible from the leaves,
 checking for validity at the end.

 Otherwise, there is an odd cycle. Any set of weights is solvable
 for an odd cycle. So we extend tress from each each node in the odd cycle,
 greedily determine what the root of the tree should be to satisfy the
 constraints, and then consturct the solution for the resulting solution.
*/
bool checkEdges(vector<bool>& seen, int st, vi& c, vi& ans,
      map<pii, int>& lookup, vector<vi>& G) {
  queue<int> Q;
  vector<pii> bfs_tree_edges;
  seen[st] = true;
  Q.push(st);
  while(!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for(int next : G[cur]) {
      if(!seen[next]){
        bfs_tree_edges.push_back({cur, next});
        seen[next] = true;
        Q.push(next);
      }
    }
  }
  reverse(bfs_tree_edges.begin(), bfs_tree_edges.end());
  for(pii edge : bfs_tree_edges) {
    int from = edge.first;
    int to = edge.second;
    ll edge_ind = lookup[edge];
    ans[edge_ind] = c[to];
    c[to] -= ans[edge_ind];
    c[from] -= ans[edge_ind];
  }
  return c[st] == 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vi c(n);
  rep(i, 0, n) { cin >> c[i]; }
  vector<vi> G(n);
  map<pii, int> lookup;
  rep(i, 0, m) {
    int st, end;
    cin >> st >> end;
    st--;
    end--;
    lookup[{st, end}] = i;
    lookup[{end, st}] = i;
    G[st].push_back(end);
    G[end].push_back(st);
  }
  vi oddCycle = find_odd_cycle(G);
  vi ans(m);
  vector<bool> seen(n, false);
  if(oddCycle.size() == 0) {
    if(!checkEdges(seen, 0, c, ans, lookup, G)){
      cout << "NO\n";
      return 0;
    }
  } else {
    for(int i = 0; i < oddCycle.size(); i++){
      seen[oddCycle[i]] = true;
    }
    for(int i = 0; i < oddCycle.size(); i++){ 
      checkEdges(seen, oddCycle[i], c, ans, lookup, G);
    }
    ll x = c[oddCycle[0]];
    for(int i = 1; i < oddCycle.size(); i++) {
      if(i % 2) {
        x += c[oddCycle[i]];
      } else {
        x -= c[oddCycle[i]];
      }
    }
    assert(x % 2 == 0);
    assert(oddCycle.size() % 2 == 1);
    for(int i = 0; i < oddCycle.size(); i++){ 
      int st = oddCycle[i];
      int end = oddCycle[(i + 1) % oddCycle.size()];
      assert(lookup.find({st, end}) != lookup.end());
      int ind = lookup[{st, end}];
      assert(ans[ind] == 0);
      if(i == 0) {
        ans[ind] = x / 2;
      } else {
        ans[ind] = c[st];
      }
      c[st] -= ans[ind];
      c[end] -= ans[ind];
    }
    for(int i = 0; i < n; i++){
      assert(c[i] == 0);
    }
  }
  cout << "YES\n";
  rep(i, 0, m) {
    // remember that we assumed that we
    // added 1 to all edges during
    // preprocessing.
    cout << ans[i] << "\n";
  }
  return 0;
}
