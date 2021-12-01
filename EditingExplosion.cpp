// https://open.kattis.com/contests/nac20open/problems/editingexplosion
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int levD(string a, string b) {
  vector<vi> table(a.size() + 1, vi(b.size() + 1, a.size() + b.size()));
  for (int i = 0; i <= a.size(); i++) {
    table[i][0] = i;
  }
  for (int i = 0; i <= b.size(); i++) {
    table[0][i] = i;
  }
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        // just concat
        table[i][j] = table[i - 1][j - 1];
      }
      // add or remove letter
      table[i][j] = min(table[i][j], table[i - 1][j] + 1);
      table[i][j] = min(table[i][j], table[i][j - 1] + 1);
        // edit letter
      table[i][j] = min(table[i][j], table[i - 1][j - 1] + 1);
    }
  }
  return table[a.size()][b.size()];
}
const bool test = false;
const ll MOD = 998'244'353;
ll solve(string s, int d)
{
  vector<vector<vi>> ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if(test){
    while(true){
      string a, b;
      cin >> a >> b;
      cout << "Distance: " << levD(a, b) << endl;
    }
  }
  string s;
  cin >> s;
  int d;
  cin >> d;
  cout << solve(s, d) << endl;
  return 0;
}