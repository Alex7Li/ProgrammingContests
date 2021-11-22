# include <bits/stdc++.h>
typedef long long ll;
// Count ways to make change for N cents.
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> coins = {1, 5, 10, 25};
    // ways[i][j] = ways to make j cents using only the first i coin types.
    vector<vector<ll>> ways = vector<vector<ll>>(coins.size() + 1, vector<ll>(N + 1, 0));
    // There is 1 way to make 0 cents.
    ways[0][0] = 1;

    for (int i = 1; i <= coins.size(); i++) {
        vector<ll> partialSum(N + 1);
        for (int j = 0; j <= N; j++) {
            partialSum[j] = ways[i - 1][j];
            if (j >= coins[i - 1]) {
                partialSum[j] += partialSum[j - coins[i - 1]];
            }
            ways[i][j] += partialSum[j];
        }
    }
    cout << ways[coins.size()][N] << "\n";
    return 0;
}
