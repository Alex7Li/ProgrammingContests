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
        vector<ll> d(2 * n);
        rep(i, 0, 2 * n) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        bool possible = true;
        vector<ll> vals(1, 0);
        for (int i = 0; i < 2 * n; i += 2) {
            if (d[i] != d[i + 1]) {
                possible = false;
            }
            if (i > 0) {
                ll left = (n - i / 2);
                if ((d[i - 1] - d[i]) % (2 * left) != 0) {
                    possible = false;
                }
                ll diff = (d[i - 1] - d[i]) / (2 * left);
                if(diff == 0){
                    possible = false;
                }
                vals.push_back(vals[vals.size() - 1] - diff);
            }
        }
        ll minSum = 0;
        for(int i = 0; i < vals.size(); i++){
            vals[i] -= vals[vals.size() - 1] - 1;
            minSum += vals[i] * 2;
        }
        if (d[2 * n - 1] - minSum < 0 || (d[2 * n - 1] - minSum) % (2 * n) != 0) {
            possible = false;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}