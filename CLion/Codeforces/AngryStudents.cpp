# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1287/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(cases, 0, t) {
        int n;
        cin >> n;
        int maxT = 0;
        int cur = -1;
        string str;
        cin >> str;
        for (int i = 0; i < n; i++) {
            if (str[i] == 'A') {
                cur = 0;
            } else if (cur != -1) {
                cur++;
                maxT = max(maxT, cur);
            }
        }
        if(cur==-1) {
            cout << 0 << "\n";
        }else{
            cout << maxT << "\n";
        }
    }
    return 0;
}