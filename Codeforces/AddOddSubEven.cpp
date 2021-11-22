# include <bits/stdc++.h>
//https://codeforces.com/contest/1311/problem/A
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
    int t;
    cin >> t;
    rep(x, 0, t) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0;
        } else if ((a - b) % 2 == 1) {
            cout << 2;
        } else if ((a - b) % 2 == -1) {
            cout << 1;
        } else if ((a - b) % 2 == 0 && a > b) {
            cout << 1;
        } else if ((a - b) % 2 == 0 && a < b){
            cout << 2;
        }
        cout << "\n";
    }
    return 0;
}