#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
/**
 * Author: Johan Sannemo
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Calculate power of two jumps in a tree,
 * to support fast upward jumps and LCAs.
 * Assumes the root node points to itself.
 * Time: construction $O(N \log N)$, queries $O(\log N)$
 * Status: Tested at Petrozavodsk, also stress-tested via LCA.cpp
 */

vector<vi> treeJump(vi &P) {
  int on = 1, d = 1;
  while (on < sz(P))
    on *= 2, d++;
  vector<vi> jmp(d, P);
  rep(i, 1, d) rep(j, 0, sz(P)) jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
  return jmp;
}

int jmp(vector<vi> &tbl, int nod, int steps) {
  rep(i, 0, sz(tbl)) if (steps & (1 << i)) nod = tbl[i][nod];
  return nod;
}

int lca(vector<vi> &tbl, vi &depth, int a, int b) {
  if (depth[a] < depth[b])
    swap(a, b);
  a = jmp(tbl, a, depth[a] - depth[b]);
  if (a == b)
    return a;
  for (int i = sz(tbl); i--;) {
    int c = tbl[i][a], d = tbl[i][b];
    if (c != d)
      a = c, b = d;
  }
  return tbl[0][a];
}

void get_h(int root, vector<vi> &g, vi &h, vi &p, int root_h) {
  h[root] = root_h;
  for (int child : g[root]) {
    if (h[child] == -1) {
      h[child] = root_h + 1;
      p[child] = root;
      get_h(child, g, h, p, root_h + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  map<pii, int> edge_ind;
  vector<pii> edges(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    edges[i] = {a, b};
    edge_ind[{a, b}] = i;
    edge_ind[{b, a}] = i;
  }
  set<int> treeInds;
  vector<vi> spanning_tree(n);
  for (int i = 0; i < n - 1; i++) {
    int ind;
    cin >> ind;
    ind--;
    treeInds.insert(ind);
    int a = edges[ind].first;
    int b = edges[ind].second;
    spanning_tree[a].push_back(b);
    spanning_tree[b].push_back(a);
  }
  int root = 0;

  vector<int> h(n, -1);
  vector<int> p(n, 0);
  int curT = 0;
  vector<int> ans(m);
  get_h(root, spanning_tree, h, p, 0);
  vector<vi> tbl = treeJump(p);
  for (int i = 0; i < edges.size(); i++) {
    int a = edges[i].first;
    int b = edges[i].second;
    if (h[a] > h[b]) {
      swap(a, b);
    }
    if (ans[i] != 0){
      continue;
    }
    if (treeInds.count(i)) {
      assert(a == p[b]);
      ans[i] = ++curT;
      continue;
    }
    int lca_ind = lca(tbl, h, a, b);
    vector<int> updates;
    while (h[b] > h[lca_ind]) {
      int edgeI = edge_ind[{b, p[b]}];
      if (treeInds.count(edgeI) && ans[edgeI] == 0) {
        updates.push_back(edgeI);
      }
      int tmp = p[b];
      p[b] = lca_ind;
      b = tmp;
    }
    while (h[a] > h[lca_ind]) {
      int edgeI = edge_ind[{a, p[a]}];
      if (treeInds.count(edgeI) && ans[edgeI] == 0) {
        updates.push_back(edgeI);
      }
      int tmp = p[a];
      p[a] = lca_ind;
      a = tmp;
    }
    sort(updates.begin(), updates.end());
    updates.push_back(i); //edge_ind[edges[i]]);
    for (int edgeI : updates) {
      ans[edgeI] = ++curT;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == 0) {
      ans[i] = ++curT;
    }
  }
  cout << ans[0];
  for (int i = 1; i < m; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}
