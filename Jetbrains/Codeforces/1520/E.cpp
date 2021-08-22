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
        string s;
        cin >> s;
        int l = 0;
        int r = s.size();
        int lw = 0;
        int rw = 0;
        ll c = 0;
        while (l < r) {
            while(l < r && s[l]=='*'){
                lw++;
                l++;
            }
            while(l < r && s[r - 1] == '*'){
                rw++;
                r--;
            }
            if (lw <= rw) {
                while (l < r && s[l] == '.'){
                    c += lw;
                    l++;
                };
            } else {
                while(l < r && s[r - 1] == '.') {
                    c += rw;
                    r--;
                }
            }
        }
        cout << c << "\n";
    }
    return 0;
}