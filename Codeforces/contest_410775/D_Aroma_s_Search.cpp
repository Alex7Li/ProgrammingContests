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

ll dist(ll x0, ll x1, ll y0, ll y1) {
  return abs(x1 - x0) + abs(y1 - y0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    dbg("aha");
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    vector<ll> x;
    vector<ll> y;
    x.push_back(x0);
    y.push_back(y0);
    while(x[x.size() - 1] <= 2.1e16 and y[y.size() - 1] <= 2.1e16) {
      x.push_back(x[x.size() - 1] * ax + bx);
      y.push_back(y[y.size() - 1] * ay + by);
    }
    ll ans = 0;
    for(ll st = 0; st < x.size(); st++) {
      for(ll end = st; end < x.size(); end++) {
        ll diff = dist(x[st], x[end], y[st], y[end]) +
          min(dist(x[st], xs, y[st], ys), dist(x[end], xs, y[end], ys));
        dbg(diff);
        if(diff <= t) {
          ans = max(ans, end - st + 1);
        }
      }
    }
    cout << ans << "\n";
    return 0;
}