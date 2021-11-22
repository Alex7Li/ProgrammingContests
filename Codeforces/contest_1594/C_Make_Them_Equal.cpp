#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++)
  {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    int badPos = -1;
    int goodPos = -1;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == c && i >= n/2)
      {
        goodPos = i;
      }
      if(s[i] != c){
        badPos = i;
      }
    }
    if(badPos == -1){
      cout << "0\n";
    } else if(goodPos == -1) {
      cout << "2\n";
      cout << (n - 1) << " "  << n <<  "\n";
    } else {
      cout << "1\n" << (goodPos + 1) << endl;
    }
  }
  return 0;
}