#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int n;
  cin >> n;
  vector<pii> d(n);
  for (int i = 0; i < n; i++) {
    ll x3, y3;
    cin >> x3 >> y3;
    d[i].first = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    d[i].second = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
  }
  sort(d.begin(), d.end());
  ll ans = d[n-1].first;
  ll maxR = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans = min(ans, maxR + d[i].first);
    maxR = max(maxR, d[i].second);
  }
  ans = min(ans, maxR);
  cout << ans << '\n';
  return 0;
}