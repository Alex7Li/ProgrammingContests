# include <bits/stdc++.h>
//https://codeforces.com/contest/1305/problem/A
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
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << a[0];
        rep(j, 1, n) {
            cout << " " << a[j];
        }
        cout << "\n" << b[0];
        rep(j, 1, n) {
            cout << " " << b[j];
        }
        cout << "\n";
    }
    return 0;
}