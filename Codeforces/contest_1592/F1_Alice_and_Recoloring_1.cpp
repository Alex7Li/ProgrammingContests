# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve(vector<vector<int>> g, int n, int m){
  vector<int> nextRow(n);
  int count = 0;
  for(int i = n - 1; i >= 0; i--){
    for(int j = m - 1; j >= 0; j--){
      if(g[i][j] ^ (nextRow[j])){
        count++;
        //cout << i << " " << j << endl;
        for(int k = 0; k <= j; k++) {
          nextRow[k] ^= 1;
        }
      }
    }
  }
  return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      for(int j = 0; j < m; j++){
        g[i][j] = s[j] == 'B';
      }
    }
    cout << solve(g, n, m);
    return 0;
}