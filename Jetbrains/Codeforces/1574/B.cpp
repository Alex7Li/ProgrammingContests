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
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int minB = max(a - b - c - 1, b - a - c - 1);
        minB = max(minB, c - a - b - 1);
        if (minB <= m && m <= max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0)){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    } 
    return 0;
}