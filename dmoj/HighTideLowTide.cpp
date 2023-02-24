//https://dmoj.ca/problem/ccc17s2
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
  vi a(n);
  vi res(n);
  rep(i, 0, n) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int last = ((n - 1)/ 2) * 2;
  int cur = 0;
  while(last > 0) {
    res[last] = a[cur++];
    last -= 2;
  }
  res[last] = a[cur++];
  last++;
  while(last < n) {
    res[last] = a[cur++];
    last += 2;
  }
  rep(i, 0, n){
    cout << res[i] << " ";
  }
  return 0;
}