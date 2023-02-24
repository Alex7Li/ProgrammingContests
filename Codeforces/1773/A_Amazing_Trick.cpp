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

// start is just heuristic for speed, not needed
bool match(int from, int start, vi& a_inv, vi& l, vi& r,
  vector<bool> seen) {
  if(seen[from]){
    return false;
  }
  seen[from] = true;
  for(int to = start; to <= start + a_inv.size(); to++) {
    int adj = to % a_inv.size();
    if (adj != from && adj != a_inv[from]) {
      if(r[adj] == -1 || match(r[adj], start, a_inv, l, r, seen)) {
        l[from] = adj;
        r[adj] = from;
        return true;
      }
    }
  }
  return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
      int n;
      cin >> n;
      vector<int> a(n);
      vector<int> a_inv(n);
      for(int i = 0; i < n; i++) {
        cin >> a[i];
        a_inv[--a[i]] = i;
      }
      vi l(n, -1);
      vi r(n, -1);
      unordered_set<int> not_taken(n);
      rep(i, 0, n) {
        not_taken.insert(i);
      }
      rep(i, 0, n - 2) {
        // Note: at most 3 reps per element
        for(int x: not_taken) {
          if(x != i && x != a_inv[i]) {
            l[i] = x;
            r[x] = i;
            not_taken.erase(x);
            break;
          }
        }
      }
      int ind = max(0, n - 2);
      bool possible = true;
      for(int x: not_taken) {
        vector<bool> seen(n);
        possible &= match(ind++, x, a_inv, l, r, seen);
      }
      if(!possible) {
        cout << "Impossible\n";
      } else {
        cout << "Possible\n";
        vi p(n);
        rep(i, 0, n){
          p[l[i]] = a_inv[i];
        }
        rep(i, 0, n){
          assert(a[p[l[i]]] == i);
        }
        rep(i, 0, n - 1){
          cout << ++p[i] << " ";
        }
        cout << ++p[n - 1] << "\n";
        rep(i, 0, n - 1){
          cout << ++l[i] << " ";
        }
        cout << ++l[n - 1] << "\n";
      }
    }
    return 0;
}
