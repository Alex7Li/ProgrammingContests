# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


ll modpow(ll base, int power, ll mod) {
    if (power == 0) {
        return 1;
    } else {
        ll half = modpow(base, power / 2, mod);
        ll full = (half * half) % mod;
        if (power % 2 == 1) {
            full = (full * base) % mod;
        }
        return full;
    }
}

/*
 ll mobius(int n) {
    ll ans = 1;
    int p = 2;
    while (p * p <= n) {
        if (n % (p * p) == 0) {
            return 0;
        } else if (n % p == 0) {
            ans *= -1;
            n /= p;
        }
        p += 1;
    }
    if (n > 1) {
        ans *= -1;
    }
    return ans;
}*/

vector<ll> sieve(int n) {
    n += 5;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    vector<ll> mobius(n, 1);
    for (int i = 2; i * i < n; i++) {
        for (int j = i * i; j < n; j += i * i) {
            mobius[j] = 0;
        }
    }
    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = i; j < n; j += i) {
                mobius[j] *= -1;
            }
        }
    }
    return mobius;
}

// ankan
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;
    ll ans;
    cin >> m >> k;
    const ll p = 998244353;

    ans = 0;
    vector<ll> mobius = sieve(k);
    for (int i = 1; i <= k; ++i) {
        ans += mobius[i] * (modpow(2 * (k / i) + 1, m, p) - 1);
        ans += 10 * p;
        ans %= p;
    }
    ans += 1;
    ans %= p;
    cout << ans << endl;
    return 0;
}
