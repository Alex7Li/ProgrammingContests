#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
  #pragma GCC optimize("trapv") // signed overflow => RE
#else
  #pragma GCC target("arch=skylake") // CF only
#endif

ll MOD = 10007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vi> G(n);
  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vi vals(n);
  rep(i, 0, n) {
    cin >> vals[i];
  }
  rep(i, 0, n) {
    rep(j, 0, sz(G[i])) {
      G[i][j] = vals[G[i][j]];
    }
  }
  int M = 0;
  ll S = 0;
  for(vi& e: G) {
    sort(e.begin(), e.end());
    if(sz(e) >= 2) {
      M = max(M, e[sz(e) - 1] * e[sz(e) - 2]);
    }
    ll su = 0;
    rep(j, 0, sz(e)) {
      su += e[j];
    }
    su = su % MOD;
    su = (su * su) % MOD;
    S += su;
    rep(j, 0, sz(e)) {
      S -= e[j] * e[j];
    }
    S = S % MOD;
  }
  S = (S + MOD) % MOD;
  cout << M << " " << S;
  return 0;
}