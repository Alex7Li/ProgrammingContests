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

  int n, k;
  cin >> n >> k;
  vi a(n + 1);
  a[0] = -6;
  rep(i, 1, n + 1) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vi prev(n + 1);
  prev[0] = 0;
  int curInd = 0;
  rep(i, 1, n + 1) {
    while(a[curInd + 1] < a[i] - 5) {
      curInd++;
    }
    prev[i] = curInd;
  }
  vector<vi> dp(2, vi(n + 1, 0));
  rep(g, 1, k + 1) {
    int g2 = g % 2;
    rep(i, 1, n + 1) {
      dp[g2][i] = max(dp[g2][i - 1],
          i - prev[i] + dp[g2 ^ 1][prev[i]]);
      // cout << dp[g2][i] << " ";
    }
    // cout << "\n";
  }
  cout << dp[k % 2][n] << "\n";
  return 0;
}