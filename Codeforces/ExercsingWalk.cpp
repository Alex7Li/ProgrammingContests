# include <bits/stdc++.h>
//http://codeforces.com/contest/1332/problem/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, a, b, c, d;
    cin >> t;
    rep(time, 0, t) {
        int x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        int endx = b - a;
        int endy = d - c;
        y1 -= y;
        y2 -= y;
        x1 -= x;
        x2 -= x;
        bool pos = true;
        if (max(0, endx) > x2 || min(0, endx) < x1 || max(0, endy) > y2 || min(0, endy) < y1) {
            pos = false;
        }
        if (endx == 0 && x1 == 0 && x2 == 0 && b > 0) {
            pos = false;
        }
        if (endy == 0 && y1 == 0 && y2 == 0 && d > 0) {
            pos = false;
        }
        if (pos) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}