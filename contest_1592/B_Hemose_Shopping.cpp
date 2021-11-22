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
        int n, x;
        cin >> n >> x;
        int r = x;
        int l = n - x;
        // [r, l) must be sorted.
        vi a(n);
        vi b(n);
        for(int i = 0; i < n; i++){
          cin >> a[i];
          b[i] = a[i];
        }
        sort(b.begin(), b.end());
        bool possible = true;
        for(int i = l; i< r; i++){
          if(a[i] != b[i]){
            possible = false;
          }
        }
        cout << (possible?"YES":"NO") << "\n";
    }
    return 0;
}