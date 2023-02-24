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
  int n, k;
  cin >> n >> k;
  vector<bitset<1024>> prev(n);
  bitset<1024> done;
  rep(tt, 0, k) {
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      if(i > 0) {
        prev[a[i]].set(a[i - 1]);
      }
      if(i == 0 || i == n) {
        prev[a[i]].set(999);
      }
    }
  }
  vi parent(n, -2);
  while(done.count() != n - 1) {
    rep(i, 0, n) {
      if(done[i] | prev[i][999]) {
        continue;
      }
      if (prev[i].count() == 2) {
        vi children;
        rep(c, 0, n) {
          if (prev[i][c]) {
            children.push_back(c);
          }
        }
        for (int c: children) {
            // the parent of c is i
            done[c] = true;
            parent[c] = i;
            rep(j, 0, n) {
              prev[j].set(i, prev[j][i] | prev[j][c]);
              prev[j].reset(c);
            }
        }
      }
    }
  }
  cout << (parent[0] + 1);
  for(int i = 1; i < parent.size(); i++){
    cout << " " << (parent[i] + 1);
  }
  return 0;
}
