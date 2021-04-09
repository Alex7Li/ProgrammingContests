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
    rep(tt, 0, t) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2 == 0) {
            bool hasEven = false;
            for (int i = 1; i < n; i += 2) {
                if ((s[i] - '0') % 2 == 0) {
                    hasEven = true;
                }
            }
            cout << 1 + hasEven;
        } else {
            bool hasOdd = false;
            for (int i = 0; i < n; i += 2) {
                if ((s[i] - '0') % 2 != 0) {
                    hasOdd = true;
                }
            }
            cout << 2 - hasOdd;
        }
        cout << "\n";
    }
    return 0;
}