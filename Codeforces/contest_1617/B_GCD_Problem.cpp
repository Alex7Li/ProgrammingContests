#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int gcd(int a, int b){
  return a == 0 ? b : gcd(b % a, a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int n;
        cin >> n;
        int a, b, c;
        if (n % 2 == 0)
        {
          a = n / 2;
          b = n/2 - 1;
          c = 1;
        } else {
          a = b = n / 2;
          int i;
          for (i = 1; i < n / 2; i++)
          {
            if (gcd(a - i, b + i) == 1)
            {
              break;
            }
          }
          a = a - i;
          b = b + i;
          c = 1;
        }
        cout << a << " " <<  b << " " << c << "\n";
    }
    return 0;
}