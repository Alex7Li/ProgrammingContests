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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vi a;
  int x;
  while(cin >> x) {
    a.push_back(x);
  }
  int n = a.size();
  // calc count
  set<pii> vals;
  vals.insert({a[0], 0});
  rep(i, 1, n) {
    auto next = vals.lower_bound({a[i], -1});
    if(next == vals.end()){
      vals.insert({a[i], vals.size()});
    } else {
      pii new_val = {a[i], next->second};
      vals.erase(next);
      vals.insert(new_val);
    }
  }

  vector<vector<int>> count(2, vi(50002, 0));
  rep(i, 0, n) {
    int ind = i % 2;
    rep(j, 0, sz(count[0])) {
      count[ind][j] = count[ind ^ 1][j];
    }
    rep(j, a[i], sz(count[0])) {
      count[ind][a[i]] = max(count[ind ^ 1][j] + 1, count[ind][a[i]]);
    }
  }
  int best = 0;
  rep(j, 0, sz(count[0])) {
    best = max(best, count[(n - 1) % 2][j]);
  }
  cout << best << "\n" << sz(vals) << "\n"; 
  return 0;
}
