# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
          int n, m;
          cin >> n >> m;
          set<int> ok;
          for(int i = 1; i <= n; i++){
            ok.insert(i);
          }
          for(int x = 0; x < m; x++){
            int a, b, c;
            cin >> a >> b >> c;
            ok.erase(b);
          }
          int center = *ok.lower_bound(0);
          for(int i = 1; i <= n; i++){
            if( i != center) {
              cout << i << " " << center << "\n";
            }
          }
    }
    return 0;
}