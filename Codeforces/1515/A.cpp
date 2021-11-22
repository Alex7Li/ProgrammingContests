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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int pSum = 0;
        bool done = false;
        for (int i = 0; i < n; ++i) {
            pSum += a[i];
            if (pSum >= x) {
                if (pSum == x && i == n - 1) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    if (pSum == x) {
                        swap(a[i], a[i + 1]);
                    }
                    for (int j = 0; j < n; ++j) {
                        cout << a[j] << " ";
                    }
                    cout << "\n";
                }
                done = true;
                break;
            }
        }
        if (!done) {
            cout << "YES\n";
            for (int j = 0; j < n; ++j) {
                cout << a[j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}