# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1418/A
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
        ll x, y, k;
        cin >> x >> y >> k;
        ll gain = x - 1;
        ll cost = gain - 1 + (k - 1) + y * k;
        cout << k + cost / gain << "\n";
    }
    return 0;
}