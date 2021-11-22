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
        int n, k;
        cin >> n >> k;
        k--;
        vi h(n);
        rep(i, 0, n) {
            cin >> h[i];
        }
        int maxH = h[0];
        int minH = h[0];
        bool possible = true;
        rep(i, 1, n) {
            maxH = min(h[i] + k, maxH + k);
            minH = max(h[i], minH - k);
            if (minH > maxH) {
                possible = false;
            }
        }
        if (maxH < h[n - 1] || minH > h[n - 1]) {
            possible = false;
        }
        cout << (possible ? "YES" : "NO") << '\n';

    }
    return 0;
}