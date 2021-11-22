#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpp;

pii add(pii a, pii b)
{
  return {a.first + b.first, a.second + b.second};
}

int pair_max(pii a)
{
  return max(a.first, a.second);
}
bool possible = true;
pii dfs(int st, int c, vector<vpp> &G, vector<int> &color)
{
  pii ans = pii(0, 0);
  if (color[st] != -1)
  {
    if (color[st] != c)
    {
      possible = false;
    }
    return ans;
  }
  color[st] = c;
  if (c == 0)
  {
    ans.first++;
  }
  else
  {
    assert(c == 1);
    ans.second++;
  }
  for (pii p : G[st])
  {
    int next = p.first;
    int w = p.second;
    ans = add(ans, dfs(next, c ^ w, G, color));
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++)
  {
    int n, m;
    cin >> n >> m;
    vector<vpp> g(n);
    for (int i = 0; i < m; i++)
    {
      int a, b;
      string type;
      cin >> a >> b >> type;
      a--;
      b--;
      g[a].push_back(pii{b, type == "imposter"});
      g[b].push_back(pii{a, type == "imposter"});
    }
    vector<int> color(n, -1);
    ll count = 0;
    possible = true;
    for (int i = 0; i < n; i++)
    {
      if (color[i] == -1)
      {
        count += pair_max(dfs(i, 0, g, color));
      }
    }
    if (!possible)
    {
      cout << "-1\n";
    }
    else
    {
      cout << count << "\n";
    }
  }

  return 0;
}