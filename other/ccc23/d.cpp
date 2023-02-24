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

struct Road {
  int u;
  int v;
  int l;
  ll c;
  bool operator<(Road& o) {
    return c < o.c;
  }
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  RollbackUF uf = RollbackUF(n + 1);
  vector<Road> roads(m);
  rep(i, 0, m) {
    cin >> roads[i].u >> roads[i].v >> roads[i].l >> roads[i].c;
    roads[i].u--;
    roads[i].v--;
  }
  sort(roads.begin(), roads.end());
  ll cost = 0;
  rep(i, 0, m) {
    bool joined = uf.join(roads[i].u, roads[i].v);
    if(joined) {
      cost += roads[i].c;
    }
  }
  cout << cost;
  return 0;
}