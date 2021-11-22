# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1501/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vi a(n + 1);
        vi b(n + 1);
        vi tm(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i + 1];
            cin >> b[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            cin >> tm[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // delay at station i
            ans += (b[i] - a[i] + 1) / 2;
            ans = max(ans, b[i]);
            // travel to station i+1
            ans += a[i + 1] - b[i] + tm[i];
        }
        cout << ans << endl;
    }
    return 0;
}