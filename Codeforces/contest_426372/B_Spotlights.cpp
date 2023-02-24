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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vi> a(n, vi(m));
  rep(i, 0, n) {
    rep(j, 0, m) { cin >> a[i][j]; }
  }
  int c = 0;
  rep(i, 0, n) {
    int s = 0;
    rep(j, 0, m) {
      if (s > 0 && !a[i][j]) {
        c++;
      }
      s += a[i][j];
    }
  }
  rep(j, 0, m) {
    int s = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s > 0 && !a[i][j]) {
        c++;
      }
      s += a[i][j];
    }
  }
  rep(j, 0, m) {
    int s = 0;
    rep(i, 0, n) {
      if (s > 0 && !a[i][j]) {
        c++;
      }
      s += a[i][j];
    }
  }
  rep(i, 0, n) {
    int s = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (s > 0 && !a[i][j]) {
        c++;
      }
      s += a[i][j];
    }
  }
  cout << c;
  return 0;
}