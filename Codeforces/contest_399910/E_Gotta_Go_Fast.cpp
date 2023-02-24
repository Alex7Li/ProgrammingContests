#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif
#define INF 1e20

bool test_e_too_large(double e, vd& f, vd& s, vd& p) {
  int n = f.size();
  vector<vd> dp(n, vd(5201, INF));
  for(int t = 0; t < dp[n - 1].size(); t++) {
    dp[n-1][t] = 0;
  }
  for(int i = n - 2; i >= 0; i--) {
    for(int t = 0; t < dp[i].size() - 100; t++) {
      dp[i][t] = (1 - p[i]) * min(dp[i + 1][t + s[i]], e + t) +
        p[i] * dp[i + 1][t + f[i]];
    }
  }
  return dp[0][0] > e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    vd f(n);
    vd s(n);
    vd p(n);
    rep(i, 0, n) {
      cin >> f[i] >> s[i] >> p[i];
      p[i] /= 100;
    }
    double min = 0;
    double max = INF;
    while(max - min > 1e-9) {
      double mid = (max + min) / 2;
      if(test_e_too_large(mid, f, s, p)) {
        max = mid;
      } else {
        min = mid;
      }
    }
    printf("%.9f", min);
    return 0;
}