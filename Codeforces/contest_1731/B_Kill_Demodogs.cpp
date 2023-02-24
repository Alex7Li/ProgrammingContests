#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define _ << " _ " <<
#define MOD 1'000'000'007
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
  ll twoInv = 500'000'004;
  ll threeInv = 333'333'336;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    ll n;
    cin >> n;
    ll p1 = n * (n + 1) % MOD;
    ll p2 = p1 * twoInv % MOD;
    p1 = p1 * (2 * n + 1) % MOD;
    p1 = p1 * threeInv % MOD;
    ll ans = ((p1 - p2) % MOD + MOD) % MOD;
    ans = ans * 2022 % MOD;
    cout << ans << "\n";
  }
  return 0;
}