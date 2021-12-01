#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool canKill(ll h, ll k, vi& d) {
  for (int i = 0; i < d.size(); i++) {
    h -= min(ll(d[i]), k);
  }
  h -= k;
  return h <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int n;
        cin >> n;
        ll h;
        cin >> h;
        vi a(n);
        for(int i = 0; i < n; i++) {
          cin >> a[i];
        }
        vi d(n - 1);
        for(int i = 0; i < n - 1; i++) {
          d[i] = a[i + 1] - a[i];
        }
        ll kMAX = 1LL << 62;
        for (ll i = (1LL << 61); i > 0; i/=2){
          if(canKill(h, kMAX - i, d)) {
            kMAX -= i;
          }
        }
        cout << kMAX << "\n";
    }
    return 0;
}