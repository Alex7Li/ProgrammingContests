# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1'000'000'007;

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

ll lcmf(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        ll n;
        cin >> n;
        ll lcm = 1;
        ll count = n;
        for (int i = 1; i <= n && lcm <= n; ++i) {
            lcm = lcmf(i, lcm);
            count = (count + n / lcm) % MOD;
        }
        cout << count << "\n";
    }
    return 0;
}