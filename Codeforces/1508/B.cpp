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
        ll n, k;
        cin >> n >> k;
        if (n < 63 && k > (1LL << (n - 1))) {
            cout << -1 << endl;
        } else {
            k--;
            vector<int> perm(n);
            iota(perm.begin(), perm.end(), 1);
            reverse(perm.begin(), perm.end());
            int start = 62;
            for (int i = 61; i >= 0; --i) {
                if (k & (1LL << i)) {
                    for (int j = i; j < start; ++j) {
                        swap(perm[j], perm[j + 1]);
                    }
                } else {
                    start = i;
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                cout << perm[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}