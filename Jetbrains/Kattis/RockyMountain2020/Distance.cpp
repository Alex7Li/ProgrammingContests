# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll solve(vi &a) {
    sort(a.begin(), a.end());
    ll c = 0;
    ll last = 0;
    ll ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans += (a[i] - last) * c * (a.size() - c);
        last = a[i];
        c++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi s(n);
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> a[i];
    }
    ll ans = solve(s) + solve(a);
    cout << ans << '\n';
    return 0;
}