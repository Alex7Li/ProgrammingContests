// https://codeforces.com/gym/101557
# include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    vector<int> d(k);
    for (int i = 0; i < k; ++i) {
        cin >> d[i];
    }
    vector<vi> dp(1 << k, vi(8, 10000));
    for (int i = 0; i < 8; ++i) {
        dp[0][i] = 0;
    }
    for (int mask = 0; mask < (1 << k); ++mask) {
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                for (int x = 0; x < 7; ++x) {
                    int l = dp[mask ^ (1 << i)][x];
                    int singles_left = max(0, d[i] - x - 1);
                    dp[mask][singles_left] = min(dp[mask][singles_left],
                                                 l + x + 1);
                }
            }
        }
    }

    int best = dp[(1 << k) - 1][0];
    cout << best << endl;
    return 0;
}