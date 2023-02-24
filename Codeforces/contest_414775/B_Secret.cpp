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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi p(n);
    rep(i, 0, n) {
      cin >> p[i];
      if(p[i] == -1){
        p[i]++;
      }
    }
    vector<vi> G(n + 1);
    rep(i, 0, n){
      G[p[i]].push_back(i + 1);
    }
    vector<int> d(n + 1);
    vector<int> h(n + 1);
    h[0] = 1;
    queue<pii> Q;
    Q.push({0, 1});
    int maxD = 1;
    while(!Q.empty()) {
      pii t = Q.front();
      Q.pop();
      maxD = max(maxD, t.second);
      for(int next: G[t.first]) {
        if(h[next] != -1) {
          h[next] = t.second + 1;
          Q.push({next, t.second + 1});
        }
      }
    }
    cout << maxD - 1 << "\n";
    return 0;
}