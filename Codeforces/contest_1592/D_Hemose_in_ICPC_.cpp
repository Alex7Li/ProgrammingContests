#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<int> order;
vector<vi> g;
int query(int low, int high)
{
  set<int> a;
  for(int i = low; i <= high; i++){
    a.insert(order[i] + 1);
  }
  cout << "? " << a.size();
  trav(x, a){
    cout << " " << x;
  }
  cout << endl;
  int resp;
  cin >> resp;
  return resp;
}
void guess(int a, int b)
{
  cout << "! " << (a + 1) << " "  << (b + 1);
  cout << endl;
}
void make_order(int st, int prev) {
  order.push_back(st);
  for(int next: g[st]) {
    if(next != prev) {
      make_order(next, st);
      order.push_back(st);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n; // 10^3
  g = vector<vi>(n);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >>  v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  make_order(0, -1);
  int l = 0;
  int r = order.size() - 1;
  int goal = query(l, r);
  while(l + 1 != r) {
    int mid = (l + r)/ 2;
    int score = query(l, mid);
    if(score == goal){
      r = mid;
    } else {
      l = mid;
    }
  }
  guess(order[l], order[r]);
  return 0;
}
