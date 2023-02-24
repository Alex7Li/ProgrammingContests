#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
  int n;
  vi a;
  Tree(int n) : n(n) { a = vi(2 * n); };
  void add_to_interval(int l, int v) {
    for (l += n; l != 0; l >>= 1) {
      a[l] += v;
    }
  }
  int query_interval(int l, int r) {
    int sum = 0;
    for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
      if (l % 2 == 1) {
        sum += a[l++];
      }
      if (r % 2 == 1) {
        sum += a[--r];
      }
      assert(l <= r);
    }
    return sum;
  }
};

// https://cses.fi/problemset/task/1740
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  // (x_coord, (y_coord, 1 if start else -1))
  vector<pair<int, pii>> hlines;
  // (x_coord, lower y, higher y)
  vector<pair<int, pii>> vlines;
  rep(i, 0, n) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1e6;
    x2 += 1e6;
    y1 += 1e6;
    y2 += 1e6;
    if (y1 == y2) {
        if(x1 > x2) {
            swap(x1, x2);
        }
      hlines.push_back({x1, {y1, 1}});
      hlines.push_back({x2, {y2, -1}});
    } else {
      assert(x1 == x2);
        if(y1 > y2) {
            swap(y1, y2);
        }
      vlines.push_back({x1, {y1, y2}});
    }
  }
  sort(hlines.begin(), hlines.end());
  sort(vlines.begin(), vlines.end());
  if (hlines.size() == 0) {
    cout << 0 << endl;
    exit(0);
  }
  int hind = 0;
  int next_upd_t = hlines[hind].first;
  ll ans = 0;
  Tree tree(2e6 + 5);
  for (auto line : vlines) {
    while (hind < hlines.size() && line.first > next_upd_t) {
        // update ds
        tree.add_to_interval(hlines[hind].second.first, hlines[hind].second.second);
        next_upd_t = hlines[++hind].first;
    }
    // perform query
    ans += tree.query_interval(line.second.first,
                                line.second.second + 1);
  }
  cout << ans << "\n";
  return 0;
}