# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll MOD = 1'000'000'007;

ll solve(vector<ll> b, int n) {
    ll count = 1;
    bool overflowed = false;
    for (int i = 0; i < n; ++i) {
        count *= 2;
        count -= b[i];
        if (count < 0) {
            if (!overflowed) {
                return -1;
            } else {
                count = ((count % MOD) + MOD) % MOD;
            }
        }
        if (count > (1LL << 61)) {
            overflowed = true;
            count = count % MOD;
        }
    }
    return ((count % MOD) + MOD) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int ans = solve(b, n);
    if (ans == -1) {
        cout << "error" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}