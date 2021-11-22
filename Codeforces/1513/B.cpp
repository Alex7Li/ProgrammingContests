# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll common = (1L << 31) - 1LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            common &= a[i];
        }
        ll zeros = 0;
        for (int i = 0; i < n; i++) {
            a[i] ^= common;
            if (a[i] == 0) {
                zeros++;
            }
        }
        //number of zeros choose 2 times (n-2)!
        ll ans = (zeros * (zeros - 1));
        ans %= MOD;
        for (int i = 2; i <= n - 2; ++i) {
            ans = (ans * i) % MOD;
        }
        cout << ans << "\n";
    }
    cout << endl;
    return 0;
}