#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
      int n;
      cin >> n;
      vi a(n);
      rep(i, 0, n) {
        cin >> a[i];
      }
      int cur = 1;
      int M = -1;
      if(a[0] == 0) {
        cur = 0;
        M = 1;
      }
      rep(i, 0, n) {
        if(cur != a[i]) {
          if(M != -1 || cur < a[i] || (a[i] >= cur / 2)){
            M = -1;
            break;
          } else {
            M = cur - a[i];
          }
        }
        if (M != -1) {
          cur = cur % M;
        }
        cur = cur * 2;
        if (M != -1) {
          cur = cur % M;
        }
      }
      cout << M << "\n";
    }
    return 0;
}