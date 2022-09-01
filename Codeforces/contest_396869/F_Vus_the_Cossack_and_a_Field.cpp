#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef vector<ll> vi;

ll is_flip(ll x, ll y){
  ll out = __builtin_popcount(x ^ y) % 2;
  return out;
}

ll query(ll i, ll j, vector<vi>& sqSum, ll n, ll m) {
  ll rowBlocks = i / n;
  ll colBlocks = j / m;
  ll baseSum = (rowBlocks * colBlocks * n * m) / 2;
  ll colSum = ((i - (i % n)) * (j % m)) / 2;
  ll rowSum = ((i % n) * (j - j % m)) / 2;
  ll finSum = sqSum[i % n][j % m];
  if(is_flip(rowBlocks, colBlocks)) {
    finSum = (i % n) * (j % m) - finSum;
  }
  ll ans = baseSum + colSum + rowSum + finSum;
  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vi> M(2 * n, vi(2 * m));
    rep(i, 0, n) {
      string s;
      cin >> s;
      rep(j, 0, m) {
        if(s[j] == '1') {
          M[i][j] = 1;
          M[i + n][j + m] = 1;
        } else {
          M[i + n][j] = 1;
          M[i][j + m] = 1;
        }
      }
    }
    vector<vi> colSum(2 * n + 1, vi(2 * m));
    vector<vi> sqSum(2 * n + 1, vi(2 * m + 1));
    rep(i, 1, 2 * n + 1) {
      colSum[i][0] = M[i - 1][0] + colSum[i - 1][0];
    }
    rep(i, 1, 2 * n + 1) {
      rep(j, 0, 2 * m) {
        colSum[i][j] = colSum[i - 1][j] + M[i - 1][j];
      }
    }
    rep(i, 1, 2 * n + 1) {
      rep(j, 1, 2 * m + 1) {
        sqSum[i][j] = sqSum[i][j - 1] + colSum[i][j - 1];
      }
    }
    rep(i, 0 , q) { 
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      ll ul = query(x1 - 1, y1 - 1, sqSum, 2 * n, 2 * m);
      ll ur =  query(x1 - 1, y2, sqSum, 2 * n, 2 * m);
      ll bl =  query(x2, y1 - 1, sqSum, 2 * n, 2 * m);
      ll br =  query(x2, y2, sqSum, 2 * n, 2 * m);
      ll ans = br + ul - ur - bl;
      cout << ans << "\n";
    }
    return 0;
}