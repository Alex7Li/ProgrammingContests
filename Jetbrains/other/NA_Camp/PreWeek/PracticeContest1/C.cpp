# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
const ll MOD = 1'000'000'009;

vector<ll> fact(5001);

ll modPow(ll base, ll pow, ll mod) {
    if (pow == 0) {
        return 1;
    } else {
        ll half = modPow(base, pow / 2, mod) % mod;
        ll whole = (half * half) % mod;
        if (pow % 2 == 1) {
            whole = (whole * base) % mod;
        }
        return whole;
    }
}

ll inv_mod(ll v, ll mod) {
    ll inv = (modPow(v, mod - 2, mod)) % mod;
    assert((inv * v) % mod == 1);
    return inv;
}

ll solve(int n, vector<ll> &a) {
    vll sortedWays(n + 1);
    vll unSortedWays(n + 1);
    unSortedWays[0] = 1;
    sortedWays[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vll counts(i, 1);
        for (int k = 1; k < i; ++k) {
            if (a[k] == a[k - 1]) {
                counts[k] = counts[k - 1] + 1;
            } else {
                counts[k] = 1;
            }
        }
        for (int k = i - 2; k >= 0; --k) {
            if (a[k] == a[k + 1]) {
                counts[k] = counts[k + 1];
            }
        }
        for (int j = 0; j < i; ++j) {
            ll tmp = (unSortedWays[j] * fact[i - j - 1]) % MOD;
            ll tmp2 =  (tmp * counts[j]) % MOD;
            sortedWays[i] = (tmp2 + sortedWays[i]) % MOD;
        }
        unSortedWays[i] = ((fact[i] - sortedWays[i]) % MOD + MOD) % MOD;
    }
    return unSortedWays[n] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i <= 5000; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = (solve(n, a) + MOD) % MOD;
    vll counts(n, 1);
    for (int k = 1; k < n; ++k) {
        if (a[k] == a[k - 1]) {
            counts[k] = counts[k - 1] + 1;
            ans = (ans * inv_mod(counts[k], MOD)) % MOD;
        } else {
            counts[k] = 1;
        }
    }
    cout << (ans + MOD) % MOD << endl;
    return 0;
}