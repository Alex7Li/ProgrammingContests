#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
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

int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n;
  vector<vi> boxes(n, vi(3));
  rep(i, 0, n) {
    cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
    sort(boxes[i].begin(), boxes[i].end());
  }
  cin >> m;
  vector<vi> items(m, vi(3));
  rep(i, 0, m) {
    cin >> items[i][0] >> items[i][1] >> items[i][2];
    sort(items[i].begin(), items[i].end());
  }
  rep(i, 0, m) {
    int best = 2e9;
    int best_ind = -1;
    rep(j, 0, n) {
      if (items[i][0] <= boxes[j][0] &&
          items[i][1] <= boxes[j][1] && items[i][2] <= boxes[j][2]) {
            if(best > (boxes[j][0] * boxes[j][1] * boxes[j][2])) {
              best = (boxes[j][0] * boxes[j][1] * boxes[j][2]);
              best_ind = j;
            }
      }
    }
    if (best_ind == -1) {
      cout << "Item does not fit.\n";
    } else {
      cout << best << "\n";
    }
  }
  return 0;
}
