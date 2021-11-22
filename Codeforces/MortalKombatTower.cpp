# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1418/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    rep(tt, 0, t) {
        int n;
        cin >> n;
        vi a(n + 10, 0);
        rep(i, 0, n) {
            cin >> a[i];
        }
        vi dp(n + 10, n+10);
        dp[0] = 0;
        rep(i, 0, n) {
            dp[i + 4] = min(dp[i + 4], dp[i] + a[i] + a[i + 1]);
            dp[i + 3] = min(dp[i + 3], dp[i] + a[i]);
            dp[i + 2] = min(dp[i + 2], dp[i] + a[i]);
        }
        int best = min(dp[max(n - 1, 0)] + a[n - 1], dp[n]);
        cout << best << "\n";
    }
    return 0;
}