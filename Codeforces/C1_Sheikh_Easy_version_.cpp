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
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<ll> psum(n + 1);
    vector<int> pxor(n + 1);
    vector<int> next(n);
    vector<int> prev(n);
    for(int i = 1; i <= n; i++) {
      psum[i] = psum[i - 1] + a[i - 1];
      pxor[i] = pxor[i - 1] ^ a[i - 1];
    }
    prev[0] = -1;
    for(int i = 1; i < n; i++) {
      if(a[i - 1] == 0) {
        prev[i] = prev[i - 1];
      } else {
        prev[i] = i - 1;
      }
    }
    next[n - 1] = n;
    for(int i = n - 2; i >= 0; i--) {
      if(a[i + 1] == 0) {
        next[i] = next[i + 1];
      } else {
        next[i] = i + 1;
      }
    }
    auto score = [&psum, &pxor](int l, int r) -> ll{
      return (psum[r + 1] - psum[l]) - (pxor[r + 1] ^ pxor[l]);
    };
    for(int i = 0; i < q; i++) {
      int L, R;
      cin >> L >> R;
      L--; R--;
      pair<ll, int> best_score = {0, 0};
      pair<int, int> best_ans = {L, L};
      vi l_pos = {};
      vi r_pos = {};

      int cur_l = L;
      int bound = 32;
      while(cur_l < R && l_pos.size() <= bound) {
        l_pos.push_back(cur_l);
        cur_l = next[cur_l];
      }

      int cur_r = R;
      while(cur_r > L && r_pos.size() < bound) {
        r_pos.push_back(cur_r);
        cur_r = prev[cur_r];
     }

      for(int l : l_pos) {
        for(int r : r_pos) {
          if(l < r) {
            pair<ll, int> this_score = {score(l, r), l - r};
            if(this_score > best_score) {
              best_score = this_score;
              best_ans = {l, r};
            }
          }
        }
      }
      cout << (best_ans.first + 1) << " " << (best_ans.second + 1) << "\n";
    }
  }
  return 0;
}
