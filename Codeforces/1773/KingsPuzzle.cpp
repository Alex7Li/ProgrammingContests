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
    int k, n;
    cin >> n >> k;
    if(n == 1) {
      cout << "YES\n0\n";
    } else if (k >= n) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      vector<pii> roads;
      if(k == 1) {
        if(n == 2){
          roads.push_back({0, 1});
        } else {
          rep(i, 0, n) {
            roads.push_back({i, (i + 1) % n});
          }
        }
      } else {
        vector<int> reqs(k + 1);
        rep(i, 1, n) {
          roads.push_back({0, i});
        }
        rep(i, 1, k + 1){
          reqs[i] = k - i - 1;
        }
        while(true){
          int maxInd = 0;
          int maxReq = 0;
          rep(j, 1, k) {
            if(reqs[j] > maxReq) {
              maxInd = j;
              maxReq = reqs[j];
            }
          }
          if(maxReq == 0){
            break;
          }
          rep(j, 0, k + 1) {
            if(reqs[j] && j != maxInd) {
              reqs[maxInd]--;
              reqs[j]--;
              roads.push_back({maxInd, j});
            }
          }
        }
      }
      cout << roads.size() << "\n";
      rep(i, 0, roads.size()) {
        assert(roads[i].first != roads[i].second);
        cout << (roads[i].first + 1) << " " << (roads[i].second + 1) << "\n";
      }
    }
    return 0;
}
