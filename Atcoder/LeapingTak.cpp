# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define MOD 998244353
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct Tree {
    typedef ll T;
    static constexpr T unit = 0ll;

    T f(T a, T b) { return (a + b) % MOD; } // (any associative fn)
    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }

    T query(int b, int e) { // query [b, e)
        b = max(b, 0);
        e = max(e, 0);
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi l(k);
    vi r(k);
    for (int i = 0; i < k; i++) {
        cin >> l[i] >> r[i];
    }
    Tree t(n + 1);
    t.update(0, 1);
    rep(i, 1, n) {
        ll s = 0;
        rep(j, 0, k) {
            s = (s + t.query(i - r[j], i)) % MOD;
            s = (s - t.query(i - (l[j] - 1), i)) % MOD;
        }
        s = (s + MOD) % MOD;
        t.update(i, s);
    }
    cout << t.query(n - 1, n);
    return 0;
}