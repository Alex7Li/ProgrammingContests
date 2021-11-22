# include <bits/stdc++.h>
// https://codeforces.com/contest/1428/problem/A
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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 || y1 == y2) {
            cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
        } else {

            cout << abs(x1 - x2) + 2 + abs(y1 - y2) << "\n";
        }
    }
    return 0;
}