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
        int x_1, y_1, x_2, y_2, x_3, y_3;
        cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
        int x, y;
        if (x_1 == x_2) {
            x = x_3;
        } else if (x_1 == x_3) {
            x = x_2;
        } else {
            x = x_1;
        }
        if (y_1 == y_2) {
            y = y_3;
        } else if (y_1 == y_3) {
            y = y_2;
        } else {
            y = y_1;
        }
        cout << x << " " << y << '\n';
    }
    return 0;
}