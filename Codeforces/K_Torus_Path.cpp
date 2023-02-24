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
    vector<vi> a(n, vi(n, 0));
    ll sum = 0;
    rep(i, 0, n){
      rep(j, 0, n){
        cin >> a[i][j];
        sum += a[i][j];
      }
    }
    int minV = a[n-1][0];
    rep(i, 0, n) {
      minV = min(minV,a[n-1-i][i]);
    }
    cout << sum - minV;
    return 0;
}