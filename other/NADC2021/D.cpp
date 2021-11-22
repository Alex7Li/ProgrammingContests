# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 998'244'353LL;

struct ANDTree {
    typedef ll T;
    static constexpr T unit = (1LL << 62) - 1LL;

    T f(T a, T b) { return a & b; } // (any associative fn)
    vector<T> s;
    int n;

    ANDTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }

    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

struct PLUSTree {
    typedef ll T;
    static constexpr T unit = 0LL;

    T f(T a, T b) { return (a + b) % MOD; } // (any associative fn)
    vector<T> s;
    int n;

    PLUSTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }

    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

PLUSTree genDP(int end, int n, vector<int> &backTo) {
    PLUSTree dp(end + 1, 0);
    dp.update(n, 1);
    for (int i = n + 1; i <= end; ++i) {
        if (backTo[i - 1] <= n && backTo[i - 1] > end - n) {
            backTo[i - 1] = n + 1;
        }
        ll val = dp.query(backTo[i - 1], i);
        dp.update(i, val);
        //  cerr << i << " " << val << "\n";
    }
    return dp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    int len = n * 2 + 2;
    ANDTree andTree(len);
    for (int i = 0; i < len; ++i) {
        andTree.update(i, a[i % n]);
    }
    vector<int> backTo(len);
    for (int i = 0; i < backTo.size(); ++i) {
        int min = 0;
        int max = i;
        while (min != max) {
            int mid = (min + max) / 2;
            if (min + 1 == max) {
                mid = min;
            }
            if (andTree.query(mid, i + 1) == 0LL) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        backTo[i] = min;
    }
    ll ans = 0LL;
    if (backTo[len - 1] == 0) {
        cerr << "EZ case";
        ans = 1LL;
        for (int i = 0; i < n; ++i) {
            ans = (2 * ans) % MOD;
        }
        ans = (ans + MOD - n) % MOD;
    } else {
        ans = genDP(2 * n, n, backTo).query(2 * n, 2 * n + 1);
        int end = 2 * n - 1;
        ll AND = a[0] & a[end];
        while (end > n + 1 && AND != 0) {
            PLUSTree dp = genDP(end, n, backTo);
            int E = end + 1;
            while (end > n + 1 && AND == (AND & a[end - 1])) {
                AND = AND & a[end - 1];
                end--;
            }
            ll add = dp.query(end, E);
            end--;
            AND &= a[end];
            ans = (ans + add) % MOD;
            cerr << "Done with interval [" << end << " " << E << ")" << add << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
