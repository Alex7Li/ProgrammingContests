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

struct RainEvent {
  int grow;
  ll pos;
  bool operator< (const RainEvent& o) const {
    if(o.pos == pos) {
      return grow > o.grow;
    } else {
      return pos > o.pos;
    }
  }
};

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
    ll n, m;
    cin >> n >> m;
    vector<ll> xs(n);
    vector<ll> ps(n);
    priority_queue<RainEvent> Q;
    rep(i, 0, n){
      cin >> xs[i] >> ps[i];
      Q.push(RainEvent({1, xs[i] - ps[i]}));
      Q.push(RainEvent({-2, xs[i]}));
      Q.push(RainEvent({1, xs[i] + ps[i]}));
    }
    ll MIN_V = -2e10;
    ll min_rpx = MIN_V;
    ll min_rmx = MIN_V;
    ll sweep_pos = MIN_V;
    ll h = 0;
    ll slope = 0;
    while(!Q.empty()) {
      RainEvent e = Q.top();
      Q.pop();
      h += slope * (e.pos - sweep_pos);
      assert(h >= 0);
      if (h > m) {
        min_rpx = max(min_rpx, h + e.pos);
        min_rmx = max(min_rmx, h - e.pos);
      }
      // cerr << h _ e.pos _ (h + e.pos) _ (h - e.pos) _ "\n";
      sweep_pos = e.pos;
      slope += e.grow;
    }
    rep(i, 0, n) {
      if(ps[i] - xs[i] + m >= min_rmx && 
         ps[i] + xs[i] + m >= min_rpx) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << "\n";
  }
  return 0;
}