# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1418/B
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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> l(n);
        vector<int> ul;
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            if (!l[i]) {
                ul.push_back(a[i]);
            }
        }
        sort(ul.begin(), ul.end());
        for (int i = 0; i < n; i++) {
            if (!l[i]) {
                a[i] = ul[ul.size() - 1];
                ul.pop_back();
            }
        }
        rep(i, 0, n) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}