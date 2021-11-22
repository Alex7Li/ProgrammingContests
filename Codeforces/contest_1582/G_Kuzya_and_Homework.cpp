#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int gcd(int a, int b) { return (a == 0 ? b : gcd(b % a, a)); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<char> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (a[i] == 1) {
      b[i] = '*';
    }
  }
  stack<int> V;
  ll ans = 0LL;
  for (int i = 0; i < n; i++) {
    if (b[i] == '*') {
      V.push(a[i]);
    } else {
      int val = a[i];
      while (val != 1 && !V.empty()) {
        int x = V.top();
        V.pop();
        int g = gcd(x, val);
        x /= g;
        val /= g;
        if (val == 1) {
          V.push(x);
        }
      }
    }
    ans += V.size();
  }
  std::cout << ans << '\n';
  return 0;
}
