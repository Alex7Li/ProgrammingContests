# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        ll gc = 0;
        rep(i, 0, n) {
            cin >> a[i];
            gc = gcd(a[i] - a[0], gc);
        }
        if ((k - a[0]) % gc == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}