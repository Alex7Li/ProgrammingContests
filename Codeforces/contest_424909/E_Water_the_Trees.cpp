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

int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vi h(n);
    int maxVV = 0;
    rep(i, 0, n) {
      cin >> h[i];
      maxVV = max(maxVV, h[i]);
    }
    ll best = 1e16;
    rep (maxV, maxVV, maxVV + 2) {
      int wrong_pairity = 0;
      ll req_sum = 0;
      rep(i, 0, n) {
        int need_height = maxV - h[i];
        if (need_height % 2 == 1) {
          wrong_pairity++;
          need_height--;
        }
        req_sum += need_height;
      }
      ll cur_day = max(0, wrong_pairity * 2 - 1);
      ll even_days = cur_day / 2;
      req_sum = max(ll(0), req_sum - even_days * 2);
      ll loops = req_sum / 6;
      cur_day += loops * 4;
      req_sum -= loops * 6;
      if (req_sum == 4) {
        cur_day += 3;
        req_sum -= 4;
      } else if (req_sum == 2) {
        cur_day += 2 - (cur_day % 2);
        req_sum -= 2;
      }
      assert(req_sum == 0);
      best = min(best, cur_day);
    }
    cout << best << "\n";
  }
  return 0;
}