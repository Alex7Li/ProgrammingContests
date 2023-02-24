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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
      int n;
      cin >> n;
      vector<ll> a(n);
      for(int i = 0; i < n; i++) {
        cin >> a[i];
      }
      ll ans = 1;
      for(int i = 0; i < n; i++) {
        ans *= a[i];
      }
      cout << (ans + n - 1) * 2022 << "\n";
  }
  return 0;
}