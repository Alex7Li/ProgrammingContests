# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        ll n, k;
        cin >> n >> k;
        // n ^ k
        ll ans = 1;
        for (int i = 0; i < k; ++i) {
            ans = (ans * n) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}