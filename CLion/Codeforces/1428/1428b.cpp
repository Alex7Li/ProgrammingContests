# include <bits/stdc++.h>
// https://codeforces.com/contest/1428/problem/A
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
        string s;
        cin >> s;
        int count = 0;
        bool r = false;
        bool l = false;
        for (int i = 0; i < n; i++) {
            if ((s[i] == '<' && s[(i + 1) % n] == '>') || (s[i] == '>' && s[(i + 1) % n] == '<')) {
                count++;
            }
            if (s[i] == '<') {
                l = true;
            }
            if (s[i] == '>') {
                r = true;
            }
        }
        if (l && r) {
            for (int i = 0; i < n; i++) {
                if ((s[i] == '<' && s[(i + 1) % n] == '<') || (s[i] == '>' && s[(i + 1) % n] == '>')) {
                    count++;
                }
            }
        }
        cout << (n - count) << "\n";
    }
    return 0;
}