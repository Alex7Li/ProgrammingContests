#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
#pragma GCC optimize("trapv")  // signed overflow => RE
#else
#pragma GCC target("arch=skylake")  // CF only
#endif

struct Edge {
  int cost;
  bool needs_move;
  int to;
  int from;
  bool used = false;
};
struct RollbackUF {
  vi e;
  vector<pii> st;
  RollbackUF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return st.size(); }
  void rollback(int t) {
    for (int i = time(); i-- > t;) e[st[i].first] = st[i].second;
    st.resize(t);
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m, d;
  cin >> n >> m >> d;
  // 1) MST with strange comparison func
  vector<Edge> edges(m);
  rep(i, 0, m) {
    cin >> edges[i].to >> edges[i].from >> edges[i].cost;
    edges[i].to--;
    edges[i].from--;
    edges[i].needs_move = i >= n - 1;
  }
  sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
    if (a.cost == b.cost) {
      return a.needs_move < b.needs_move;
    } else {
      return a.cost < b.cost;
    }
  });
  RollbackUF uf(n);
  rep(i, 0, m) {
    if (uf.find(edges[i].to) != uf.find(edges[i].from)) {
      uf.join(edges[i].to, edges[i].from);
      edges[i].used = true;
    }
  }
  // 2) Check if all edges have cost less than d
  // check if there is an unused origin edge of cost at most d,
  int max_edge_cost = 0;
  int days = 0;
  rep(i, 0, m) {
    if (edges[i].used and edges[i].needs_move) {
      days++;
      max_edge_cost = max(max_edge_cost, edges[i].cost);
    }
  }
  rep(i, 0, m) {
    if (edges[i].used && edges[i].cost >= d) {
      cout << days << "\n";
      return 0;
    }
  }
  RollbackUF uf2(n);
  sort(edges.begin(), edges.end(), [&](Edge& a, Edge& b) {
    int ac, bc;
    if (a.cost >= max_edge_cost && a.cost <= d && !a.needs_move) {
      ac = max_edge_cost;
    }
    if (b.cost >= max_edge_cost && b.cost <= d && !b.needs_move) {
      bc = max_edge_cost;
    }
    if (ac == bc) {
      return a.needs_move < b.needs_move;
    } else {
      return a.cost < b.cost;
    }
  });
  rep(i, 0, m) {
    if (uf2.find(edges[i].to) != uf2.find(edges[i].from)) {
      if (edges[i].cost > max_edge_cost && !edges[i].needs_move) {
        cout << days - 1 << "\n";
        return 0;
      }
      uf2.join(edges[i].to, edges[i].from);
    }
  }
  cout << days << "\n";
  return 0;
}
