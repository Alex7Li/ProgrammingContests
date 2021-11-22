#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int query(int position, bool low, int n)
{
  vi a;
  if (low)
  {
    a = vi(n, 1);
    a[position] = 2;
  }
  else
  {
    a = vi(n, 2);
    a[position] = 1;
  }
  cout << "?";
  for (int i = 0; i < a.size(); i++)
  {
    cout << " " << a[i];
  }
  cout << endl;
  cout.flush();
  int nextPos;
  cin >> nextPos;
  return (nextPos - 1);
}

void answer(vi &a)
{
  cout << "!";
  for (int i = 0; i < a.size(); i++)
  {
    cout << " " << (a[i] + 1);
  }
  cout << endl;
}
vi topoSort(const vector<vi> &gr)
{
  vi indeg(gr.size()), ret;
  for (auto &li : gr)
    for (int x : li)
      indeg[x]++;
  queue<int> q; // use priority_queue for lexic. largest ans.
  rep(i, 0, gr.size()) if (indeg[i] == 0) q.push(i);
  while (!q.empty())
  {
    int i = q.front(); // top() for priority queue
    ret.push_back(i);
    q.pop();
    for (int x : gr[i])
      if (--indeg[x] == 0)
        q.push(x);
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vi> g(n);
  for (int i = 0; i < n; i++)
  {
    int x = query(i, false, n);
    if (x < i && x != -1)
    {
      g[x].push_back(i);
    }
    x = query(i, true, n);
    if (x < i && x != -1)
    {
      g[i].push_back(x);
    }
  }
  vi order = topoSort(g);
  vi ans(g.size());
  for(int i = 0; i < order.size(); i++){
    ans[order[i]] = i;
  }
  answer(ans);
  cout.flush();
  return 0;
}
