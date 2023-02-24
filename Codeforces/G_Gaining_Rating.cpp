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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n + 1);
  a[n] = y;
  rep(i, 0, n) {
    cin >> a[i];
    a[i] = min(a[i], y);
  }
  sort(a.begin(), a.end());
  ll cost = 0;
  int idx = 0;
  while(x < y && a[idx] <= x) {
    x++; idx++; cost++;
  }
  if (2 * idx - n > 0) {
    while (x < y) {
      ll gain = 2 * idx - n;
      ll dist = a[idx] - x;
      ll iterations = (dist + (gain - 1)) / gain;
      x += iterations * gain;
      cost += iterations * n;
      while(x < y && a[idx] <= x) {
        x++; idx++; cost++;
      }
    }
  }
  if(x >= y) {
    cout << cost - (x - y) << "\n";
  } else {
    assert(x < y);
    cout << -1 << "\n";
  }
  } 
  return 0;
}