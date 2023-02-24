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

struct SegTree {
  SegTree* lTree;
  SegTree* rTree;
  int l;
  int mid;
  int r;
  int sumVal = 0;

  SegTree(int l_, int r_) {
    l = l_; r = r_;
    mid = (r + l) / 2;
    if(r - l > 1) {
      mid = (r + l) / 2;
      lTree = new SegTree(l, mid);
      rTree = new SegTree(mid, r);
    }
  }

  void add(int x) {
    sumVal++;
    if(r - l == 1) {
      return;
    }
    if(x < mid) {
      lTree->add(x);
    } else {
      rTree->add(x);
    }
  }

  int sum_under(int x) {
    int res = 0;
    if(r - l == 1) {
      return 0;
    }
    if(x < mid) {
      res += lTree->sum_under(x);
    } else {
      res += lTree->sumVal;
      res += rTree->sum_under(x);
    }
    return res;
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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
      cin >> a[i];
    }
    vi pLess(n + 1);
    rep(i, 0, n) {
      pLess[i + 1] = pLess[i];
      if(a[i] <= i) {
        pLess[i + 1]++;
      }
    }
    ll ans = 0;
    rep(i, 0, a.size()) {
      if(1 <= a[i] && a[i] <= i) {
        ans += pLess[a[i] - 1];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}