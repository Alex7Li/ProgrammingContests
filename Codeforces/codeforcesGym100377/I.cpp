# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] *= a;
    }
    vi l(n + 1, 0);
    vi r(n + 1, 0);
    rep(i, 0, n) {
        l[i + 1] = l[i] + x[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = r[i + 1] + x[i];
    }
    rep(i, 1, n + 1) {
        l[i] = min(l[i - 1], l[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = min(r[i + 1], r[i]);
    }
    ll ans = 0;
    rep(i, 0, n) {
        ans = min(ans, r[i + 1] + l[i]);
    }
    ll sum = 0;
    rep(i, 0, n) {
        sum += x[i];
    }
    cout << -ans + sum + b << "\n";
    return 0;
}