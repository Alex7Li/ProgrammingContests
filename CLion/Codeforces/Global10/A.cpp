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
    rep(tt, 0, t) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        bool possible = true;
        rep(i, 0, n - 1) {
            int y;
            cin >> y;
            if (y != x) {
                possible = false;
            }
        }
        if (possible) {
            cout << n;
        } else {
            cout << 1;
        }
        cout << "\n";
    }

    return 0;
}