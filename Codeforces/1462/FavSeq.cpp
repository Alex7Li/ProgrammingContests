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
        int n;
        cin >> n;
        vi b(n);
        rep(i, 0, n) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << b[i / 2] << " ";
            }
            if (i % 2 == 1) {
                cout << b[n - (i + 1) / 2] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}