# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1326/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    rep(a, 0, t) {
        cin >> n;
        if (n == 1) {
            cout << "-1";
        } else {
            rep(i, 0, n - 1) {
                cout << "5";
            }
            cout << "4";
        }
        cout << "\n";
    }
    return 0;
}