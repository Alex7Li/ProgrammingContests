# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    // The best score you can get from the interval [st, end)
    vector<vi> dp(n, vi(n + 1, 0));
    for (int l = 3; l <= n; l++) {
        for (int st = 0; st + l <= n; st++) {
            int end = st + l;
            for (int mid = st + 1; mid < end; mid++) {
                dp[st][end] = max(dp[st][end], dp[st][mid] + dp[mid][end]);
            }
            if(l % 3 == 0) {
                for (int mid = st + 1; mid < end - 1; mid += 3) {
                    dp[st][end] = max(dp[st][end], dp[st + 1][mid] + dp[mid + 1][end - 1] +
                                                   a[st] + a[mid] + a[end - 1]);
                }
            }
        }
    }
    cout << dp[0][n];
    return 0;
}