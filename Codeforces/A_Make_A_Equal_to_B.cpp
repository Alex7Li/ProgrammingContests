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
      vi a(n);
      vi b(n);
      rep(i, 0, n){
        cin >> a[i];
      }
      rep(i, 0, n){
        cin >> b[i];
      }
      int diff = 0;
      int sum = 0;
      rep(i, 0, n){
        if(a[i] != b[i]) {
          diff += 1;
        }
        sum += a[i];
        sum -= b[i];
      }
      int ans = diff;
      ans = min(ans, 1 + abs(sum));
      cout << ans << "\n";
    }
    return 0;
}