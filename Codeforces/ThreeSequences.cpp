# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1406/D
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef vector<int> vi;

ll solve(ll s, ll u) {
    return floor((s + u + 1) *.5);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    vector<ll> d(n - 1);
    ll upSum = 0;
    ll downSum = 0;
    cin >> a[0];
    rep(i, 1, n) {
        cin >> a[i];
        d[i - 1] = a[i] - a[i - 1];
        if (d[i - 1] > 0) {
            upSum += d[i - 1];
        } else {
            downSum += d[i - 1];
        }
    }
    ll s = a[0];
    int q;
    cin >> q;
    cout << solve(s, upSum) << "\n";
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        if (l == 1) {
            s += x;
        } else {
            int ind = l - 2;
            if (d[ind] > 0) {
                upSum -= d[ind];
            }
            d[ind] += x;
            if (d[ind] > 0) {
                upSum += d[ind];
            }
        }
        if (r != n) {
            int ind = r - 1;
            if (d[ind] > 0) {
                upSum -= d[ind];
            }
            d[ind] -= x;
            if (d[ind] > 0) {
                upSum += d[ind];
            }
        }
        cout << solve(s, upSum) << "\n";
    }

    return 0;
}