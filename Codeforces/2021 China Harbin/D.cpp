#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll powtens[19];
int digit(ll x, int position) {
  return (x / powtens[position]) % 10;
}

ll removeDigit(ll x, int position) {
  if(position == 0){
    return x / 10;
  }
  ll low = x % powtens[position];
  ll high = (x / powtens[position + 1]) * powtens[position];
  return low + high;
}

int diglen(ll x){
  for(int i = 0; i < 19; i++){
    if(x < powtens[i]){
      return i;
    }
  }
  return 19;
}

pll dfs(__int128_t num, __int128_t denom, int nLen, int dLen, pll best) {
  // cout << ll(num) << " " << ll(denom)  << "\n";
  rep(i, 0, nLen) {
    rep(j, 0, dLen) {
      if(digit(num,i) == digit(denom, j)){
        __int128_t remN = removeDigit(num, i);
        __int128_t remD = removeDigit(denom, j);
        if(remN * denom == remD * num) {
          if(best.first > remN) {
            dbg(ll(remN));
            best.first = remN;
            best.second = remD;
          }
          best = dfs(remN, remD, nLen - 1, dLen - 1, best);
        }
      }
    }
  }
  return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    powtens[0] = 1LL;
    rep(i, 1, 19) {
      powtens[i] = powtens[i - 1] * 10LL;
    }
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        ll p, q;
        cin >> p >> q;
        pll ans = dfs(p, q, diglen(p), diglen(q), pll(p, q));
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}