# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<double> vi;

vector<vi> times(vector<vi> &a, vector<vi> &b) {
    vector<vi> c(a.size(), vi(a.size(), 0));
    rep(i, 0, a.size()) {
        rep(j, 0, a.size()) {
            rep(k, 0, a.size()) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

vector<vi> pow(vector<vi> &a, int p) {
    if (p == 0) {
        vector<vi> c(a.size(), vi(a.size(), 0));
        for (int i = 0; i < c.size(); i++) {
            c[i][i] = 1;
        }
        return c;
    } else {
        int rem = p%2;
        vector<vi> half = pow(a, p/2);
        vector<vi> whole = times(half, half);
        if(rem!=0) {
            whole = times(whole, a);
        }
        return whole;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }
    vector<vi> p = pow(a, m);
    rep(i, 0, n) {
        cout << p[0][i] << "\n";
    }
    return 0;
}
