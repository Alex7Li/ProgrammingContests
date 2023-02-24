#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;
typedef vector<int> vi;

piii solve(vi& all, int bit){
  if(bit > 31 || sz(all) == 0){
    return {0,-2, -2};
  }
  int pow = 1 << bit;
  int mask = pow - 1;
  vi one;
  vi zero;
  int maxOne = 0;
  int maxZero = 0;
  int maxOneInd = -1;
  int maxZeroInd = -1;
  rep(i, 0, all.size()) {
    if(all[i] & pow) {
      one.push_back(i); 
      // Wrong operation the code is broke
      int oneScore = __builtin_popcount(all[i] - (all[i] & mask));
      if (oneScore > maxOne) {
        maxOne = oneScore;
        maxOneInd = i;
      }
    } else {
      zero.push_back(i);
      // Wrong operation the code is broke
      int zeroScore = max(maxZero, __builtin_popcount(all[i]));
      if (zeroScore > maxZero) {
        maxZero = zeroScore;
        maxZeroInd = i;
      }
    }
  }
  piii ans = {maxOne + maxZero, maxZeroInd, maxOneInd};
  piii left = solve(one, bit + 1);
  piii right = solve(zero, bit + 1);
  if(get<0>(ans) > get<0>(left)) {
    ans = left;
  }
  if(get<0>(ans) > get<0>(right)) { 
    ans = right;
  }
  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
      cin >> a[i];
    }
    piii ans = solve(a, 0);
    cout << get<1>(ans) << " " << get<2>(ans) << " " << get<0>(ans);
    return 0;
}