#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

vi longest_common_prefix(string s){
  int n = s.size();
  vi lcp(n);
  int i = 1;
  lcp[0] = n;
  while(i < n) {
    if(s[i] != s[0]){
      i++;
      continue;
    }
    int offset = lcp[i];
    while(i + offset < n && s[i + offset] == s[offset]) {
      offset++;
    }
    lcp[i] = offset;
    bool broke = false;
    for(int j = 1; j < offset; j++) {
      lcp[i + j] = lcp[j];
      if(i + j + lcp[i + j] >= i + offset) {
        lcp[i + j] = offset - j;
        i = i + j;
        broke = true;
        break;
      }
    }
    if (not broke){
      i = i + offset;
    }
  }
  return lcp;
}
vi Z(string S) {
  int n = S.size();
  vi z(n);
  int l = -1, r = -1;
  rep(i,1,n) {
      z[i] = i >= r ? 0 : min(r - i, z[i - l]);
      while (i + z[i] < n && S[i + z[i]] == S[z[i]])
          z[i]++;
      if (i + z[i] > r)
          l = i, r = i + z[i];
  }
  return z;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    vi lcp = longest_common_prefix(s);
    for(int i = 1; i < n; i++) {
      if(i + lcp[i] == n) {
        if (n % i == 0){
          ans = n / i;
          break;
        }
      }
    }
    std::cout << ans;
    return 0;
}