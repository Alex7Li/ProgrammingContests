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
  pii cd = {2, 27};
  pair<int, pii> cur_date = {2007 - 18, cd};
  for(int i = 0; i < n; i++) {
    pair<int, pii> the_day;
    cin >> the_day.first >> the_day.second.first >> the_day.second.second;
    if(the_day <= cur_date) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}