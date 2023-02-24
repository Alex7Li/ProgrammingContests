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

int hash_pii(int x0, int x1){
  if(x1 < x0){
    swap(x1, x0);
  }
  return x0 + x1 * 26;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int n;
        cin >> n;
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;
        vector<int> pairs(26 * 26);
        for(int i = 0; i < n; i++){
          int x1 = s1[i] - 'a';
          int x2 = s2[n - i - 1] - 'a';
          int key = hash_pii(x1, x2);
          pairs[key] += 1;
          if(pairs[key] >= 2) {
            pairs[key] -= 2;
          }
        }
        bool possible = true;
        int left_key = -1;
        for(int i = 0; i < 26 * 26; i++){
          int count = pairs[i];
          if(count > 0) {
            if(count > 1 || left_key != -1) {
              possible = false;
            } else if(i % 27 == 0 && n % 2 == 1){
              left_key = i;
            } else{
              possible = false;
            }
          }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}