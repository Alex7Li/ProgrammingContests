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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll M = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      M = max(M, a[i]);
    }
    ll ans = 0;
    if(n != 3 && n != 2){
      ans = n * M;
    } else if(n == 2){
      ans = max(a[0] + a[1], 2 * abs(a[0] - a[1]));
    } else {
      vector<ll> possible = {
        a[0] + a[1] + a[2],
        3 * a[0],
        3 * a[2],
        3 * abs(a[1] - min(a[0], a[2])),
        3 * abs(abs(a[2] - a[1]) - a[0]),
        3 * abs(abs(a[0] - a[1]) - a[2]),
      };
      for(ll x : possible) {
        ans = max(ans, x);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
