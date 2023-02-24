#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
#pragma GCC optimize("trapv")  // signed overflow => RE
#else
#pragma GCC target("arch=skylake")  // CF only
#endif

vector<ll> offsets(ll lo, ll hi) {
  ll d = hi - lo;
  vector<ll> ans;
  for(ll factor = 1; factor * factor <= d; factor++) {
    if(d % factor == 0) {
      ll other_f = d / factor;
      assert(other_f >= factor);
      if ((other_f + factor) % 2 == 0) {
        ll a = (other_f + factor) / 2;
        ll b = (other_f - factor) / 2;
        ll bb = b * b;
        ll aa = a * a;
        assert(aa - bb == d);
        assert(aa - hi == bb - lo);
        if(aa >= hi) {
          ans.push_back(aa - hi);
        }
      }
    }
  }
  return ans;
}


bool isSquare(ll e) {
  ll sqr = sqrtl(e);
  return sqr * sqr == e;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) { cin >> a[i]; }
    sort(a.begin(), a.end());
    int repeats = 1;
    int max_repeats = 1;
    rep(i, 1, n){
      if(a[i] == a[i - 1]) {
        repeats += 1;
        max_repeats = max(repeats, max_repeats);
      } else {
        repeats = 1;
      }
    }
    ll best = max_repeats;
    rep(i, 0, n) {
      rep(j, i + 1, n) {
        vector<ll> offs = offsets(a[i], a[j]);
        for (ll x : offs) {
          ll count = 0;
          rep(k, 0, n) {
            if (isSquare(a[k] + x)) {
              count++;
            }
          }
          best = max(best, count);
        }
      }
    }
    cout << best << "\n";
  }

  return 0;
}