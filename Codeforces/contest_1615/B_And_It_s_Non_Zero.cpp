#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  vi cnt(20);
  vector<vi> pSum(20, vi(200'002, 0));
  for (int i = 0; i < 20; i++) {
    for (int j = 1; j < 200'002; j++) {
      if(j & ((1<<i))){
        pSum[i][j]+=1;
      }
    }
  }
  for(int i = 0; i < 20; i++) {
      for(int j = 1; j < 200'002; j++){
        pSum[i][j] = pSum[i][j - 1] + pSum[i][j];
      }
  }  
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int l, r;
    cin >> l >> r;
    int M = int(log2(r)) + 1;
    vi d(M);
    for(int i = 0; i < M; i++) {
        d[i] = pSum[i][r] - pSum[i][l-1];
    }
    int best = r - l + 1;
    for(int i = 0; i < M; i++) {
        best = min(best, r - l + 1 - d[i]);
    }  
    cout << best << "\n";
  }
  return 0;
}