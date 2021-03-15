# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define N_WORKERS 5

int hash_state(vi &s) {
    int pow = 1;
    int hash = 0;
    rep(i, 0, s.size()) {
        hash += pow * s[i];
        pow *= 5;
    }
    return hash;
}

vi get_state(int hash) {
    vi s(N_WORKERS);
    rep(i, 0, s.size()) {
        s[i] = hash % 5;
        hash /= 5;
    }
    return s;
}

int solve(int n, int m, vector<pii> &v) {
    // dp[i][j] is the time it takes to get to
    // state j in the ith minute
    vector<vi> dp(2, vi((int) (pow(5, N_WORKERS)), -1));
    dp[0][0] = 0;
    for (int i = 0;; i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (dp[i % 2][j] != -1) {
                vi old = get_state(j);
                for (int k = 0; k < old.size(); k++) {
                    if (old[k] == 0) {
                        vi newV = old;
                        for (int l = 0; l < old.size(); l++) {
                            newV[l] = max(old[l] - 1, 0);
                        }
                        newV[k] = v[k].second;
                        int count = dp[i % 2][j] + v[k].first;
                        int nh = hash_state(newV);
                        dp[(i + 1) % 2][nh] = max(count, dp[(i + 1) % 2][nh]);
                        if (count >= m) {
                            return i + 1;
                        }
                    }
                }

                // or do nothing
                for (int l = 0; l < old.size(); l++) {
                    old[l] = max(old[l] - 1, 0);
                }
                int ho = hash_state(old);
                dp[(i + 1) % 2][ho] = max(dp[i % 2][j], dp[(i + 1) % 2][ho]);
            }
        }
        rep(j, 0, dp[0].size()) {
            dp[i % 2][j] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<pii> v(n);
    rep(i, 0, n) {
        cin >> v[i].first >> v[i].second;
        v[i].first *= -1;
    }
    sort(v.begin(), v.end());
    rep(i, 0, n) {
        v[i].first *= -1;
    }
    while (v.size() > N_WORKERS) {
        v.pop_back();
    }
    while (v.size() < N_WORKERS) {
        v.push_back(pii(0, 4));
    }
    cout << solve(n, m, v) << "\n";
    return 0;
}