#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x)
#define _ << " _ " <<
#define MOD 1'000'000'007
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
  #pragma GCC optimize("trapv") // signed overflow => RE
  #define BOUND 30
#else
    #pragma GCC target("arch=skylake") // CF only
  #define BOUND 1 << 22
#endif
namespace PersistentSets {
  int lPtr[BOUND];
  int rPtr[BOUND];
  // maximum value in the interval representing the set
  int maxVals[BOUND];
  int parent[BOUND];
  vector<int> pow2;
  int curInd = 1;
  void setup(int n){
    pow2 = vector<int>(n + 1);
    pow2[0] = 1;
    for(int i = 0; i < n; i ++) {
      pow2[i + 1] = (pow2[i] + pow2[i]) % MOD;
    }
    for(int i = 0; i < BOUND; i++) {
      parent[i] = -1;
    }
  }
  int init(int l, int r) {
    int mid = (l + r) / 2;
    int ind = curInd++;
    if(l + 1 != r){
      lPtr[ind] = init(l, mid);
      rPtr[ind] = init(mid, r);
    }
    maxVals[ind] = -1;
    return ind;
  }
  int makeNewTree(int copyInd) {
    int ind = curInd++;
    lPtr[ind] = lPtr[copyInd];
    rPtr[ind] = rPtr[copyInd];
    maxVals[ind] = maxVals[copyInd];
    return ind;
  }
  pair<bool, int> add(int x, int l, int r, int treeInd) {
    assert(x >= 0);
    treeInd = makeNewTree(treeInd);
    if(x == l && r == l + 1) {
      if(maxVals[treeInd] == -1) {
        maxVals[treeInd] = x;
        return {false, treeInd};
      } else {
        maxVals[treeInd] = -1;
        return {true, treeInd};
      }
    } else {
      int mid = (l + r) / 2;
      bool carry;
      do {
        carry = false;
        if(x < mid) {
          pair<int, int> res = add(x, l, mid, lPtr[treeInd]);
          carry = res.first;
          lPtr[treeInd] = res.second;
          x = mid;
        }  else if (x < r){
          pair<int, int> res = add(x, mid, r, rPtr[treeInd]);
          carry = res.first;
          rPtr[treeInd] = res.second;
          x = r;
        } else {
          return {true, treeInd};
        }
        maxVals[treeInd] = max(
          maxVals[lPtr[treeInd]], maxVals[rPtr[treeInd]]
        );
      } while(carry);
      return {false, treeInd};
    }
  }
  // dsu
  int set_of(int ind1) {
    return parent[ind1] < 0 ? ind1 : parent[ind1] = set_of(parent[ind1]);
  }
  void mergeSet(int ind1, int ind2) {
    int p1 = set_of(ind1);
    int p2 = set_of(ind2);
    if(p1 > p2){
      swap(p1, p2);
    }
    parent[p1] += parent[p2];
    parent[p2] = p1;
  }
  int compare(int ind1, int ind2) {
    if(set_of(ind1) == set_of(ind2)) {
      return 0;
    }
    int result = 0;
    if(maxVals[ind1] != maxVals[ind2] || !lPtr[ind1]) {
      result = maxVals[ind2] - maxVals[ind1];
    } else {
      result = compare(rPtr[ind1], rPtr[ind2]);
      if(!result) {
        result = compare(lPtr[ind1], lPtr[ind2]);
      }
    }
    if(!result) {
      mergeSet(ind1, ind2); // cache this equality
    }
    return result;
  }

  ll cost(int ind) {
    if(!lPtr[ind]) {
      if(maxVals[ind] >= 0) {
        return pow2[maxVals[ind]];
      } else {
        return 0;
      }
    } else {
      return (cost(lPtr[ind]) + cost(rPtr[ind])) % MOD;
    }
  }
  struct TreeCompare {
    bool operator() (pair<int, pii> treeInd1, pair<int, pii> treeInd2) {
      int cmp = compare(treeInd1.first, treeInd2.first);
      return cmp < 0;
    }
  };
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> G(n);
    int tree_size = 0;
    rep(i, 0, m) {
      int u, v, x;
      cin >> u >> v >> x;
      u--;v--;
      G[u].push_back({v, x});
      G[v].push_back({u, x});
      tree_size = max(tree_size, x);
    }
    tree_size += int(log2(n)) + 2;
    int s, t;
    cin >> s >> t;
    s--; t--;
    PersistentSets::setup(tree_size);
    int tree_root = PersistentSets::init(0, tree_size);
    // (treeind, nodeind, fromnodeind)
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, PersistentSets::TreeCompare> Q;
    vector<int> prev(n, -1);
    Q.push({tree_root, {s, s}});
    ll final_cost = -1;
    while(!Q.empty()) {
      auto from = Q.top();
      Q.pop();
      int from_tree = from.first;
      int from_node = from.second.first;
      if(prev[from_node] != -1) {
        continue;
      }
      prev[from_node] = from.second.second;
      if(from_node == t) {
        final_cost = PersistentSets::cost(from_tree);
        break;
      }
      for(pii edge: G[from_node]) {
        int to_node = edge.first;
        int w = edge.second;
        if(prev[to_node] == -1) {
          int to_tree = PersistentSets::add(w, 0, tree_size, from_tree).second;
          Q.push({to_tree, {to_node, from_node}});
        }
      }
    }
    cout << final_cost << "\n";
    if(final_cost != -1) {
      vector<int> path;
      int from = t;
      path.push_back(t);
      while(from != s) {
        from = prev[from];
        path.push_back(from);
      }
      cout << path.size() << "\n";
      for(int i = path.size() - 1; i >= 1; i--) {
        cout << (path[i]+1) << " ";
      }
      cout << (path[0]+1) << "\n";
    }
    return 0;
}
