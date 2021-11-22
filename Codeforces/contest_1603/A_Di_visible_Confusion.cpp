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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = a.size() - 1; i >= 0; i--) {
      if (a[i] % (i + 2) != 0) { // delete it
        for (int j = i; i < a.size() - 1; i++) {
          a[i] = a[i + 1];
        }
        a.pop_back();
        i = a.size();
      }
    }
    if (a.size() != 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
