# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define INF 100'000'000
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int maxV(vi a) {
    int maxVal = 0;
    rep(i, 0, a.size()) {
        maxVal = max(maxVal, a[i]);
    }
    return maxVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vi r(n);
        vi rSum(n + 1, 0);
        rep(i, 0, n) {
            cin >> r[i];
            rSum[i + 1] = rSum[i] + r[i];
        }
        int m;
        cin >> m;
        vi b(m);
        vi bSum(m + 1, 0);
        rep(i, 0, m) {
            cin >> b[i];
            bSum[i + 1] = bSum[i] + b[i];
        }
        cout << maxV(rSum) + maxV(bSum) << "\n";

    }
    return 0;
}