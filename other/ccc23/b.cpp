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
typedef vector<ll> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
  #pragma GCC optimize("trapv") // signed overflow => RE
#else
  #pragma GCC target("arch=skylake") // CF only
#endif
#define INF 1000000000000LL

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n);
  rep(i, 0, n) {
    cin >> a[i];
  }
  vector<vi> dp(n, vi(n));
  vi ans(n, INF);
  ans[0] = 0;
  rep(i, 0, n) {
    dp[i][i] = 0;
  }
  rep(i, 0, n - 1) {
    dp[i][i + 1] = abs(a[i + 1] - a[i]);
    ans[1] = min(dp[i][i + 1], ans[1]);
  }

  rep(l, 2, n) {
    rep(i, 0, n - l) {
      dp[i][i + l] = abs(a[i + l] - a[i]) + dp[i + 1][i + l - 1];
      ans[l] = min(dp[i][i + l], ans[l]);
    }
  }
  rep(i, 0, n) {
    cout << ans[i] << " ";
  }
  return 0;
}
