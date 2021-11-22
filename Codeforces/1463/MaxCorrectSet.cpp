# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    vector<vi> dp(2, vi(1 << y, 0));
    int r = n % (x + y);
    int q = n / (x + y);
    dp[0][1] = 0 < r ? q + 1 : q;
    rep(i, 1, x + y) {
        rep(j, 0, 1 << min(y, i)) {
            int next_mask = ((1 << y) - 1) & (j << 1);
            if ((j & (1 << (x-1))) == 0 && (j & (1 << (y-1))) == 0) {
                int scoreGain = i < r ? q + 1 : q;
                dp[i % 2][next_mask + 1] = max(dp[i % 2][next_mask + 1], dp[(i - 1) % 2][j] + scoreGain);
            }
            dp[i % 2][next_mask] = max(dp[i % 2][next_mask], dp[(i - 1) % 2][j]);
        }
    }
    int maxV = 0;
    rep(i, 0, 1 << y) {
        maxV = max(dp[(x + y - 1) % 2][i], maxV);
    }
    cout << maxV;
    return 0;
}
