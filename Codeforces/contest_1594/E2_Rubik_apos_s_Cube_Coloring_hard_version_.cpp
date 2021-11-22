
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
ll modPow(ll base, ll pow, ll mod)
{
  if (pow == 0)
  {
    return 1;
  }
  else
  {
    ll half = modPow(base, pow / 2, mod) % mod;
    ll whole = (half * half) % mod;
    if (pow % 2 == 1)
    {
      whole = (whole * base) % mod;
    }
    return whole;
  }
}
const ll MOD = 1'000'000'007;

vi waysEasy(65);
ll getWays(ll k, ll n, vector<pii> &c)
{
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  unordered_map<ll, vi> dp;
  dp[1] = vi(3, waysEasy[k - 1]);
  for (pii coloring : c)
  {
    ll loc = coloring.first;
    ll color = coloring.second;
    while (loc != 0)
    {
      int depth = log2(loc) + 1;
      vi ways = {0, 0, 0};
      if(k == depth) {
        ways[color] = 1;
      } else {
        vi ways_right = vi(3, waysEasy[k - depth - 1]);
        vi ways_left = vi(3, waysEasy[k - depth - 1]);
        if (dp.count(loc * 2))
        {
          ways_left = dp[loc * 2];
        }
        if (dp.count(loc * 2 + 1))
        {
          ways_right = dp[loc * 2 + 1];
        }
        ll tWL = 0;
        ll tWR = 0;
        for(int i = 0; i < 3; i++) {
            tWL += ways_left[i];
            tWR +=  ways_right[i];
        }
        if(loc == coloring.first){
          ways[color] = ((tWR - ways_right[color]) * (tWL - ways_left[color])) % MOD;
        } else {
          for (int i = 0; i < 3; i++)
          {
            ways[i] = ((tWR - ways_right[i]) * (tWL - ways_left[i])) % MOD;
          }
        }
      }
      dp[loc] = ways;
      loc /= 2;
    }
  }
  return (dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll k;
  cin >> k;
  ll n;
  cin >> n;
  vector<pii> c(n);
  waysEasy[0] = 1;
  for(int i = 1; i < waysEasy.size(); i++) {
     waysEasy[i] = (waysEasy[i - 1] * waysEasy[i - 1]) % MOD;
     waysEasy[i] = (waysEasy[i] * 4) % MOD;
  }
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> c[i].first >> s;
    if (s == "orange" || s == "red")
    {
      c[i].second = 0;
    }
    else if (s == "yellow" || s == "white")
    {
      c[i].second = 1;
    }
    else
    {
      assert(s == "green" || s == "blue");
      c[i].second = 2;
    }
  }
  ll base = modPow(2, (1LL << k) - 1 - n, MOD);
  ll ways = getWays(k, n, c);
  cout << (base * ways) % MOD << endl;
  return 0;
}