# include <bits/stdc++.h>

using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll INF = 1'000'000'000;

vector<ll> solve(vector<string> runes, vector<ll> costs, int k) {
    vector<vector<ll>> dp(k, vector<ll>(26, INF));
    for (int i = 0; i < 26; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < runes.size(); ++j) {
            string rune = runes[j];
            ll st = rune[0] - 'a';
            ll end = rune[1] - 'a';
            dp[i][end] = min(dp[i][end], dp[i - 1][st] + costs[j]);
        }
    }
    return dp[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int k;
    cin >> n >> k;
    vector<string> runes(n);
    vector<ll> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> runes[i] >> costs[i];
    }

    vector<string> runes2;
    vector<ll> costs2;
    map<int, int> ok;
    for (int i = 0; i < runes.size(); ++i) {
        // check that the inverse rune exists
        for (int j = 0; j < runes.size(); ++j) {
            if (runes[i][0] == runes[j][1] && runes[i][1] == runes[j][0]) {
                runes2.push_back(runes[i]);
                if(i == j) {
                    ok.insert({runes[i][0]-'a', costs[i]});
                }
                costs2.push_back(costs[i] + costs[j]);
                break;
            }
        }
    }
    vector<ll> cost = solve(runes2, costs2, (k + 1) / 2);
    ll best = INF;
    if (k % 2 == 1) {
        for (int i = 0; i < 26; ++i) {
            best = min(best, cost[i]);
        }
    } else {
        trav(a, ok){
            best = min(best, cost[a.first] + a.second) ;
        }
    }
    int ans = best >= INF ? -1 : best;
    cout << ans << endl;
}