# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vector<vi> makeDiffs(vi a) {
    int n = a.size();
    vector<vi> d(n, vi(n, 0));
    rep(i, 0, n) {
        d[i][i] = 0;
        rep(j, i + 1, i + n) {
            d[i][j % n] = d[i][(j - 1) % n] + a[(j - 1) % n];
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, s, n;
    cin >> r >> s >> n;
    vi a(r);
    vi b(s);
    vi c(n);
    int aSum = 0;
    int bSum = 0;
    rep(i, 0, r) {
        cin >> a[i];
        aSum += a[i];
    }
    rep(i, 0, s) {
        cin >> b[i];
        bSum += b[i];
    }
    vector<vi> aDiff = makeDiffs(a);
    vector<vi> bDiff = makeDiffs(b);
    int maxC = 0;
    rep(i, 0, n) {
        cin >> c[i];
        maxC = max(maxC, c[i]);
    }
    vector<bool> ok(maxC + aSum + bSum + 3, false);
    ok[0] = true;
    rep(i, 0, maxC + 1) {
        if (ok[i]) {
            ok[i + aSum] = true;
            ok[i + bSum] = true;
        }
    }
    vector<vvb> dp(n + 1, vvb(r, vb(s, false)));
    dp[0][0][0] = true;
    rep(i, 0, n) {
        rep(j, 0, r) {
            rep(k, 0, s) {
                if (dp[i][j][k]) {
                    rep(j2, 0, r) {
                        rep(k2, 0, s) {
                            int cost = aDiff[j][j2] + bDiff[k][k2];
                            if (cost > c[i]) {
                                continue;
                            }
                            dp[i + 1][j2][k2] = dp[i + 1][j2][k2] | ok[c[i] - cost];
                        }
                    }
                }
            }
        }
    }
    bool pos = false;
    rep(j, 0, r) {
        rep(k, 0, s) {
            if (dp[n][j][k]) {
                pos = true;
            }
        }
    }
    cout << (pos ? "Yes" : "No");
    return 0;
}