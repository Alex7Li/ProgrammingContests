#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll INF = 1e15;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  int MAX_K = 450;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++)
  {
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<vll> dp(n, vll(MAX_K, 0));
    // sums[i]: sum of last i elements
    vll sums(MAX_K);
    int best_k = 1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < MAX_K; j++)
      {
        sums[j] += a[i];
        if (i - j >= 0)
        {
          sums[j] -= a[i - j];
        }
      }
      for (int j = 1; j < MAX_K; j++)
      {
        if (i > 0)
        {
          dp[i][j] = dp[i - 1][j];
        }
        dp[i][1] = max(dp[i][1], a[i]);
        if (i - j >= 0 && sums[j] < dp[i - j][j - 1])
        {
          dp[i][j] = max(dp[i][j], sums[j]);
          best_k = max(best_k, j);
        }
      }
    }
    cout << best_k << "\n";
  }
  return 0;
}