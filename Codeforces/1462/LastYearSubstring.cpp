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
    string goal = "2020";
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ok = 0;

        if (s.size() >= 4) {
            rep(i, 0, 4) {
                if (s[i] == goal[i]) {
                    ok++;
                } else {
                    break;
                }
            }
            rep(i, 1, 5) {
                if (s[n - i] == goal[4 - i]) {
                    ok++;
                } else {
                    break;
                }
            }
        }
        if (ok >= 4) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}