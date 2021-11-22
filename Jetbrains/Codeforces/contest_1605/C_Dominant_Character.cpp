#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int solve(string s)
{
  int n = s.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] == s[i + 1] && s[i] == 'a')
    {
      return 2;
    }
  }
  for (int i = 0; i < n - 2; i++)
  {
    if (s[i] == s[i + 2] && s[i] == 'a')
    {
      return 3;
    }
  }
  for (int i = 0; i < n - 3; i++)
  {
    if (s[i] == s[i + 3] && s[i] == 'a')
    {
      if((s[i + 1] == 'b' && s[i + 2] == 'c') ||
        (s[i + 1] == 'c' && s[i + 2] == 'b')
      )
      return 4;
    }
  }
  for (int i = 0; i < n - 6; i++)
  {
    if (s[i] == s[i + 3] && s[i + 3] == s[i + 6] && s[i] == 'a')
    {
      if((s[i + 1] == 'b' && s[i + 4] == 'c') ||
        (s[i + 1] == 'c' && s[i + 4] == 'b')
      )
      return 7;
    }
  }
  return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
      int n;
      cin >> n;
      string s;
      cin >> s;
      cout << solve(s) << "\n";
    }
    return 0;
}