# include <bits/stdc++.h>
// https://codeforces.com/contest/1419/problem/C
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
        ll n, x;
        cin >> n >> x;
        vi a(n);
        bool zero = true;
        bool one = false;
        ll SUM = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if (a[i] != x) {
                zero = false;
            }
            if(a[i] == x){
                one = true;
            }
            SUM += a[i];
        }
        if (SUM == n * x) {
            one = true;
        }
        sort(a.begin(), a.end());
        if (zero) {
            cout << "0";
        } else if (one) {
            cout << "1";
        } else {
            cout << "2";
        }
        cout << "\n";
    }
    return 0;
}