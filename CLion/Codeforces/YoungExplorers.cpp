# include <bits/stdc++.h>
//http://codeforces.com/problemset/problem/1355/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t) {
        int n;
        cin >> n;
        vector<int> e(n);
        rep(i, 0, n) {
            cin >> e[i];
        }
        sort(e.begin(), e.end());
        int topInd = n - 1;
        int groups = 0;
        while (topInd >= 0) {
            int first = topInd - e[topInd];
            while (topInd >= 0 && first < topInd) {
                first = max(first, topInd - e[topInd]);
                topInd--;
            }
            if (first >= -1) {
                groups++;
            }
        }
        cout << groups << "\n";
        cerr << endl;
    }
    return 0;
}