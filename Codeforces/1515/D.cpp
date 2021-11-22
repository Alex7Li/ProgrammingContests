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
        int n, l, r;
        cin >> n >> l >> r;
        int ans = n / 2 + abs(r - l) / 2;
        map<int, int> rc;
        map<int, int> lc;
        set<int> colors;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            colors.insert(c);
            if (i < l) {
                lc[c]++;
            } else {
                rc[c]++;
            }
        }
        if (l > r) {
            swap(lc, rc);
        }
        int match = 0;
        int swap = 0;
        for (auto c : colors) {
            int fromLeft = lc[c];
            int fromRight = rc[c];
            match += min(fromLeft, fromRight);
            swap += max((fromRight - fromLeft) / 2, 0);
        }
        swap = min(abs(r - l)/2, swap);
        cout << ans - match - swap << endl;
    }
    return 0;
}