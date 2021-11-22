# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;
typedef vector<int> VI;

// return a % b (positive value)
int mod(int a, int b) {
    return ((a % b) + b) % b;
}

// returns g = gcd(a, b); finds x, y such that d = ax + by
int extended_euclid(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
int mod_inverse(int a, int n) {
    int x, y;
    int g = extended_euclid(a, n, x, y);
    if (g > 1) return -1;
    return mod(x, n);
}

ll binom(ll n, ll k) {
    ll ans = 1LL;
    for (ll i = k + 1; i <= n; ++i) {
        ans = (ans * i) % MOD;
    }
    for (int i = 2; i <= n - k; ++i) {
        ans = (ans * mod_inverse(i, MOD)) % MOD;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll su = accumulate(a.begin(), a.end(), 0LL,
                       [](ll x, ll y) { return x + y; });
    if (su % n != 0) {
        cout << 0 << endl;
        exit(0);
    }
    vector<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll av = su / n;
    ll ways = 1;
    sort(a.begin(), a.end());
    for_each(a.begin(), a.end(), [&](ll &x) { x -= av; });
    ll pos = count_if(a.begin(), a.end(), [](ll x) { return x > 0; });
    ll neg = count_if(a.begin(), a.end(), [](ll x) { return x < 0; });
    ll zero = count(a.begin(), a.end(), 0);
    int same = 1;
    for (int i = 0; i < n; ++i) {
        if (i != 0 && a[i] == a[i - 1]) {
            same++;
        } else {
            same = 1;
        }
        if (a[i] != 0) {
            ll inv = mod_inverse(same, MOD);
            ways = (ways * inv) % MOD;
        }
    }
    if (neg != 0) {
        if (neg == 1 || pos == 1) {
            ways = (ways * (neg + pos)) % MOD;
        } else {
            ways = (ways * 2) % MOD;
        }
    }
    ways = (ways * binom(n, zero)) % MOD;
    ways = (ways * fact[neg]) % MOD;
    ways = (ways * fact[pos]) % MOD;
    cout << ways << endl;
    return 0;
}