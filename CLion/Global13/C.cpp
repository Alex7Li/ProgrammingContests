# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll solve(vector<ll> &a, int n) {
    vector<ll> jumps(n, 0);
    ll count = 0;
    for (int i = 0; i < n; i++) {
        count += max(0LL, a[i] - 1 - jumps[i]);
        jumps[i] = max(a[i] - 1, jumps[i]);
        for (int j = 2; i + j < min(n + 0LL, i + a[i] + 1LL); j++) {
            jumps[i + j]++;
        }
        // more jumps than the number
        if (i + 1 < n) {
            jumps[i + 1] += max(0LL, jumps[i] - (a[i] - 1LL));
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<ll> a(n, 0);
        rep(i, 0, n) {
            cin >> a[i];
        }
        cout << solve(a, n) << "\n";
    }
    return 0;
}