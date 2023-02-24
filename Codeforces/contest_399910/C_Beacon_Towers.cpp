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
#define MOD 1'000'000'007LL

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake")
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    int cur_max = 0;
    ll ans = 1;
    int last_max_ind = 0;
    rep(i, 0, n){
      cin >> a[i];
      if(a[i] > cur_max){
        cur_max = a[i];
        ans = (ans * (i - last_max_ind + 1)) % MOD;
        last_max_ind = i;
      }
    }
    cout << ans;
    return 0;
}