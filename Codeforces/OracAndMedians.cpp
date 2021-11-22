# include <bits/stdc++.h>
//http://codeforces.com/contest/1349/problem/B
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
    rep(tt, 0, t) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        bool possible = false;
        int count = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if (a[i] == k) {
                count++;
            }
        }
        if (count == 0) {
            cout << "no";
        } else if (n == 1) {
            cout << "yes";
        } else {
            possible = false;
            rep(i, 0, n - 1) {
                if (a[i] >= k && a[i + 1] >= k) {
                    possible = true;
                }
            }
            rep(i, 0, n - 2) {
                if (a[i] >= k && a[i + 2] >= k) {
                    if (count > 1) {
                        possible = true;
                    } else {//count = 1
                        if (a[i + 1] == k) {
                            continue;
                        } else {
                            possible = true;
                        }
                    }
                }
            }
            if (possible) {
                cout << "yes";
            } else {
                cout << "no";
            }
        }
        cout << "\n";
    }
    return 0;
}