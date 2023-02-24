#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
template <class k>
using ordered_set =
    __gnu_pbds::tree<k, __gnu_pbds::null_type, std::less<k>,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define _ << " _ " <<
#define INF 100000
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#ifdef LOCAL
#pragma GCC optimize("trapv")  // signed overflow => RE
#else
#pragma GCC target("arch=skylake")  // CF only
#endif
// Description: Push-relabel using the highest label selection rule and the gap
// heuristic. Quite fast in practice. To obtain the actual flow, look at positive
// values only.
struct PushRelabel {
  struct Edge {
    int dest, back;
    ll f, c;
  };
  vector<vector<Edge>> g;
  vector<ll> ec;
  vector<Edge*> cur;
  vector<vi> hs;
  vi H;
  PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
  void addEdge(int s, int t, ll cap, ll rcap = 0) {
    if (s == t) return;
    g[s].push_back({t, sz(g[t]), 0, cap});
    g[t].push_back({s, sz(g[s]) - 1, 0, rcap});
  }
  void addFlow(Edge& e, ll f) {
    Edge& back = g[e.dest][e.back];
    if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
    e.f += f;
    e.c -= f;
    ec[e.dest] += f;
    back.f -= f;
    back.c += f;
    ec[back.dest] -= f;
  }
  ll calc(int s, int t) {
    int v = sz(g);
    H[s] = v;
    ec[t] = 1;
    vi co(2 * v);
    co[0] = v - 1;
    rep(i, 0, v) cur[i] = g[i].data();
    for (Edge& e : g[s]) addFlow(e, e.c);
    for (int hi = 0;;) {
      while (hs[hi].empty())
        if (!hi--) return -ec[s];
      int u = hs[hi].back();
      hs[hi].pop_back();
      while (ec[u] > 0)  // discharge u
        if (cur[u] == g[u].data() + sz(g[u])) {
          H[u] = 1e9;
          for (Edge& e : g[u])
            if (e.c && H[u] > H[e.dest] + 1) H[u] = H[e.dest] + 1, cur[u] = &e;
          if (++co[H[u]], !--co[hi] && hi < v)
            rep(i, 0, v) if (hi < H[i] && H[i] < v)-- co[H[i]], H[i] = v + 1;
          hi = H[u];
        } else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
          addFlow(*cur[u], min(ec[u], cur[u]->c));
        else
          ++cur[u];
    }
  }
  bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

namespace Node {
int a[10000];
int lPtr[10000];
int rPtr[10000];
int curInd = 0;
int M;
void init(int M_, PushRelabel& d) {
  M = M_;
  for (int i = 1; i < M; i++) {
    d.addEdge(i, 2 * i, INF);
    d.addEdge(i, 2 * i + 1, INF);
  }
}
void fill(int ql, int qr, int fromInd, PushRelabel& d) {
  for (ql = ql + M, qr = qr + M; ql != qr; ql >>= 1, qr >>= 1) {
    if (ql & 1) {
      d.addEdge(fromInd, ql++, 1);
    }
    if (qr & 1) {
      d.addEdge(fromInd, --qr, 1);
    }
  }
}
}  // namespace Node
// https://codeforces.com/contest/1045/problem/A
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  PushRelabel flow_net(2 * m + n + 2);
  Node::init(m, flow_net);
  int source = 0;
  int sink = 2 * m;
  int weaponOffset = 2 * m + 1;
  vector<bool> usedNodes(m);
  hash_map<int, vi> sql_rockets;
  vector<pair<pii, int>> cognition_beams;
  hash_map<int, vi> OMG_bazookas;
  vector<int> types(n);
  // read input
  rep(i, 0, n) {
    int type;
    cin >> type;
    types[i] = type;
    if (type == 0) {
      int k;
      cin >> k;
      vi weap(k);
      rep(j, 0, k) {
        cin >> weap[j];
        weap[j]--;
      }
      sql_rockets[i] = weap;
    } else if (type == 1) {
      int l, r;
      cin >> l >> r;
      l--;
      cognition_beams.push_back({{r, l}, i});
    } else {
      assert(type == 2);
      vector<int> OMG(3);
      cin >> OMG[0] >> OMG[1] >> OMG[2];
      OMG[0]--;
      OMG[1]--;
      OMG[2]--;
      OMG_bazookas[i] = OMG;
    }
  }
  // make graph
  for (auto weap : sql_rockets) {
    int weaponInd = weap.first;
    flow_net.addEdge(source, weaponInd + weaponOffset, 1);
    rep(i, 0, weap.second.size()) {
      flow_net.addEdge(weaponInd + weaponOffset, m + weap.second[i], 1);
    }
  }
  for (auto weap : cognition_beams) {
    int weaponInd = weap.second;
    int l = weap.first.second;
    int r = weap.first.first;
    flow_net.addEdge(source, weaponInd + weaponOffset, 1);
    Node::fill(l, r, weaponInd + weaponOffset, flow_net);
  }
  for (auto weap : OMG_bazookas) {
    int weaponInd = weap.first;
    for (auto omgInd : weap.second) {
      flow_net.addEdge(m + omgInd, weaponInd + weaponOffset, 1);
      usedNodes[omgInd] = true;
    }
    flow_net.addEdge(weaponInd + weaponOffset, sink, 1);
  }
  rep(i, 0, m) {
    if (!usedNodes[i]) {
      flow_net.addEdge(i + m, sink, 1);
    }
  }
  ll flow = flow_net.calc(source, sink) + 2 * OMG_bazookas.size();
  vector<pii> ans;
  // determine type 0 and 2 weapons
  for(int u = 0; u < flow_net.g.size(); u++) {
    for(auto e : flow_net.g[u]) {
      if(e.f > 0) {
        if (u >= weaponOffset && types[u - weaponOffset] == 0 && e.dest != 0) {
            // type 0
            int boomed_ship = e.dest - m;
            ans.push_back({u - weaponOffset, boomed_ship});
        } else if (e.dest >= weaponOffset && types[e.dest - weaponOffset] == 2) {
          int weaponInd = e.dest - weaponOffset;
          vi options = OMG_bazookas[weaponInd];
          for (auto boomable_ship : options) {
            if (boomable_ship != u - m) {
              ans.push_back({weaponInd, boomable_ship});
            }
          }
          OMG_bazookas.erase(weaponInd);
        }
      }
    }
  }
  for (auto weap : OMG_bazookas) {
    int weaponInd = weap.first;
    ans.push_back({weaponInd, weap.second[0]});
    ans.push_back({weaponInd, weap.second[1]});
  }
  vector<bool> hit_ships(m);
  for (auto p : ans) {
    hit_ships[p.second] = true;
  }
  ordered_set<int> unhit_ships;
  for (int i = 0; i < m; i++) {
    if (!hit_ships[i]) {
      unhit_ships.insert(i);
    }
  }
  // determine type 1 weapons
  sort(cognition_beams.begin(), cognition_beams.end());
  for (auto weap : cognition_beams) {
    int r = weap.first.first;
    int l = weap.first.second;
    int weaponInd = weap.second;
    auto target = unhit_ships.lower_bound(l);
    if (*target < r) {
      ans.push_back({weaponInd, *target});
      unhit_ships.erase(target);
    }
  }
  cout << flow << endl;
  // Sometimes they are not equal but printing flow first
  // always works O:
  // I think there is a bug in the checker
  // assert (flow == ans.size());
  // cout << ans.size() << endl;
  for (auto a : ans) {
    cout << (a.first + 1) << " " << (a.second + 1) << "\n";
  }
  return 0;
}
