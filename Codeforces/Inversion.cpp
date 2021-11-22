# include <bits/stdc++.h>
//http://codeforces.com/gym/101964/attachments/download/7814/seerc-2018.pdf
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> inversions(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        inversions[--v][--u] = 1;
        inversions[u][v] = 1;
    }
    vector<int> perm(n + 1);
    for (int i = 0; i < n; i++) {
        int count = i;
        for (int j = 0; j < i; j++) {
            count -= inversions[i][j];
        }
        for (int j = i + 1; j < n; j++) {
            count += inversions[i][j];
        }
        perm[count] = i;
    }
    perm[n] = n + 1;
    vector<ll> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        ll maxV = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (perm[i] > perm[j] && perm[j] > maxV) {
                maxV = perm[j];
                dp[i] += dp[j];
            }
        }
        if (dp[i] == 0) {
            dp[i]++;
        }
    }
    cout << dp[n] << endl;
    return 0;
}