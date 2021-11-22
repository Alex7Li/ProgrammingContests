# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
//https://codeforces.com/contest/1305/problem/C
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << 0;
        return 0;
    }
    vi a(n, 0);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int prod = 1;
    rep(i, 0, n) {
        rep(j, i+1, n) {
            prod = (prod * (abs(a[i] - a[j]) % m)) % m;
        }
    }
    cout << prod;
    return 0;
}