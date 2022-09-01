#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
    vector<vi> grid(n + 1, vi(n + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int v = grid[i - 1][j];
        ans ^= v;
        grid[i - 1][j] ^= v;
        grid[i + 1][j] ^= v;
        grid[i][j + 1] ^= v;
        if (j > 0) {
          grid[i][j - 1] ^= v;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}