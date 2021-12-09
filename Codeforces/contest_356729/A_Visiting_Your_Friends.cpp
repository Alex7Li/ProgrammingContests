#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// my book code
struct UF {
  // E is parent set number if positive, and the size if negative.
  // If negative, it's the root of a set.
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  void IncreaseSize(int x, int dsize) { e[find(x)]-=dsize; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
void add_fedge(int u, int v,
      map<int, map<int, set<pii>>> &fedges,
      UF &tedges, vector<set<int>> &fg) {
  int pu = tedges.find(u);
  int pv = tedges.find(v);

  if (pu == pv) {
    fg[u].insert(v);
    fg[v].insert(u);
  } else {
    fedges[pu][pv].insert(pii(u, v));
    fedges[pv][pu].insert(pii(u, v));
    tedges.IncreaseSize(pu, 1);
    tedges.IncreaseSize(pv, 1);
  }
}

void add_tedge(int u, int v, 
              map<int, map<int, set<pii>>> &fedges,
              UF &tedges, vector<set<int>> &fg) {
  int pu = tedges.find(u);
  int pv = tedges.find(v);
  if (pu != pv) {
    if(pu > pv){
      swap(pu, pv);
    }
    tedges.join(pu, pv);
    int alive = tedges.find(pu);
    int killed = pu ^ pv ^ alive;
    // merge pv and pu components
    tedges.IncreaseSize(pu, -fedges[pu][pv].size());
    tedges.IncreaseSize(pv, -fedges[pu][pv].size());
    for (auto edge : fedges[pu][pv])
    {
      int a = edge.first;
      int b = edge.second;
      fg[a].insert(b);
      fg[b].insert(a);
    }
    fedges[pu].erase(pv);
    fedges[pv].erase(pu);
    // move edges pointing to and from killed to alive
    for (auto edges : fedges[killed]) {
      int compInd1 = edges.first;
      for (auto edge: edges.second) {
        fedges[alive][compInd1].insert(edge);
        fedges[compInd1][alive].insert(edge);
      }
      tedges.IncreaseSize(alive, edges.second.size());
      tedges.IncreaseSize(compInd1, edges.second.size());
    }
    fedges.erase(killed);
  }
}
int query(int loc, vector<set<int>> &fg) { return fg[loc].size(); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  UF tedges(n);
  map<int, map<int, set<pii>>> fedges;
  vector<set<int>> fg(n);
  int u, v;
  // faster to do tedges first
  vector<pii> fedgetodo;
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    u--;
    v--;
    fedgetodo.push_back({u, v});
  }
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    u--;
    v--;
    add_tedge(u, v, fedges, tedges, fg);
  }
  for(pii a : fedgetodo) {
    add_fedge(a.first, a.second, fedges, tedges, fg);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string type;
    cin >> type;
    if (type == "?") {
      int loc;
      cin >> loc;
      loc--;
      cout << query(loc, fg) << "\n";
    } else if (type == "F") {
      cin >> u >> v;
      u--;
      v--;
      add_fedge(u, v, fedges, tedges, fg);
    } else if (type == "T") {
      cin >> u >> v;
      u--;
      v--;
      add_tedge(u, v, fedges, tedges, fg);
    } else {
      assert(false);
    }
  }
  return 0;
}