# include <bits/stdc++.h>
// https://codeforces.com/contest/1503
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
        int x;
        int y;
        string s;
        cin >> x >> y >> s;
        string s2 = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '?') {
                s2 += s[i];
            }
        }
        ll c = 0;
        for (int i = 1; i < s2.size(); ++i) {
            if (s2[i - 1] == 'C' && s2[i] == 'J') {
                c += x;
            }
            if (s2[i - 1] == 'J' && s2[i] == 'C') {
                c += y;
            }
        }
        cout << "Case #" << tt+1 << ": " << c << "\n";
    }
    return 0;
}