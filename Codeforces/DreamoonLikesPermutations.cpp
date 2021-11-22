# include <bits/stdc++.h>
//https://codeforces.com/contest/1330/problem/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool isPerm(vector<int> &p, int st, int end) {
    vector<bool> in(end - st, false);
    for (int i = st; i < end; i++) {
        if (p[i] > end - st) {
            return false;
        }
        in[p[i]] = true;
    }
    for (int i = 0; i < end - st; i++) {
        if (!in[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(ntimes, 0, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, 0, n) {
            int v;
            cin >> v;
            a[i] = v - 1;
        }
        int split = 0;
        rep(i, 0, n) {
            if (a[i] + 1 > split) {
                split = a[i] + 1;
            }
        }
        int count = 0;
        if (isPerm(a, 0, split) && isPerm(a, split, n)) {
            count++;
        }
        if (split != n - split) {
            if (isPerm(a, 0, n - split) && isPerm(a, n - split, n)) {
                count += 2;
            }
        }
        if (split == n) {
            count = 0;
        }
        cout << __builtin_popcount(count) << "\n";
        if (count & 1) {
            cout << split << " " << n - split << "\n";
        }
        if (count & 2) {
            cout << n - split << " " << split << "\n";
        }
    }
    return 0;
}