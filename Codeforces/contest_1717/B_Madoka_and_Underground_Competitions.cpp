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
int mod(int n, int k){
  return (n % k + k) % k;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        int xloc = mod(r - c, k);
        for (size_t i = 0; i < n; i++)
        {
          for (size_t j = 0; j < n; j++)
          {
            if(mod(i - j, k) == xloc) {
              cout << 'X';
            }else{
              cout << '.';
            }
          }
          cout << "\n";
        }
    }

    return 0;
}