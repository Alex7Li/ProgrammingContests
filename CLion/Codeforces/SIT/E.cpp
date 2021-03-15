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
        ll x, y;
        cin >> x >> y;
        ll day = 0;
        while (x != y) {
            if (x > y) {
                swap(x, y);
            }
            ll temp = x;
            day += y / x;
            x = y % x;
            if (x == 0) {
                day--;
                x += temp;
            }
            y = temp;
        }
        if (x != 1) {
            cout << -1 << "\n";
        } else {
            cout << day << "\n";
        }
    }
    return 0;
}