# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    typedef ll T;
    static constexpr T unit = LONG_LONG_MIN;

    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

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

    T get(int a) {
        return query(a, a + 1);
    }
};

ll solve(vi &h, vector<ll> &b, int n) {
    Tree t(n + 1);
    t.update(0, 0);
    stack<int> lastMinPos;
    rep(i, 1, n + 1) {
        while (!lastMinPos.empty() && h[lastMinPos.top()] > h[i]) {
            lastMinPos.pop();
        }
        ll last = 0;
        ll score = LONG_LONG_MIN;
        if (!lastMinPos.empty()) {
            last = lastMinPos.top();
            score = t.get(last);
        }
        score = max(score, b[i] + t.query(last, i));
        if (last != 1) {
        }
        lastMinPos.push(i);
        t.update(i, score);
    }
    return t.get(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi h(n + 1, 0);
    vector<ll> b(n + 1, 0);
    h[0] = n+1;
    rep(i, 1, n + 1) {
        cin >> h[i];
    }
    rep(i, 1, n + 1) {
        cin >> b[i];
    }
    cout << solve(h, b, n);
    return 0;
}