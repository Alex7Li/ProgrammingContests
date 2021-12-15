#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll solve(vi a, int k, bool use_end) {
  ll cost = 0;
  if (use_end && a.size() > 0)
  {
    int its = min(k, (int)a.size());
    cost += a[a.size() - 1];
    for(int i = 0; i < its ; i++) {
      a.pop_back();
    }
  }
  while(a.size() > 0) {
    int its = min(k, (int)a.size());
    cost += a[a.size() - 1] * 2;
    for(int i = 0; i < its ; i++) {
      a.pop_back();
    }
  }
  return cost;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
      int n, k;
      cin >> n >> k;
      vi x(n);
      for (int i = 0; i < n; i++)
      {
        cin >> x[i];
      }
      sort(x.begin(), x.end());
      vi neg;
      vi pos;
      for(int i = 0; i < n; i++) {
          if(x[i] < 0){
            neg.push_back(-x[i]);
          } else{
            pos.push_back(x[i]);
          }
      }
      sort(neg.begin(), neg.end());
      cout << min(
        solve(neg, k, 0) + solve(pos, k, 1),
        solve(neg, k, 1) + solve(pos, k, 0)) << "\n";
    }
    return 0;
}
