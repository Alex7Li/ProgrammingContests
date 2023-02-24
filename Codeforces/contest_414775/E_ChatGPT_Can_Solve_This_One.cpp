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
typedef vector<ll> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(i, 0, t){
      int x, y;
      cin >> x >> y;
      vector<ll> f = {y, y, x, x};
      ll ans = 0;
      for(int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        vi p(n);
        rep(i, 0, n) {
          cin >> p[i];
        }
        sort(p.begin(), p.end());
        ll area = (p[p.size() - 1] - p[0]) * f[i];
        ans = max(ans, area);
      }
      cout << ans << "\n";
    }
    

    return 0;
}