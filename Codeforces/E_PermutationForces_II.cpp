#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll MOD = 998244353;
int main() {
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int n, s;
        cin >> n >> s;
        s += 1;
        vector<int> a(n);
        vector<int> order(n);
        for(int i = 0; i < n; i++) {
          cin >> a[i];
          order[a[i] - 1] = i;
        }
        vector<int> b(n);
        set<int> seenb;
        for(int i = 0; i < n; i++) {
          cin >> b[i];
          seenb.insert(b[i]);
        }
        set<int> seen;
        int blank = 0;
        for(int i = 0; i < min(s,n); i++) {
          if(b[order[i]] == -1) {
            blank++;
          } else {
            seen.insert(b[order[i]]);
          }
        }
        ll ans = 1;
        for(int i = 0; i < n; i++) {
          if(seen.count(a[order[i]])) {
            // OK, forced
          } else if(seenb.count(a[order[i]])) {
            // it's here but not in a reachable place
            ans = 0;
            break;
          } else {
            // Must replace a ? with this
            ans = (ans * blank) % MOD;
            blank--;
          }
          if (i + s < n) {
            if(b[order[i + s]] == -1){
              blank++;
            } else {
              seen.insert(b[order[i + s]]);
            }
          }
        }
        cout << (ans)%MOD << "\n";
    }
    return 0;
}
