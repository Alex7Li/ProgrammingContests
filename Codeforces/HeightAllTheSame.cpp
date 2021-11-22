# include <bits/stdc++.h>
//http://codeforces.com/contest/1332/problem/E
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define MOD 998244353LL
# define HALF 499122177LL
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll modPow(ll base, ll pow) {
    if (pow == 0) {
        return 1;
    } else {
        ll ans = 1;
        if (pow % 2 == 1) {
            ans = base % MOD;
        }
        ll p = modPow(base, pow / 2);
        p = (p * p) % MOD;
        return (p * ans) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    ll ans = modPow(R - L + 1, n * m);
    if (n % 2 == 0 || m % 2 == 0) {
        if ((R - L) % 2 == 0) {
            ans++;
        }
        ans = (ans + MOD) * HALF;
    }
    cout << ans % MOD << endl;
    return 0;
}