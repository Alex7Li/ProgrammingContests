#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int x, y;
    cin >> x >> y;
    if (y < x) {
      cout << (y + x) << "\n";
    } else if (y == x) {
      cout << y << "\n";
    } else {
      int n = y / x;
      cout << (y + n * x) / 2 << "\n";
    }
  }
  return 0;
}