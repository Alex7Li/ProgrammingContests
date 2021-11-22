# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
# define MOD 1000000007
// Wrong
bool ok(int i, int j) {
    if (i >= 0 && j >= 0 && i < 3 && j < 3) {
        return true;
    }
    return false;
}

ll power(ll base, ll n) {
    if (n == 0) {
        return 1LL;
    } else {
        ll half = power(base, n / 2);
        ll all = (half * half) % MOD;
        return (all * (n % 2 == 1 ? base : 1)) % MOD;
    }
}

ll choose(ll n, ll k) {
    ll p = 1;
    for (int i = n - k + 1; i <= n; ++i) {
        p = (p * i) % MOD;
    }
    /*
    for (int i = 1; i <= k; i++) {
        p = (p * power(i, MOD - 2)) % MOD;
    }
     */
    return p;
}


vi get_state(int hash, int n) {
    vi s(n);
    rep(i, 0, s.size()) {
        s[i] = hash % 9;
        hash /= 9;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<vi> grid(3, vi(3, -1));
        int ind = 0;
        rep(i, 0, 3) {
            string s;
            cin >> s;
            rep(j, 0, 3) {
                if (s[j] == 'x') {
                    if (i + j != 2) {
                        grid[i][j] = ind++;
                    } else {
                        grid[i][j] = -2;
                    }
                }
            }
        }
        vector<vi> fix;
        vector<vi> check;
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                if (grid[i][j] != -1) {
                    vi v = vi(0);
                    if (i + j != 2) {
                        if (ok(i - 1, j) && grid[i - 1][j] >= 0) {
                            v.push_back(grid[i - 1][j]);
                        }
                        if (ok(i - 2, j) && grid[i - 2][j] >= 0) {
                            v.push_back(grid[i - 2][j]);
                        }
                        if (ok(i, j - 1) && grid[i][j - 1] >= 0) {
                            v.push_back(grid[i][j - 1]);
                        }
                        if (ok(i, j - 2) && grid[i][j - 2] >= 0) {
                            v.push_back(grid[i][j - 2]);
                        }
                        if (ok(i + 1, j) && grid[i + 1][j] >= 0) {
                            v.push_back(grid[i + 1][j]);
                        }
                        if (ok(i + 2, j) && grid[i + 2][j] >= 0) {
                            v.push_back(grid[i + 2][j]);
                        }
                        if (ok(i, j + 1) && grid[i][j + 1] >= 0) {
                            v.push_back(grid[i][j + 1]);
                        }
                        if (ok(i, j + 2) && grid[i][j + 2] >= 0) {
                            v.push_back(grid[i][j + 2]);
                        }
                        fix.push_back(v);
                    } else {
                        if (ok(i - 1, j) && grid[i - 1][j] != -1) {
                            v.push_back(grid[i - 1][j]);
                        }
                        if (ok(i - 2, j) && grid[i - 2][j] != -1) {
                            v.push_back(grid[i - 2][j]);
                        }
                        if (ok(i, j - 1) && grid[i][j - 1] != -1) {
                            v.push_back(grid[i][j - 1]);
                        }
                        if (ok(i, j - 2) && grid[i][j - 2] != -1) {
                            v.push_back(grid[i][j - 2]);
                        }
                        if (ok(i + 1, j) && grid[i + 1][j] != -1) {
                            v.push_back(grid[i + 1][j]);
                        }
                        if (ok(i + 2, j) && grid[i + 2][j] != -1) {
                            v.push_back(grid[i + 2][j]);
                        }
                        if (ok(i, j + 1) && grid[i][j + 1] != -1) {
                            v.push_back(grid[i][j + 1]);
                        }
                        if (ok(i, j + 2) && grid[i][j + 2] != -1) {
                            v.push_back(grid[i][j + 2]);
                        }
                        check.push_back(v);
                    }
                }
            }
        }
        ll ans = 0;
        int p = int(pow(min(9, n), fix.size()));
        rep(i, 0, p) {
            vi st = get_state(i, fix.size());
            ll extra = 1;
            for (int j = 0; j < fix.size(); j++) {
                trav(k, fix[j]) {
                    if (st[j] == st[k]) {
                        extra = 0;
                    }
                }
            }
            for (int j = 0; j < check.size(); j++) {
                set<int> bad;
                trav(k, check[j]) {
                    bad.insert(st[k]);
                }
                extra *= max(0u, min(9, n) - bad.size());
            }
            ans = (ans + extra) % MOD;
        }
        if (check.size() + fix.size() == 0) {
            cout << 1 << endl;
        } else {
            cout << (ans * (n < 9 ? 1 : choose(n, 9))) % MOD << endl;
        }
    }
    return 0;
}