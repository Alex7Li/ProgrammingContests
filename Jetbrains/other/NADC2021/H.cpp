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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int best = 0;
    for (int i = 0; i < s[0].size(); ++i) {
        for (int j = i + 1; j < s[0].size(); ++j) {
            int len = j - i;
            string sub = s[0].substr(i, j);
            bool ok = true;
            for (int k = 0; k < n; ++k) {
                if (s[k].find(sub) == s[k].size()) {
                    ok = false;
                }
            }
            if (ok) {
                best = len;
            }
        }
    }
    cout << best << endl;
    return 0;
}