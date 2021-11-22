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
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> areas;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                areas.insert(abs(a[i]-a[j]));
            }
        }
        cout << areas.size()-1 << "\n";
    }
    return 0;
}