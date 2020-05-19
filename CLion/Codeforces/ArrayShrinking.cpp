# include <bits/stdc++.h>
//https://codeforces.com/contest/1312/problem/D
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD (998244353LL)


ll choose(ll n, ll k, vector<ll> &modInv) {
    ll ans = 1;
    for (int i = k + 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    rep(i, 2, n - k + 1) {
        ans = (ans * modInv[i]) % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> modInv(m + 1, 0LL);
    vector<ll> factorial(m + 1, 0LL);
    factorial[0] = 1;
    for (int i = 0; i < m; i++) {
        factorial[i + 1] = (factorial[i] * (i + 1)) % MOD;
    }
    modInv[0] = modInv[1] = 1;
    for (int i = 2; i <= m; i++) {
        modInv[i] = modInv[MOD % i] * (MOD - MOD / i) % MOD;
        assert((modInv[i] * i) % MOD == 1);
    }
    ll ways = (choose(m, n - 1, modInv) * (n - 2)) % MOD;
    ll orders = 0;
    ll count = choose(n - 3, 0, modInv);//(modInv[n - i - 2] * modInv[i - 1]) % MOD;
    for (int i = 1; i < n - 1; i++) {
  //      ll count = choose(n-3, i-1, modInv)
        orders = (orders + count) % MOD;
        count = (count * modInv[i]) % MOD;
        count = (count * (n-2-i)) % MOD;
    }
    cout << ((ways * orders) % MOD);
    return 0;
}