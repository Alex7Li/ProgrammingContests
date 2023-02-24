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
        string s;
        cin >> s;
        int n = s.size();
        vi dTimes(10, -1);
        vector<bool> taken(n);
        vi takeList;
        rep(digit, 0, 10){
          bool ok = true;
          for(int i = n - 1; i >= 0; i--) {
            int v = s[i] - '0';
            if (v == digit) {
              ok = false;
            } else if(!ok && v > digit && !taken[i]) {
              taken[i] = true;
              takeList.push_back(min(9, v + 1));
            }
          }
        }
        sort(takeList.begin(), takeList.end());
        int j = 0;
        rep(i, 0, n){
          if(!taken[i]) {
            int v = s[i] - '0';
            while(j < takeList.size() && takeList[j] < v) {
              cout << takeList[j];
              j += 1;
            }
            cout << s[i];
          }
        }
        while(j < takeList.size()) {
          cout << takeList[j];
          j += 1;
        }
        cout << "\n";
    }
    return 0;
}