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
        if (k <= (n - 1) / 2) {
            int ma = n;
            int mi = 1;
            for (int i = 0; i < k; i++) {
                cout << mi++ << " " << ma-- << " ";
            }
            for (int i = 2 * k; i < n; ++i) {
                cout << ma-- << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}