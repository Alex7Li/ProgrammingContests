# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vi x(n);
        vi y(n);
        rep(i, 0, n) {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll ans = 0;
        if (n % 2 == 1) {
            ans = 1;
        } else {
            ll mid = (n - 1) / 2;
            ans = (x[mid + 1] - x[mid] + 1LL) * (y[mid + 1] - y[mid] + 1LL);
        }
        cout << ans << "\n";
    }
    return 0;
}