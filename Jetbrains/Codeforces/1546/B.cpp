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
        int n, m;
        cin >> n >> m;
        assert(n % 2 == 1);
        vector<string> strs(n);
        for (int i = 0; i < n; ++i) {
            cin >> strs[i];
        }
        vector<string> strs2(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> strs2[i];
        }
        string out = "";
        for (int i = 0; i < m; ++i) {
            vector<int> multiS(26);
            for (int j = 0; j < n; ++j) {
                int diff = strs[j][i] - 'a';
                multiS[diff]++;
            }
            for (int j = 0; j < n - 1; ++j) {
                int diff = strs2[j][i] - 'a';
                multiS[diff]--;
            }
            for (int j = 0; j < 26; ++j) {
                if (multiS[j] > 0) {
                    out += (char)(j + 'a');
                }
            }
        }
        cout << out <<  endl;
    }
    return 0;
}