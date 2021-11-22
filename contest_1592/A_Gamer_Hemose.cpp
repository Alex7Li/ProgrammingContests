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
    int n, H;
    cin >> n >> H;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int ans = 0;
    if (n == 1)
    {
      ans = (H + a[0] - 1) / a[0];
    }
    else
    {
      sort(a.begin(), a.end());
      reverse(a.begin(), a.end());
      int T = H / (a[0] + a[1]);
      H -= T * (a[0] + a[1]);
      int cost = 2 * T;
      if (H > 0)
      {
        H -= a[0];
        cost++;
      }
      if (H > 0)
      {
        H -= a[1];
        cost++;
      }
      ans = cost;
    }
    cout << ans << "\n";
  }
  return 0;
}