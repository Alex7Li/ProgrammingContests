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
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n;
  cin >> n;
  ll ans = 0;
  vector<ll> b;
  rep(i, 0, n) {
    int a;
    cin >> a;
    if(a % 2 == 0) {
      ans += max(a, 0);
    } else {
      b.push_back(a);
    }
  }
  sort(b.rbegin(), b.rend());
  ll extra = b[0];
  for(int i = 2; i < b.size(); i += 2) {
    extra = max(extra, extra + b[i - 1] + b[i]);
  }
  cout << extra + ans;
  return 0;
}