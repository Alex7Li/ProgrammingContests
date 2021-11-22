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
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << x + y;
        } else {
            cout << max(x, y) * 2 - 1;
        }
        cout << "\n";
    }
    return 0;
}