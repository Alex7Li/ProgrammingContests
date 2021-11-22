# include <bits/stdc++.h>

#include <utility>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef int T;
static constexpr T unit = INT_MAX;
T f(T a, T b) { return min(a, b); } // (any associative fn)

struct Tree {
    vector<T> s; int n;
    explicit Tree(int n = 0) : s(2*n, unit), n(n) {}
    Tree(int n, vi &a) : s(2 * n), n(n) {
        assert(a.size() == n);
        for (int i = 0; i < a.size(); ++i) {
            s[i + n] = a[i];
        }
        for (int i = a.size() - 1; i >= 0; --i) {
            s[i] = f(s[i * 2], s[i * 2 + 1]);
        }
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

struct Tree2D {
    Tree f2D(Tree& a, Tree& b) {
        Tree result = Tree(a.n);
        for (int i = 0; i < a.s.size(); ++i) {
            result.s[i] = f(a.s[i], b.s[i]);
        }
        return result;
    }
    vector<Tree> s; int n; int m;
    explicit Tree2D(int n =0, int m =0) : n(n), m(m) {};
    Tree2D(int n, int m, vector<vi>& a) : s(2 * n), n(n), m(m) {
        for (int i = 0; i < a.size(); ++i) {
           s[i + n] = Tree(m, a[i]);
        }
        for (int i = a.size() - 1; i >= 0; --i) {
            s[i] = f2D(s[i * 2], s[i * 2 + 1]);
        }
    }
    // query the [nl, nr) by [ml, mr) box
    T query(int nl, int nr, int ml, int mr) {
        T ra = unit, rb = unit;
        for (nl += n, nr += n; nl < nr; nl /= 2, nr /= 2) {
            if (nl % 2) ra = f(ra, s[nl++].query(ml, mr));
            if (nr % 2) rb = f(s[--nr].query(ml, mr), rb);
        }
        return f(ra, rb);
    }
};

Tree2D tree;

void init(std::vector<std::vector<int>> arr) {
    tree = Tree2D(arr.size(), arr[0].size(), arr);
}

int query(int a, int b, int c, int d) {
    return tree.query(a, b + 1, c, d + 1);
}

int main() {
    init({{1, 2}, {3, 4}});
    cout << query(0, 1, 0, 1) << endl;
    cout << query(1, 1, 0, 1) << endl;
    cout << query(0, 0, 1, 1) << endl;
    assert(query(0, 1, 0, 1) == 1);
    assert(query(1, 1, 0, 1) == 3);
    assert(query(0, 0, 1, 1) == 2);
}
