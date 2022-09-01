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
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    vi l(n + 1);
    vi r(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    r[n] = r[0];
    l[n] = l[0];
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += l[i] * r[i + 1] - l[i + 1] * r[i];
    }
    if (sum < 0) {
      sum *= -1;
      printf("CW %.1f\n", sum / 2);
    } else {
      printf("CCW %.1f\n", sum / 2);
    }
  }
  return 0;
}