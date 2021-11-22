# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1501/B
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
        vector<bool> drenched(n);
        int i = n - 1;
        while (i >= 0) {
            if (a[i] > 0) {
                int left = a[i];
                while (left > 0) {
                    drenched[i] = true;
                    i--;
                    left--;
                    if(i < 0){
                        break;
                    }
                    left = max(left, a[i]);
                }
            } else {
                drenched[i] = false;
                i--;
            }
        }
        rep(j, 0, n) {
            cout << drenched[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}