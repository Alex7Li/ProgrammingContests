#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
      int n;
      cin >> n;
      vi a(n);
      for(int i = 0; i < n; i++) {
        cin >> a[i];
      }
      int h = 1;
      bool l = false;
      for (int i = 0; i < n; i++)
      {
        if(a[i]){
          h += l ? 5 : 1;
          l = true;
        } else {
          if(!l && i > 0){
            h = -1;
            break;
          }
          l = false;
        }
      }
      cout << h << "\n";
    }
    return 0;
}