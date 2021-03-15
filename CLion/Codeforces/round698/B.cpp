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
        int q, d;
        cin >> q >> d;
        rep(i, 0, q) {
            int x;
            cin >> x;
            bool ok = false;
            for (int i = 1; i <= 10; i++) {
                if (x % 10 == i * d % 10 && x >= i * d) {
                    ok = true;
                }
            }
            if (x >= d * 10) {
                ok = true;
            }
            cout << (ok ? "YeS" : "nO") << "\n";
        }
    }
    return 0;
}