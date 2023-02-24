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
#define INF 1'000'000'000
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<vi>> dp;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif
void upd(dp& ans, vector<vi>& cache, int ansi, int ansk, int ansv, int oldi, int oldk, int oldv, int add) {
  ans[ansi][ansk][ansv] = max(ans[oldi][oldk][oldv] + add, ans[ansi][ansk][ansv]);
  cache[ansi][ansk] = max(cache[ansi][ansk], ans[ansi][ansk][ansv]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n){
      cin >> a[i];
    }
    // Ans[i][k][v] = The answer after i turns,
    // given that we have not used k swaps (or used them on the left side)
    // and that the value at a[i - 1] is a[v].
    // Final answer is hence max ans[n][*][*]
    dp ans(n + 1, vector<vi>(n + 1, vi(n, -INF)));
    // max of ans[i][k]
    vector<vi> cache(n + 1, vi(n + 1, -INF));
    ans[0][0][0] = 0;
    cache[0][0] = 0;
    rep(i, 1, n + 1) {
      rep(k, 0, n) {
        // Wait a bit
        rep(j, 0, n){
          upd(ans, cache, 
          i, k + 1, i - 1,
          i - 1, k, j, 
          a[i - 1]);
        }
        // OR
        // ans[i][k + 1][i] = cache[i - 1][k] + a[i - 1];
        // cache[i][k + 1] = max(cache[i][k + 1], ans[i][k + 1][i]);
        if(i > 1) {
          // Eat previous value
          rep(v, 0, n) {
            upd(ans, cache, 
            i, k, v,
            i - 1, k, v, 
            a[v]);
          }
        }
        // get new value from far right
        rep(s, 0, k + 1) {
          if(i + s >= n) {
            break;
          }
          ans[i][k - s][i + s] = max(cache[i - 1][k] + a[i + s], ans[i][k - s][i + s]);
          cache[i][k - s] = max(cache[i][k - s], ans[i][k - s][i + s]);
        }
      }
    }
    int final = 0;
    rep(k, 0, n) {
      final = max(final, cache[n][k]);
    }
    cout << final << "\n";
    return 0;
}
