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
        vector<int> a(n);
        bool pos = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int j = sqrt(a[i]);
            if (j * j != a[i]) {
                pos = true;
            }
        }
        cout << (pos ? "YES" : "NO") << "\n";

    }
    return 0;
}