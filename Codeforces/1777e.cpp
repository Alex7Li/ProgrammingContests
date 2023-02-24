#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
vi val, comp, z, cont;
int Time, ncomps;
template <class G>
int dfs(int j, G& g) {
  int low = val[j] = ++Time, x;
  z.push_back(j);
  for (auto e : g[j])
    if (comp[e] < 0) low = min(low, val[e] ?: dfs(e, g));
  if (low == val[j]) {
    do {
      x = z.back();
      z.pop_back();
      comp[x] = ncomps;
      cont.push_back(x);
    } while (x != j);
    cont.clear();
    ncomps++;
  }
  return val[j] = low;
}
template <class G>
void scc(G& g) {
  int n = sz(g);
  val.assign(n, 0);
  comp.assign(n, -1);
  Time = ncomps = 0;
  rep(i, 0, n) if (comp[i] < 0) dfs(i, g);
}

struct Edge {
  int a, b, w;
  bool operator<(Edge& o) { return w < o.w; }
};
struct RollbackUF {
  vi e;
  vector<pii> st;
  RollbackUF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return sz(st); }
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

bool check(vector<vi> graph, vector<Edge>& edges, int w, int m) {
    rep(i, 0, m) {
      if(edges[i].w <= w) {
        graph[edges[i].b].push_back(edges[i].a);
      } else {
        break;
      }
    }
    scc(graph);
    vector<bool> is_source(ncomps, true);
    rep(i, 0, m) {
      if (comp[edges[i].b] != comp[edges[i].a]) {
        is_source[comp[edges[i].b]] = false;
      }
    }
    int n_source = 0;
    rep(i, 0, ncomps) {
      if (is_source[i]) {
        n_source += 1;
      }
    }
    return n_source == 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<vi> graph(n);
    rep(i, 0, m) {
      int a, b, w;
      cin >> a >> b >> w;
      a--;
      b--;
      graph[a].push_back(b);
      edges.push_back({a, b, w});
    }
    sort(edges.begin(), edges.end());
    int r = (1 << 30) - 1;
    for(int d = 1 << 29; d > 0; d /= 2) {
      int new_r = r - d;
      if(check(graph, edges, new_r, m)) {
        r = new_r;
      }
    }
    if (r == (1 << 30) - 1) {
      r = -1;
    }
    cout << r << "\n";
  }
  return 0;
}

/*
4
4 5
1 2 10000
2 3 20000
1 3 30000
4 2 500
4 3 20
5 4
1 2 10
2 3 10
3 1 10
4 5 10
4 5
1 2 10000
2 3 20000
1 3 30000
4 2 5
4 3 20
2 1
1 2 3

*/