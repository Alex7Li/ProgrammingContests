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
    int m = 200005;
    vector<vector<ll>> dp(m+1, vector<ll>(10));
    for (int i = 0; i < 10; ++i) {
        dp[m][i] = 1;
    }
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < 9; ++j) {
            dp[i][j] = dp[i + 1][j + 1];
        }
        dp[i][9] = (dp[i + 1][0] + dp[i + 1][1]) % MOD;
    }
    for (int tt = 0; tt < t; tt++) {
        string n;
        int M;
        cin >> n >> M;
        ll total = 0;
        for (int i = 0; i < n.size(); ++i) {
            total = (total + dp[m-M][n[i]-'0']) % MOD;
        }
        cout << total << "\n";
    }
    return 0;
}