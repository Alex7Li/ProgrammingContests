#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int INF = 1000000;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
  int nPrimes = primes.size();
  vector<int> divisor_set(59);
  for (int b = 0; b < divisor_set.size(); b++)
  {
    // Compute the set of primes that divide b
    for (int j = 0; j < nPrimes; j++)
    {
      if (b % primes[j] == 0)
      {
        // Add this prime to the mask
        divisor_set[b] |= 1 << j;
      }
    }
  }
  vector<vi> dp(n + 1, vi(1 << nPrimes, INF));
  vector<vi> predecessor(n + 1, vi(1 << nPrimes, INF));
  vector<vi> best_value(n + 1, vi(1 << nPrimes, INF));

  dp[0][0] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int b = 1; b < 59; b++)
    {
      // Iterate over all masks that don't use primes in the
      // factorization of b
      int usable_mask = ((1 << primes.size()) - 1) ^ divisor_set[b];
      // Magic trick: mask goes through all subsets of usable_mask.
      for (int mask = usable_mask;; mask = (mask - 1) & usable_mask)
      {
        int new_mask = mask | divisor_set[b];
        if (dp[i + 1][new_mask] > dp[i][mask] + abs(b - a[i]))
        {
          dp[i + 1][new_mask] = dp[i][mask] + abs(b - a[i]);
          predecessor[i + 1][new_mask] = mask;
          best_value[i + 1][new_mask] = b;
        }
        if (!mask)
        {
          break;
        }
      }
    }
  }
  // Restore the answer
  int best = INF;
  int best_ind = 0;
  for(int i = 0; i < dp[n].size(); i++){
    if(dp[n][i] < best) {
      best = dp[n][i];
      best_ind = i;
    }
  }
  vi ans(n);
  for(int i = n - 1; i >= 0; i--){
    ans[i] = best_value[i + 1][best_ind];
    best_ind = predecessor[i + 1][best_ind];
  }
  cout << ans[0];
  for(int i = 1; i < n; i++){
    cout << " " << ans[i];
  }
  cout << "\n";
  return 0;
}