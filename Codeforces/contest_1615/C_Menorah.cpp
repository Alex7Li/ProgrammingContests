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
    string a, b;
    cin >> a >> b;
    int lita = 0;
    int litb = 0;
    int d = 0;
    int d2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1') {
        lita++;
      }
      if (b[i] == '1') {
        litb++;
      }
      if (a[i] != b[i]) {
        d++;
      } else {
        d2++;
      }
    }
    int cnt = -1;
    if (lita == litb) {
      cnt = d;
      if (lita == (n - litb + 1)) {
        cnt = min(cnt, d2);
      }
    } else if (lita == (n - litb + 1)) {
      cnt = d2;
    }
    printf("%d\n", cnt);
  }
  return 0;
}