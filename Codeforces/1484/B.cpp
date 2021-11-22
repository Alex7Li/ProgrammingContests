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
        int MAX = 0;
        rep(i, 0, n) {
            cin >> a[i];
            MAX = max(MAX, a[i]);
        }
        int pd = -1;
        int nd = -1;
        bool pos = true;
        rep(i, 1, n) {
            if (a[i] - a[i - 1] >= 0) {
                int d = a[i] - a[i - 1];
                if (pd == -1) {
                    pd = d;
                }
                if (pd != d) {
                    pos = false;
                }
            }
            if (a[i] - a[i - 1] <= 0) {
                int d = a[i - 1] - a[i];
                if (nd == -1) {
                    nd = d;
                }
                if (nd != d) {
                    pos = false;
                }
            }
        }
        if(!pos){
            cout << -1;
        }else if (pd == -1 || nd == -1 || (pd + nd) == 0) {
           cout << 0;
       }else if (pd + nd <= MAX) {
            cout << -1;
        } else {
            cout << pd + nd << " " << pd;
        }
        cout << "\n";
    }
    return 0;
}