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
typedef vector<int> vi;

pair<bool, int> works(int T, vi& x, vi& t) {
  int l = 0;
  int r = 1e9;
  for(int i = 0; i < x.size(); i++){
    int dx = T - t[i];
    if(dx < 0) {
      return {false, -1};
    }
    int new_l = x[i] - dx;
    int new_r = x[i] + dx;
    l = max(l, new_l);
    r = min(r, new_r);
  }
  return {l <= r, l};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int n;
        cin >> n;
        vi x(n);
        vi t(n);
        rep(i, 0, n) {
          cin >> x[i];
          x[i] *= 2;
        }
        rep(i, 0, n) {
          cin >> t[i];
          t[i] *= 2;
        }
        double ans = -1;
        int r = (1 << 29) - 1;
        for(int dr = 1 << 28; dr != 0; dr /= 2){
          auto w = works(r - dr, x, t);
          if(w.first) {
            r = r - dr;
            ans = w.second / 2.0;
          } else {
            works(r - dr, x, t);
          }
        }
        printf("%.1f\n", ans);
    }
    return 0;
}