#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define MOD 998244353
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
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    vector<ll> w(n + 5);
    vector<ll> w2(n + 5);
    w[0] = 1;
    for (int x : a)
    {
      if (x + 2 > w.size())
      {
        continue;
      }
      if (x > 0)
      {
        w2[x - 1] = (2 * w2[x - 1] + w[x - 1]) % MOD;
      }
      w2[x + 1] = (2 * w2[x + 1]) % MOD;
      w[x + 1] = (2 * w[x + 1] + w[x]) % MOD;
    }
    ll sum = MOD - 1;
    for (int i = 0; i < w2.size(); i++)
    {
      sum = (sum + w[i] + w2[i]) % MOD;
    }
    cout << sum << "\n";
  }
  return 0;
}