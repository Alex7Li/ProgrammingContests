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
        for (size_t i = 0; i < n; i++)
        {
          cin >> a[i];
        }
        vi b(n);
        for (size_t i = 0; i < n; i++)
        {
          cin >> b[i];
        }
        bool ok = true;
        for (size_t i = 0; i < n; i++) {
          if(b[i] < a[i]){
            ok = false;
          }else if(b[i] - b[(i + 1) % n] >= 2) {
            if(a[i] != b[i]){
              ok = false;
            }
          }
        }
        cout << (ok ? "YES": "NO") << "\n";
    }
    return 0;
}