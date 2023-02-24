#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
  #pragma GCC optimize("trapv") // signed overflow => RE
#else
  // #pragma GCC target("arch=skylake") // CF only
#endif


vi safe_values(int ind, vi& threePow) {
  vi ans(1 << ind);
  return ans;
}

ll gcd(int x, int y) {
  if(x == 0) {
    return y;
  }
  return gcd(y, x % y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> threePow(21);
  threePow[0]  = 1;
  rep(i, 1, sz(threePow)) {
    threePow[i] = threePow[i - 1] * 3;
  }
  set<ll> ans;
  ll factor = 1;
  for(int top_ind = 0; n % threePow[top_ind] == 0; top_ind++) {
    // int sub1 = threePow[top_ind] - 1;
    for(int i = 0; i < 1 << top_ind; i++) {
      int value = 0;
      int min_nonzero = top_ind;
      for(int j = 0; j < top_ind; j++) {
        if((i >> j) % 2) {
          value += threePow[j] * 2;
          min_nonzero = min(min_nonzero, j);
        }
      }
      ans.insert(value);
      if (top_ind != min_nonzero) {
        ans.insert(value - threePow[min_nonzero]);
      } else {
        ans.insert(n);
      }
    }
    factor = n / threePow[top_ind];
  }
  set<ll> ans2;
  for(ll x: ans2) {
    ans2.insert(x * factor);
  }
  for(int top_ind = 1; top_ind < 20; top_ind++) {
    if(top_ind % 3 == 0) {
      
    }
  }
  for(int i : ans) {
    cout << i << "\n";
  }
  return 0;
}
