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
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        ll sum = 0;
        ll have = 0;
        bool pos = true;
        for (int i = 0; i < n; i++) {
            sum += i;
            have += a[i];
            if (have < sum) {
                pos = false;
            }
        }
        cout << (pos ? "YES" : "NO") << "\n";
    }
    return 0;
}