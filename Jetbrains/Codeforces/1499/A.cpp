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
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        bool pos = true;
        if (k1 + k2 < w * 2) {
            pos = false;
        }
        if (2*n - k1 - k2 < b * 2) {
            pos = false;
        }
        cout << (pos ? "YES" : "NO") << "\n";
    }

    return 0;
}