#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi top(n);
  vi bot(n);
  rep(i, 0, n) { cin >> top[i]; }
  rep(i, 0, n) { cin >> bot[i]; }
  int count = top[0] + top[n - 1] + bot[0] + bot[n - 1];
  rep(i, 0, n) {
    if (i % 2 == 0) {
      if (top[i] ^ bot[i]) {
        count += 1;
      }
    } else {
      count += top[i] + bot[i];
    }
  }
  rep(i, 0, n - 1) {
    if (top[i] ^ top[i + 1]) {
      count += 1;
    }
    if (bot[i] ^ bot[i + 1]) {
      count += 1;
    }
  }
  cout << count << "\n";
  return 0;
}