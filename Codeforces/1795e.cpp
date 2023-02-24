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
typedef vector<ll> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#pragma GCC optimize("trapv")  // signed overflow => RE
#ifdef LOCAL
#else
#pragma GCC target("arch=skylake")  // CF only
#endif

ll sumFrom(ll lo, ll hi) {
  // lo + ... + (hi - 1)
  return (hi * (hi - 1)) / 2 - (lo * (lo - 1)) / 2;
}

vi get_l_gain(vi& h) {
  int n = sz(h);
  vi l_gain(n);
  vector<int> order(n);
  rep(i, 0, n) { order[i] = i; }
  stable_sort(order.begin(), order.end(),
       [&h](int a, int b) { return h[a] - a < h[b] - b; });
  set<int> seen;
  for (int i : order) {
    auto x = seen.lower_bound(i);
    if (x == seen.begin()) {
      l_gain[i] = sumFrom(max(0ll, h[i] - i), h[i]);
    } else {
      x--;
      int st_ind = *x;
      int dist = i - st_ind - 1;
      l_gain[i] =
          sumFrom(h[i] - dist, h[i]) + l_gain[st_ind] + h[st_ind];
    }
    seen.insert(i);
  }
  return l_gain;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vi h(n);
    ll S = 0;
    rep(i, 0, n) {
      cin >> h[i];
      S += h[i];
    }
    vi l_gain = get_l_gain(h);
    reverse(h.begin(), h.end());
    vi r_gain = get_l_gain(h);
    reverse(r_gain.begin(), r_gain.end());
    ll M = 0;
    rep(i, 0, n) { M = max(M, l_gain[i] + r_gain[i]); }
    cout << S - M << endl;
  }
  return 0;
}

/*
10
8
50 50 50 50 10 1000 1000 1000
*/
