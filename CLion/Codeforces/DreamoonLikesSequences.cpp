# include <bits/stdc++.h>
//https://codeforces.com/contest/1330/problem/D
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void impos() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(ntimes, 0, t) {
        int d, m;
        cin >> d >> m;
        vector<ll> ways(0);
        int x = 1;
        int prev = 1;
        while (x != d + 1) {
            x = min(2 * x, d + 1);
            ways.push_back(x - prev);
            prev = x;
        }
        ll ans = 0;
        for (int i = ways.size() - 1; i >= 0; i--) {
            ans = (ways[i] * (ans + 1) + ans) % m;
        }
        cout << ans << "\n";
    }

    return 0;
}