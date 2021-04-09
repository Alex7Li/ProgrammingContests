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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = s.size();
    ll ways = 0;
    if (n > 40) {
        ways += (1LL << (l - 1)) * (n - 40LL);
        n = 40;
    }
    vector<vi> g(n, vi(n + l - 1, 0));
    for (int i = 0; i < n; i++) {
        g[i][n - i - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[0].size(); j++) {
            g[i][j] += (i == 0 ? 0 : g[i - 1][j]) + (j == 0 ? 0 : g[i][j - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        ways += g[i][n + l - i - 2];
    }
    cout << ways << endl;
    return 0;
}