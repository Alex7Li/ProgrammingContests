# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    typedef int T;
    static constexpr T unit = 0;

    T f(T a, T b) { return a + b; } // (any associative fn)
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int q;
    cin >> q;
    Tree vTree(n + 1);
    Tree hTree(n + 1);
    vector<int> qt;
    vector<int> qx;
    for (int i = 0; i < q; i++) {
        int t;
        int x;
        cin >> t >> x;
        qt.push_back(t);
        qx.push_back(--x);
    }
    for (int i = 0; i < q; i++) {
        if (qt[i] == 1) {
            vTree.update(qx[i], 1);
        } else {
            hTree.update(qx[i], 1);
        }
    }
    ll maxV = n - 1;
    ll maxH = n - 1;
    ll sum = 0;
    for (int i = 0; i < q; i++) {
        if (qt[i] == 1) {
            if (qx[i] < maxV) {
                sum += vTree.query(qx[i], maxV) * (maxH - 1);
                maxV = qx[i];
            }
        } else {
            if (qx[i] < maxH) {
                sum += hTree.query(qx[i], maxH) * (maxV - 1);
                maxH = qx[i];
            }
        }
    }
    cout << (n - 2ll) * (n - 2ll) - sum;
    return 0;
}