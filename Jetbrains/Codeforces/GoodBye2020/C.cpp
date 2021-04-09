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
        string s;
        cin >> s;
        int count = 0;
        rep(i, 1, s.size()) {
            if (s[i] == s[i - 1]) {
                s[i] = 'X';
                count++;
            } else if (i >= 2 && s[i] == s[i - 2]) {
                s[i] = 'X';
                count++;
            }
        }
        cout << count << "\n";

    }
    return 0;
}