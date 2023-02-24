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
    int n;
    cin >> n;
    map<int, int> nums;
    int total = 0;
    int cur = 0;
    rep(i, 0, n) {
      int k;
      cur += 1;
      cin >> k;
      total += k;
      int last = 0;
      rep(j, 0, k){
        int b;
        cin >> b;
        if(b < last) {
          cur++;
        }
        last = b;
        nums[b] = cur;
      }
    }
    int last = -1;
    int streak = 0;
    int streaksum = 0;
    for(auto v: nums) {
      if(v.second != last) {
        streaksum += streak;
        streak = 0;
      } else {
        streak += 1;
      }                                                                                                                                                                   
      last = v.second;                                                       
    }
    streaksum += streak;
    int splits = total - streaksum - n;
    cout << splits << " " << splits + n - 1 << "\n";
    return 0;
}