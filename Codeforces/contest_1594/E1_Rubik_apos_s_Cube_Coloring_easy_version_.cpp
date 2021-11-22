# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k;
    cin >> k;
    cout << (6 * modPow(4, (1LL << k) - 2, MOD)) % MOD << endl;
    return 0;
}