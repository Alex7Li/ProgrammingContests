#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define MOD 998244353LL

vi Z(string S) {
  vi z(sz(S));
  int l = -1, r = -1;
  rep(i, 1, sz(S)) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
      z[i]++;
    if (i + z[i] > r)
      l = i, r = i + z[i];
  }
  return z;
}
vi kmp(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}
vi match(const string &pat, const string &s, bool prefix) {
  string x = pat + "@" + s;
  vi d;
  if (prefix)
  {
    d = Z(x);
  }
  else
  {
    d = kmp(x);
  }
  vi suffix_match(s.length());
  for (int i = 0; i < s.length(); i++) {
    suffix_match[i] = d[i + pat.length() + 1];
  }
  return suffix_match;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a, l, r;
  cin >> a >> l >> r;
  vi lprefix = match(l, a, true);
  vi rprefix = match(r, a, true);
  vll dp(a.size() + 1);
  dp[0] = 1;
  vll pSum(a.size() + 2);
  pSum[0] = 0;
  pSum[1] = dp[0];
  for (int i = 0; i < a.size(); i++) {
    if (i + 1 >= l.size()) {
      // if (a[i] == '0') {
      //   if (l.size() == 1 && l[0] == '0') {
      //     dp[i + 1] = dp[i];
      //   }
      // } else {
        // check the L bound
        int lind = i - l.size() + 1;
        if (lprefix[lind] == l.size() ||
            a[lind + lprefix[lind]] >= l[lprefix[lind]]) {
          if (r.size() == l.size()) {
            int rind = lind;
            if (rind < 0 || rprefix[rind] == r.size() ||
                a[rind + rprefix[rind]] <= r[rprefix[rind]]) {
              dp[i + 1] = (dp[i + 1] + dp[rind]) % MOD;
            }
          } else {
            dp[i + 1] = (dp[i + 1] + dp[lind]) % MOD;
          }
        }
      // }
      int rind = i - r.size() + 1; // todo overflow?
      if (r.size() - l.size() >= 1 && i + 1 >= r.size()
          && a[rind] != '0') {
        // check the R bound
        if (rind < 0 || rprefix[rind] == r.size() ||
            a[rind + rprefix[rind]] <= r[rprefix[rind]]) {
          dp[i + 1] = (dp[i + 1] + dp[rind]) % MOD;
        }
      }
      // get the middle
      int rBound = max(0, (int)(i - r.size() + 2));
      int lBound = i - l.size() + 1;
      if(lBound > rBound) {
        dp[i + 1] = (dp[i + 1] + pSum[lBound] - pSum[rBound]) % MOD;
      }
    }
    pSum[i + 2] = pSum[i + 1];
    if (i +1 < a.length() && a[i + 1] != '0')
    {
      pSum[i + 2] = (pSum[i + 2] + dp[i + 1])  % MOD;
    }
  }
  // for (int i = 0; i < dp.size(); i++) {
  //   cout << dp[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i < pSum.size(); i++) {
  //   cout << pSum[i] << " ";
  // }
  // cout << "\n";
  cout << (dp[a.size()] + MOD) % MOD;
  return 0;
}
