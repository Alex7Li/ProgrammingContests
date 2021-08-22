# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 998'244'353;

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

ll binom(int n, int k) {
    ll prod = 1;
    for (int i = k + 1; i <= n; ++i) {
        prod = (prod * i) % MOD;
    }
    for (int i = 1; i <= n - k; ++i) {
        prod = (inv_mod(i, MOD) * prod) % MOD;
    }
    return prod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int zC = 0;
        int eC = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zC++;
            } else if (i + 1 < n && s[i + 1] == '1') {
                eC++;
                i++;
            }
        }
        cout << binom(zC + eC, zC) << "\n";
    }
    return 0;
}