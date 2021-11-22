# include <bits/stdc++.h>
//https://atcoder.jp/contests/abc177/submissions/me
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int d, t, s;
    cin >> d >> t >> s;
    cout << (t*s < d ? "No" : "Yes");
    return 0;
}