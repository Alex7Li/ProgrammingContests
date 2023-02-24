#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

char toc(int x) {
  return 'a' + x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  bool didswap = false;
  bool impossible = false;
  if (c == m) {
    didswap = true;
    swap(n, m);
    swap(r, c);
  }
  vector<vector<int>> grid(n, vi(m));
  if(r != n) {
    rep(i, 0, n) {
      grid[i][0] = 4;
    }
    rep(i, 0, m) {
      grid[0][i] = 4;
    }
    grid[0][0] = 5;
    // check if r = 0 or c = 0
    rep(i, 0, n){
      rep(j, 0, m) {
        if(i < r || j < c) {
          grid[i][j] = 1;
        }
      }
    }
  } else {
    if(m % 2 == 0 && c % 2 == 1) {
      impossible = true;
    } else {
      rep(i, 0, m) {
        grid[0][i] = 10;
      }
      rep(j, 0, c / 2) {
        rep(i, 0, n) {
          grid[i][j] = 1;
          grid[i][m - j - 1] = 1;
        }
      }
      if (c % 2 == 1) {
        rep(i, 0, n) {
          grid[i][m / 2] = 1;
        }
      }
    }
  }
  if(impossible) {
    cout << "IMPOSSIBLE\n";
  } else if(didswap) {
    rep(i, 0, m) {
      rep(j, 0, n){
        cout << toc(grid[j][i]);
      }
      cout << "\n";
    }
  } else {
    rep(i, 0, n) {
      rep(j, 0, m){
        cout << toc(grid[i][j]);
      }
      cout << "\n";
    }
  }
  return 0;
}