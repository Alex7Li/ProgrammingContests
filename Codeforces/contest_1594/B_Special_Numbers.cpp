# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        ll n, k;
        cin >> n >> k;
        ll pow = 1;
        ll ans = 0;
        for(int i = 1; i <= k; i*=2) {
          if(i & k){
            ans = (ans + pow) % MOD;
          }
          pow = (pow * n) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}