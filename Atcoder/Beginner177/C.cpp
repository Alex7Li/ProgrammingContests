# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define MOD 1'000'000'007
# define HALF 500'000'004
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = (ans + a[i]) % MOD;
    }
    ans = (ans * ans) % MOD;
    for (int i = 0; i < n; i++) {
        ans -= (a[i] * a[i]);
        ans = ans % MOD;
    }
    ans = (ans * HALF) % MOD;
    cout << (ans + MOD) % MOD;
    return 0;
}
