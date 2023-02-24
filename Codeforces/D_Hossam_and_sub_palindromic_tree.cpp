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

struct EdgePath {
  int v1;
  int v2;
  int p1;
  int p2;
};

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
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<vi> G(n);
    queue<EdgePath> Q;
    vector<vi> cache(n, vi(n));
    rep(i, 0, n) {
      cache[i][i] = 1;
    }
    for(int i = 0; i < n - 1; i++) {
      int from, to;
      cin >> from >> to;
      from--; to--; // 0 indexed
      G[to].push_back(from);
      G[from].push_back(to); // undirected
      Q.push({to, from, from, to});
      cache[to][from] = -1;
      cache[from][to] = -1;
    }
    while(!Q.empty()) {
      EdgePath e = Q.front();
      Q.pop();
      assert(e.v1 != e.v2);
      cache[e.v1][e.v2] = max(cache[e.v1][e.p2], cache[e.p1][e.v2]);
      if(s[e.v1] == s[e.v2]) {
        if(e.v1 == e.p2) {
          cache[e.v1][e.v2] = 2; 
        } else {
          cache[e.v1][e.v2] = max(cache[e.v1][e.v2], 2 + cache[e.p1][e.p2]); 
        }
      }
      cache[e.v2][e.v1] = cache[e.v1][e.v2];
      for(int n_v1: G[e.v1]) {
        if(!cache[n_v1][e.v2]) {
          cache[n_v1][e.v2] = cache[e.v2][n_v1] = -1;
          Q.push({n_v1, e.v2, e.v1, e.p2});
        }
      }
      for(int n_v2: G[e.v2]) {
        if(!cache[e.v1][n_v2]) {
          cache[e.v1][n_v2] = cache[n_v2][e.v1] = -1;
          Q.push({e.v1, n_v2, e.p1, e.v2});
        }
      }
    }

    // print answer
    int best = 0;
    rep(i, 0, n) {
      rep(j, i, n) {
        best = max(best, cache[i][j]);
      }
    }
    cout << best << "\n";
  }
  return 0;
}