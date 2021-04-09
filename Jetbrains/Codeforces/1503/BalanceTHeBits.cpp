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
        string s;
        cin >> s;
        int ones = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ones++;
            }
        }
        bool pos = true;
        vector<char> a(n);
        int aP = 0;
        int bP = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (ones > 0) {
                    a[i] = '(';
                    aP++;
                    bP++;
                    ones -= 2;
                } else {
                    a[i] = ')';
                    aP--;
                    bP--;
                }
            } else if (s[i] == '0') {
                if (aP >= bP) {
                    a[i] = ')';
                    aP--;
                    bP++;
                } else {
                    a[i] = '(';
                    aP++;
                    bP--;
                }
            }
            if (aP < 0 || bP < 0) {
                pos = false;
            }
        }
        if (aP != 0 || bP != 0) {
            pos = false;
        }
        if (pos) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << a[i];
            }
            cout << "\n";
            for (int i = 0; i < n; ++i) {
                if (s[i] == '1') {
                    cout << a[i];
                } else {
                    cout << (a[i] == ')' ? '(' : ')');
                }
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }

    }
    return 0;
}