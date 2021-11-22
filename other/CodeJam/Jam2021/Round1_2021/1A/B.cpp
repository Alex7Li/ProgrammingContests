# include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef pair<int, ll> pii;

ll solve(vector<pii> &cards, const int i1, const int i2, const ll total_sum, const ll prod) {
    if (total_sum == prod) {
        return total_sum;
    }
    if (prod > total_sum) {
        return 0;
    }
    ll best = 0;
    if (i2 < cards[i1].second) {
        best = max(best, solve(
                cards, i1, i2 + 1, total_sum - cards[i1].first, prod * cards[i1].first));
    }
    for (int j = i1 + 1; j < cards.size(); j++) {
        best = max(best, solve(cards, j, 1, total_sum - cards[j].first, prod * cards[j].first));
    }
    return best;
}

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int M;
        cin >> M;
        vector<pii> cards(M);
        ll total_sum = 0;
        for (int i = 0; i < M; i++) {
            // prime, number of such primes
            cin >> cards[i].first >> cards[i].second;
            total_sum += cards[i].first * cards[i].second;
        }
        ll ans = solve(cards, 0, 0, total_sum, 1LL);
        cout << "Case #" << (tt + 1) << ": " << ans << endl;
    }
    return 0;
}