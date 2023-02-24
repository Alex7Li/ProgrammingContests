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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

void make_tree(vii& G, int st, set<pii>& used_edges, bool reversed){
  int n = G.size();
  vector<bool> seen(n);
  queue<int> Q;
  Q.push(st);
  seen[st] = true;
  while(!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for(int next : G[cur]){
      if(!seen[next]) {
        seen[next] = true;
        if(reversed){
          used_edges.insert({next, cur});
        } else {
          used_edges.insert({cur, next});
        }
        Q.push(next);
      }
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int n, m;
        cin >> n >> m;
        vii G(n);
        vii Ginv(n);
        rep(i, 0, m){
          int st, end;
          cin >> st >> end;
          st-=1; end-=1;
          G[st].push_back(end);
          Ginv[end].push_back(st);
        }
        set<pii> used_edges;
        make_tree(G, 0, used_edges, false);
        make_tree(Ginv, 0, used_edges, true);
        int to_remove = m - 2 * n;
        for(int i = 0; i < n; i++) {
          for(int j : G[i]) {
            if(to_remove != 0 && used_edges.find({i, j}) == used_edges.end()) {
              cout << i + 1 << " " << j + 1 << "\n";
              to_remove -= 1;
            }
          }
        }
    }
    return 0;
}
