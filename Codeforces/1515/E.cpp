# include <bits/stdc++.h>
// WA, wrong method completely
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

ll binom(ll n, ll k, ll m) {
    if (k == 0) {
        return max(1LL, n);// not really binom ok
    }
    ll ans = 1;
    for (ll i = n - k + 1; i <= n; ++i) {
        ans = (ans * i) % m;
    }
    for (int i = 1; i <= k; ++i) {
        ans = (ans * mod_inverse(i, m)) % m;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    ll M;
    cin >> n >> M;
    vector<ll> fact(1000000001);
    accumulate(fact.begin(), fact.end(), 0LL, [M](ll a, ll b) {
        return (a * b) % M;
    });
    vector<ll> rl(404, 0);
    // make rl
    for (int i = 2; i < 402; ++i) {
        for (int j = 0; j < i; ++j) { // take jth position
            ll ri = j;
            ll le = i - j - 1;
            rl[i] = (rl[i] + binom(rl[ri] + rl[le], rl[ri], M)) % M;
        }
        cout << i << " " << rl[i] << endl;
    }

    vector<ll> r(404, 0);
    for (int i = 2; i < 404; ++i) {
        for (int j = 0; j < i; ++j) {
            ll ri = j;
            ll le = i - j - 1;
            r[i] = (r[i] + binom(rl[ri] + r[le], r[le], M)) % M;
        }
        cout << i << " " << r[i] << endl;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll ri = i;
        ll le = n - i - 1;
        ans = (ans + binom(r[ri] + r[le], r[le], M)) % M;
    }
    cout << ans << endl;
    return 0;
}