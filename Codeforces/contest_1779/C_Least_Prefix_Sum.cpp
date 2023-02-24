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
    int n, m;
    cin >> n >> m;
    m--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ops = 0;
    ll offset = 0;
    priority_queue<int> pq;
    for (int i = m + 1; i < n; i++) {
      pq.push(-a[i]);
      if (a[i] + offset < 0) {
        ops += 1;
        offset += pq.top() * 2;
        pq.pop();
      }
      offset += a[i];
    }
    offset = 0;
    while(!pq.empty()) {
      pq.pop();
    }
    for (int i = m; i >= 1; i--) {
      pq.push(a[i]);
      if (a[i] + offset > 0) {
        ops += 1;
        offset -= pq.top() * 2;
        pq.pop();
      }
      offset += a[i];
    }
    cout << ops << "\n";
  }
  return 0;
}