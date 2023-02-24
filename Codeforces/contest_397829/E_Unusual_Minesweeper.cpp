#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, k;
    cin >> n >> k;
    hash_map<int, vii> rowMap;
    hash_map<int, vii> colMap;
    vector<vi> G(n);
    vector<int> times(n);
    rep(i, 0, n) {
      int r, c;
      cin >> r >> c >> times[i];
      rowMap[r].push_back({c, i});
      colMap[c].push_back({r, i});
    }
    vector<hash_map<int, vii>> maps = {rowMap, colMap};
    for (auto ordinalMap : maps) {
      for (auto x : ordinalMap) {
        if(x.second.size() <= 1){
          continue;
        }
        sort(x.second.begin(), x.second.end());
        rep(i, 0, x.second.size() - 1) {
          if (x.second[i + 1].first - x.second[i].first <= k) {
            int ind1 = x.second[i + 1].second;
            int ind2 = x.second[i].second;
            G[ind1].push_back(ind2);
            G[ind2].push_back(ind1);
          }
        }
      }
    }
    vi cc_times;
    vector<bool> in_cc(n);
    for (int i = 0; i < n; i++) {
      if (!in_cc[i]) {
        queue<int> to_visit;
        to_visit.push(i);
        int boomT = times[i];
        in_cc[i] = true;
        while(!to_visit.empty()) {
          boomT = min(boomT, times[to_visit.front()]);
          for (int next : G[to_visit.front()]) {
            if (!in_cc[next]) {
              in_cc[next] = true;
              to_visit.push(next);
            }
          }
          to_visit.pop();
        }
        cc_times.push_back(boomT);
      }
    }
    sort(cc_times.begin(), cc_times.end());
    int ans = cc_times.size() - 1;
    for (int i = 0; i < cc_times.size() - 1; i++) {
        ans = min(ans, max(cc_times[cc_times.size() - 2 - i], i));
    }
    if(cc_times.size() <= 1) {
      ans = 0;
    }
    cout << ans << "\n";
  }
  return 0;
}
