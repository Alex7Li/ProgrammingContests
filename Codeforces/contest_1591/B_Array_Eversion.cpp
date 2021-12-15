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
      int MAX = 0;
      for(int i = 0; i < n; i++) {
        cin >> a[i];
        MAX = max(a[i], MAX);
      }
      int MIN = 0;
      int ev = 0;
      for (int i = n - 1; i >= 0; i--)
      {
        if(a[i] == MAX){
          break;
        }
        if (a[i] > MIN){
          ev++;
          MIN = a[i];
        } else {
          continue;
        }
      }
      cout << ev << "\n";
    }
    return 0;
}