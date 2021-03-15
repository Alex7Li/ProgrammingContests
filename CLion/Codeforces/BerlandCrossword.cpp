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
        vi s(4);
        cin >> n >> s[0] >> s[1] >> s[2] >> s[3];
        bool pos = true;
        rep(i, 0, 4) {
            if (s[i] == 0 && (s[(i + 1) % 4] == n || s[(i + 3) % 4] == n)) {
                pos = false;
            }
            int allowed = min(2, s[i]) + min(2, s[(i + 2) % 4]);
            int required = max(0, s[(i + 1) % 4] - (n - 2))
                           + max(0, s[(i + 3) % 4] - (n - 2));
            if (allowed < required) {
                pos = false;
            }
        }
        cout << (pos ? "YES" : "NO") << "\n";
    }
    return 0;
}