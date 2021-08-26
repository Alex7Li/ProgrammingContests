# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
T gcd(T a, T b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mInd = min_element(a.begin(), a.end()) - a.begin();
        vector<vi> ops;
        for (int i = mInd + 1; i < n; ++i) {
            ops.push_back({mInd, i, a[mInd], a[i - 1] + 1});
            a[i] = a[i - 1] + 1;
        }
        for (int i = mInd - 1; i >= 0; --i) {
            ops.push_back({mInd, i, a[mInd], a[i + 1] + 1});
            a[i] = a[i + 1] + 1;
        }
        cout << ops.size() << "\n";
        for (vi &op: ops) {
            cout << op[0] + 1 << " " << op[1] + 1 << " " << op[2] << " " << op[3] << "\n";
        }
    }
    return 0;
}