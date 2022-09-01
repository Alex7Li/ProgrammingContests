#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        string s;
        cin >> s;
        string t;
        cin >> t;
        vi c(26);
        for(int i = 0; i < s.length(); i++) {
          c[s[i] - 'a']++;
        }
        string out;
        for (int i = 0; i < c[0]; i++)
        {
          out += 'a';
        }
        if ((t == "abc") && c[0] && c[1] && c[2])
        {
        for (int i = 0; i < c[2]; i++)
        {
          out += 'c';
        }
        for (int i = 0; i < c[1]; i++)
        {
          out += 'b';
        }
        }else {
        for (int i = 0; i < c[1]; i++)
        {
          out += 'b';
        }
        for (int i = 0; i < c[2]; i++)
        {
          out += 'c';
        }
        }
        for(int k = 3; k < 26; k++) {
        for (int i = 0; i < c[k]; i++)
        {
          out += char('a' + k);
        }
        }
        cout << out << "\n";
    }
    return 0;
}