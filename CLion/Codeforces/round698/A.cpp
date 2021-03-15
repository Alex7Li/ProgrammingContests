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
        rep(i, 0, n) {
            cin >> a[i];
        }
        int streak = 1;
        int maxStreak = 1;
        rep(i, 1, n) {
            if (a[i] == a[i - 1]) {
                streak++;
                maxStreak = max(maxStreak, streak);
            } else {
                streak = 1;
            }
        }
        cout << maxStreak << "\n";

    }
    return 0;
}