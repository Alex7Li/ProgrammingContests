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
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n;
  vi a(2001);
  cin >> n;
  rep(i, 0, n) {
    int x;
    cin >> x;
    a[x]++;
  }
  int best_score = 0;
  int n_best = 1;
  rep(j, 1, 4001) {
    int count = 0;
    rep(k, 1, min(2001, j)) {
      int other = j - k;
      if(other > k) {
        continue;
      }
      if(other == k) {
        count += a[k] / 2;
      } else {
        count += min(a[k], a[other]);
      }
    }
    if(count > best_score) {
      best_score = count;
      n_best = 0;
    }
    if(count == best_score) {
      n_best++;
    }
  }
  cout << best_score << " " << n_best;
  return 0;
}
