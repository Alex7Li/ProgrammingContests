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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vi> dp(n + 1, vi(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (a[i] - i + j == 1));
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            }
        }
        int ans = -1;
        for (int i = 0; i <= n; ++i) {
            if(dp[n][i] >= k) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}