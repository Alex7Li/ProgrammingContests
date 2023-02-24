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
typedef vector<ll> vll;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define MOD 998'244'353
#ifdef LOCAL
#pragma GCC optimize("trapv")  // signed overflow => RE
#else
#pragma GCC target("arch=skylake")  // CF only
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll* inv = new ll[5001] - 1;
  inv[1] = 1;
  rep(i, 2, 5001) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  int n_tests;
  cin >> n_tests;
  vector<vll> dp(2, vll(5001));
  vi a(5001);
  vi smallerBlocks(5001);
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.begin() + n);
    ll f = 1;
    rep(i, 1, n) {
      if (a[i] == a[i - 1]) {
        smallerBlocks[i] = smallerBlocks[i - 1];
        f = (f * inv[1 + i - smallerBlocks[i - 1]]) % MOD;
      } else {
        smallerBlocks[i] = i;
      }
    }
    rep(k, 1, n) { dp[1][k] = smallerBlocks[k]; }
    int its = n / 2;
    rep(i, 2, its + 1) {
      int cur = i % 2;
      int prev = (i - 1) % 2;
      vll pSum(n + 1);
      rep(j, 0, n) {
        pSum[j + 1] = pSum[j] + dp[prev][j] * max(0, smallerBlocks[j] - 2 * i + 3);
      }
      rep(k, 0, n) {
        dp[cur][k] = pSum[smallerBlocks[k]] % MOD;
      }
    }
    ll ans = dp[its % 2][n - 1];
    cout << (ans * f) % MOD << "\n";
  }
  return 0;
}