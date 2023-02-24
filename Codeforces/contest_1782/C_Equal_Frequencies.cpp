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

int cost(vi& counts, int reps, int used, vi& order) {
  int good = 0;
  rep(i, 0, used) {
    good += min(counts[order[i]], reps); 
  }
  return reps * used - good;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi counts(26);
    rep(i, 0, sz(s)) {
      int v = s[i] - 'a';
      counts[v]++;
    }
    vi order(26);
    rep(i, 0, 26) {
      order[i] = i;
    }
    sort(order.begin(), order.end(), [counts](int x, int y) {
      return counts[x] > counts[y];
    });
    int best_cost = n;
    int best_reps = n;
    for(int reps = 1; reps <= n; reps++){
      if(n % reps == 0 && n / reps <= 26) {
        int c = cost(counts, reps, n / reps, order);
        if (c < best_cost) {
          best_cost = c;
          best_reps = reps;
        }
      }
    }
    int count = n / best_reps;
    rep(i, 0, 26) {
      counts[i] -= best_reps;
    }
    string still_need;
    string out(n, 'Z');
    rep(i, 0, count) {
      int needed = best_reps;
      rep(j, 0, n) {
        int v = s[j] - 'a';
        if(v == order[i]) {
          out[j] = v + 'a';
          if(--needed == 0) {
            break;
          }
        }
      }
      while(needed--) {
        char add = 'a' + order[i];
        cerr << order[i] << add << "\n";
        still_need += add;
      }
    }
    int bad = 0;
    rep(j, 0, n){
      if(out[j] == 'Z') {
        assert(sz(still_need));
        out[j] = still_need[still_need.size() - 1];
        still_need.pop_back();
        bad++;
      }
    }
    assert(bad == best_cost);
    cout << best_cost << "\n" << out << "\n";


  }
  return 0;
}