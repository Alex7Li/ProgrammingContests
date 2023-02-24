#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
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

int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, 0, n) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> psum(n + 1);
    rep(i, 0, n) {
      psum[i + 1] = psum[i] + a[i];
    }
    int can_purchase = n;
    ll cur_day = 0;
    ll bought = 0;
    while (can_purchase > 0) {
      while (can_purchase > 0 && psum[can_purchase] + cur_day * can_purchase > x) {
        can_purchase--;
      }
      if(can_purchase == 0){
        break;
      }
      ll left_power = x - psum[can_purchase];
      // the first day we can not buy can_purchase items.
      // next_day * can_purchase > left_power
      // next_day > left_power / can_purchase
      ll next_day  = (left_power / can_purchase) + 1;
      bought += (next_day - cur_day) * can_purchase;
      assert(next_day >= cur_day);
      cur_day = next_day;
      assert(psum[can_purchase] + cur_day * can_purchase > x);
      assert(psum[can_purchase] + (cur_day - 1) * can_purchase <= x);
    }
    cout << bought << "\n";
  }
  return 0;
}