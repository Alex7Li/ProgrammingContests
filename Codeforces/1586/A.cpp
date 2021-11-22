#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool isPrime(int a)
{
  if (a == 1)
  {
    return false;
  }
  for (int i = 2; i * i <= a; i++)
  {
    if (a % i == 0)
    {
      return false;
    }
  }
  return true;
}
void printAllBut(vector<int> &a, int x)
{
  if (x == -1)
  {
    cout << a.size() << "\n";
  }
  else
  {
    cout << (a.size() - 1) << "\n";
  }
  for (int i = 0; i < a.size(); i++)
  {
    if (i != x)
    {
      cout << (i + 1) << " ";
    }
  }
  cout << "\n";
}
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
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      sum += a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [a](int x, int y)
         { return a[x] < a[y]; });
    if (!isPrime(sum))
    {
      printAllBut(a, -1);
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        if (!isPrime(sum - a[order[i]]))
        {
          printAllBut(a, order[i]);
          break;
        }
      }
    }
  }
  return 0;
}