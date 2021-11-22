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
        int n, m, p;
        cin >> n >> m >> p;
        if (m < n) {
            swap(n, m);
        }
        bool pos = false;
        for (int i = 1; i <= n && i * i <= p; i++) {
            if (p % i == 0 && p / i <= m) {
                pos = true;
            }
        }
        cout << (pos?"YES":"NO") << "\n";
    }
    return 0;
}