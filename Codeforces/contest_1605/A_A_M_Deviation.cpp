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
      int a, b, c;
      cin >> a >> b >> c;
      int sum = a + b + c;
      if(sum % 3 == 0){
        cout << "0\n";
      } else {
        cout << "1\n";

      }
    }
    return 0;
}