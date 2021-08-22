# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line &o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

//Container where you can add lines of the form kx+m, and
//query maximum values at points x
struct LineContainer : multiset<Line, less<>> {
    // (for doubles , use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 0;
    vi x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        ans += x[i] * b;
    }
    vector<ll> pSum(n + 1);
    pSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pSum[i] = pSum[i - 1] + x[i - 1];
    }
    LineContainer lc;
    vector<ll> dp(n + 1);
    dp[0] = ans;
    lc.add(0, dp[0] + c);
    for (int i = 1; i <= n; ++i) {
        dp[i] = a * pSum[i] * pSum[i] + lc.query(pSum[i]);
        lc.add(-2 * a * pSum[i], a * pSum[i] * pSum[i] + c + dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}