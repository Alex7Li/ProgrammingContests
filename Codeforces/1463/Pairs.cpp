# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int n;
    rep(tt, 0, t) {
        cin >> n;
        vector<int> b(n);
        int minx = 0;
        int maxx = 2 * n;
        set<int> bVals;
        rep(x, 0, n) {
            cin >> b[x];
            bVals.insert(b[x]);
        }
        int countAboveX = n;
        int countBelowX = 0;
        int i = 1;
        rep(ind, 0, n) {
            int x = b[ind];
            for (; i <= x; i++) {
                if (bVals.find(i) == bVals.end()) {
                    countAboveX--;
                    countBelowX++;
                }
            }
            minx = max(minx, countAboveX - (n - ind - 1));
            maxx = min(maxx, countAboveX + ind);
        }
        cout << maxx - minx + 1 << "\n";
        bVals.clear();
        b.clear();
    }
    return 0;
}