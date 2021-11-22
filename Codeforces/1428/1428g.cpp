# include <bits/stdc++.h>
// https://codeforces.com/contest/1428/problem/E
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

ll score(ll x, vector<ll> &f) {
    ll score = 0;
    int tenPow = 1;
    for (int pow = 0; pow < 6; pow++, tenPow *= 10) {
        int rem = (x / tenPow) % 10;
        if (rem % 3 == 0) {
            score += (rem / 3) * f[pow];
        }
    }
    return score;
}

// Compactify count identical objects with a given weight and value.
// Return a list of objects (value, weight)
void compactify(ll weight, ll value, ll count, vector<pll> &objList) {
    for (int i = 1; i < count; i *= 2) {
        objList.push_back(pll(value * i, weight * i));
        count -= i;
    }
    objList.push_back(pll(value * count, weight * count));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, q, n;
    vector<ll> f(6);
    cin >> k >> f[0] >> f[1] >> f[2] >> f[3] >> f[4] >> f[5] >> q >> n;
    vector<ll> dp(n + 1, -(1LL << 62));
    dp[0] = 0;
    vector<pll> objects;
    int tenPow = 1;
    for (int pow = 0; pow < 6; pow++, tenPow *= 10) {
        compactify(3 * tenPow, f[pow], 3 * (k - 1), objects);
    }
    for (pll p: objects) {
        for (int i = n; i >= p.second; i--) {
            dp[i] = max(dp[i], dp[i - p.second] + p.first);
        }
    }
    ll best = 0;
    for (int i = 0; i <= n; i += 3) {
        best = max(best, score(n - i, f) + dp[i]);
    }
    cout << best << endl;
    return 0;
}
