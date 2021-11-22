# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool solve(int u, int v) {
    int extra = 0;
    for (int i = 30; i >= 0; i--) {
        int pow = 1 << i;
        if (v & pow) {
            extra++;
        }
        if (u & pow) {
            extra = max(0, extra - 1);
        }
    }
    return extra == 0 && v >= u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int u, v;
        cin >> u >> v;
        cout << (solve(u, v) ? "YES" : "NO") << endl;
    }
    return 0;
}