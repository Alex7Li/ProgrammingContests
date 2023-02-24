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
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    if(n % 2 == 1){
      if(n == 3) {
        cout << "NO\n"; 
      } else {
        cout << "YES\n";
        for(int i = 0; i < n / 2; i++) {
          cout << -(n - 3) << " " << n - 1 << " ";
        }
        cout << -(n - 3) << "\n";

      }
    }else {
      cout << "YES\n";
      for(int i = 0; i < n / 2; i++) {
        cout << "-1 1 ";
      }
      cout << "\n";
    }
  }
  return 0;
}
