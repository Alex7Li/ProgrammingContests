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

bool works(int p, vi& psum, int n, int t) {
  if(p > n) {
    return false;
  }
  rep(i, 0, n - p + 1) {
    if(psum[i + p] - psum[i] <= t) {
      return true;
    }
  }
  return false;
}
int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, t;
  cin >> n >> t;
  vi a(2 * n);
  rep(i, 0, n) {
    cin >> a[i];
    a[n + i] = a[i];
  }
  vi psum(2 * n + 1);
  rep(i, 0, 2 * n){
    psum[i + 1] = psum[i] + a[i];
  }
  int l = 0;
  for(int inc = 1 << 30; inc > 0; inc /= 2) {
    int p = inc + l;
    if(works(p, psum, n, t)) {
      l = p;
    }
  }
  cout << l;

  return 0;
}