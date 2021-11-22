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
    rep(tt, 0, t) {
        ll x;
        cin >> x;
        int ans = 0;
        ll c = 1;
        for (ll h = 1; c <= x; c += (h * (h + 1)) + (h + 1) * (h + 1), h = h * 2 + 1) {
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}