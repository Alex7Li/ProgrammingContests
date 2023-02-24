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

struct Cut {
  int v;
  int i;
};

int main() {
// #ifdef LOCAL
//   ifstream cin("case1.in");
// #else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
// #endif
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int m;
    cin >> m;
    vector<int> x(m);
    rep(i, 0, m) { cin >> x[i]; }
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
    vector<Cut> cut_h(n);
    bool possible = true;
    rep(i, 0, n){
      if(a[i] < b[i]) {
        possible = false;
      }
      cut_h[i].v = b[i]; cut_h[i].i = i;
    }
    sort(cut_h.begin(), cut_h.end(), [](const Cut& a_, const Cut& b_) {
      if(a_.v == b_.v) {
        return a_.i < b_.i;
      } else {
        return a_.v > b_.v;
      }
    });
    set<int> done_locs;
    done_locs.insert(1'000'000'001);
    vector<int> req_x;
    int cur_cut_h = cut_h[0].v;
    int cur_cut_st = 0;
    vector<int> cut_locs = {};
    if(a[cut_h[0].i] != b[cut_h[0].i]) {
      cut_locs.push_back(cut_h[0].i);
    }
    for(int i = 1; i < n + 1; i++) {
      if(i == n || cut_h[i].v != cur_cut_h) {
        if(cut_locs.size()) {
          // count required cuts
          req_x.push_back(cur_cut_h); 
          for(int j = 0; j < (int)(cut_locs.size()) - 1; j++) {
            int next_cut = *done_locs.upper_bound(cut_locs[j]);
            if(next_cut < cut_locs[j + 1]) {
              req_x.push_back(cur_cut_h);
            }
          }
        }

        // update done locs
        for(int j = cur_cut_st; j < i; j++) {
          done_locs.insert(cut_h[j].i);
        }
        // reset for next time
        if(i != n) {
          cur_cut_h = cut_h[i].v;
          cur_cut_st = i;
          cut_locs.clear();
        }
      }
      // check if we need to cut here
      if(i != n && a[cut_h[i].i] != b[cut_h[i].i]) {
        cut_locs.push_back(cut_h[i].i);
      }
    }
    x.push_back(-1);
    int x_ind = 0;
    for(int i = 0; i < req_x.size(); i++) {
      while(x_ind < x.size() && req_x[i] != x[x_ind++]) {}
      if(x_ind == x.size()) {
        possible = false;
      }
    }
    if(possible) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
