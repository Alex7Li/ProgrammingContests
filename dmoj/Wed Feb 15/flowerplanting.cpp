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
typedef vector<ll> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define MOD 998'244'353LL

#ifdef LOCAL
#pragma GCC optimize("trapv")  // signed overflow => RE
#else
// #pragma GCC target("arch=skylake")  // CF only
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int id;
  int n_tests;
  cin >> n_tests >> id;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, m, c, f;
    cin >> n >> m >> c >> f;
    vector<vi> grid(n, vi(m, 0));
    rep(i, 0, n) {
      string s;
      cin >> s;
      rep(j, 0, m) {
        if (s[j] == '1') {
          grid[i][j] = 1;
        } else {
          grid[i][j] = 0;
        }
      }
    }
    vector<vi> dist_l(n, vi(m, 0));
    rep(i, 0, n) {
      for (int j = m - 2; j >= 0; j--) {
        if (grid[i][j] == 0 && grid[i][j + 1] == 0) {
          dist_l[i][j] = dist_l[i][j + 1] + 1;
        }
      }
    }
    vector<vi> lineSum(n, vi(m, 0));
    rep(j, 0, m) {
      lineSum[0][j] = dist_l[0][j];
      rep(i, 1, n) {
        if (grid[i][j] == 0) {
          lineSum[i][j] = (lineSum[i - 1][j] + dist_l[i][j]) % MOD;
        }
      }
    }
    vector<vi> cCount(n, vi(m, 0));
    vector<vi> cSum(n, vi(m, 0));
    rep(j, 0, m) {
      rep(i, 2, n) {
        if (grid[i - 1][j] == 0 && grid[i][j] == 0) {
          cCount[i][j] = (lineSum[i - 2][j] * dist_l[i][j]) % MOD;
          cSum[i][j] = (cSum[i - 1][j] + cCount[i][j]) % MOD;
        }
      }
    }
    vector<vi> fCount(n, vi(m, 0));
    rep(j, 0, m) {
      rep(i, 2, n) {
        if (grid[i][j] == 0) {
          fCount[i][j] = cSum[i - 1][j] % MOD;
        }
      }
    }
    ll Vc = 0;
    ll Vf = 0;
    rep(i, 0, n) {
      rep(j, 0, m) {
        Vc = (cCount[i][j] + Vc) % MOD;
        Vf = (fCount[i][j] + Vf) % MOD;
      }
    }
    cout << (c * Vc) % MOD << " " << (f * Vf) % MOD << "\n";
  }
  return 0;
}
