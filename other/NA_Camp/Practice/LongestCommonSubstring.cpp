# include <bits/stdc++.h>

using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int best = 0;
    for (int i = 0; i < s[0].size(); ++i) {
        for (int j = i + 1; j <= s[0].size(); ++j) {
            string mid = s[0].substr(i, j - i);
            bool pos = true;
            for (int k = 1; k < n; ++k) {
                if (s[k].find(mid) == string::npos) {
                    pos = false;
                }
            }
            if (pos) {
                best = max(best, j - i);
            }
        }
    }
    cout << best << endl;
    return 0;
}