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

int gcd(int x, int y) {
  if(y == 0) return x;
  return gcd(y, x % y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  ll ans = n * m;
  // rep(i, 1, n + 1) {
  //   rep(j, 1, m + 1) {
  //     ans += 2 * gcd(i, j);
  //   }
  // }
  int M = min(n, m);
  vector<ll> gcdCount(M + 1);
  for(int i = M; i > 1; i--) {
    gcdCount[i] = (n / i) * (m / i);
    for(int j = 2 * i; j <= M; j += i) {
      gcdCount[i] -= gcdCount[j];
    }
  }
  rep(i, 2, min(n, m) + 1) {
    ans += 2 * (i - 1) * gcdCount[i];
    // cerr << i << " " << gcdCount[i] << "\n";
  }
  cout << ans << endl;
  return 0;
}