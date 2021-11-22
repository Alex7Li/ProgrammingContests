# include <bits/stdc++.h>
//https://atcoder.jp/contests/abc179/tasks/abc179_c
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    n--;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += n / i;
    }
    cout << ans;
    return 0;
}