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
    ll x1 ,x2;
    int p1, p2;
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
      cin >> x1 >> p1 >> x2 >> p2;
      if(abs(p1 - p2) >= 7){
        if(p1 > p2){
          cout << ">";
        } else {
          cout << "<";
        }
      } else {
        for(int i = 0; i < p1 - p2; i++){
          x1 *= 10;
        }
        for(int i = 0; i < p2 - p1; i++){
          x2 *= 10;
        }
        if(x1 > x2){
          cout << ">";
        } else if(x1 < x2) {
          cout << "<";
        } else {
          cout << "=";
        }
      }
      cout << "\n";
    }
    return 0;
}  