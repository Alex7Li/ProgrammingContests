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
// #ifdef LOCAL
//   ifstream cin("case1.in");
// #else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
// #endif
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    set<int> seen;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      seen.insert(a[i]);
    }
    // if we don't need to carry
    bool need_carry = false;
    if(a[n-1] < n + 4) {
      rep(i, 0, a[n-1]) { 
        if(!seen.count(i)) {
          need_carry = true;
          break;
        }
      }
    } else {
      need_carry = true;
    }
    int ans = 0;
    if(need_carry) {
      // add
      seen.insert(0);
      bool upd = false;
      for(int i = n - 2; i >= 0; i--) {
        if(a[i] != p - 1) {
          seen.insert(a[i] + 1);
          upd = true;
          break;
        }
      }
      if(!upd) {
        seen.insert(1);
      }
      // finish
      for(int i = a[n - 1] - 1; i >= 0; i--) {
        ans = (p - a[n - 1]) + i;
        if(!seen.count(i)) {
          break;
        }
      }
    } else {  
      for(int i = p - 1; i >= a[n - 1]; i--) {
        ans = i - a[n - 1];
        if(!seen.count(i)) {
          break;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}