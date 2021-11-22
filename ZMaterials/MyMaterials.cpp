# include <bits/stdc++.h>
// speed up somewhat, sometimes:
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
T gcd(T a, T b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

struct Loc {
    int x;
    int y;

    // Must be overloaded for unordered map.
    // hashtable is better than unordered map!
    bool operator==(const Loc &other) const {
        return x == other.x && y == other.y;
    }
};

struct Loc2 {
    int x;
    int y;

    // Overloaded for ordered map. If !(x<y), !(y<x), then
    //  x will be considered equal to y.
    bool operator<(const Loc2 &o) const {
        return x == o.x ? y < o.y : x < o.x;
    }
};


// to string function, required for the hash map from gnu_pbds
ostream &operator<<(ostream &stream, const Loc &l) {
    return stream << l.x << " " << l.y;
}

/*
 * Begin hash_map description
 */
#include <ext/pb_ds/assoc_container.hpp>

using ui64 = uint64_t;

struct chash {
    static auto const c = ui64(7e18) + 23;

    ui64 operator()(const Loc &l) const {
        return __builtin_bswap64((l.x + l.y) * c);
    }
};

template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v, chash>;

int main() {
    // hash_map declared above, it is better than unordered_map in that
    // it is ~5 times faster. No real downsides,
    // though it creates hackable code if you aren't careful with the hash
    // function (https://codeforces.com/blog/entry/60737)
    // Remember to update the key data structure with the == operator.
    // You also need to create the output stream function for some reason
    hash_map<Loc, int> locU;

    // Unordered map, you probably want to use hash_map above though.
    auto locHash = [](const Loc &l) { return l.x + (l.y << 4); };
    unordered_map<Loc, int, decltype(locHash)> unordered_example(50, locHash);

    // Lambda for ordered map. If !(x<y), !(y<x), then
    //  x will be considered equal to y.
    auto order = [](const Loc &l, const Loc &l2) {
        return l.x == l2.x ? l.y < l2.y : l.x < l2.x;
    };
    map<Loc, int, decltype(order)> locO(order);
    map<Loc2, int> locO2;
}

// return false if there is a loop. UNTESTED
bool topSort(int ind, vector<int> &seen, vector<vector<int>> &g) {
    seen[ind] = 1;
    trav(next, g[ind]) {
        if (seen[next] != 2) {
            if (seen[next] == 1) {
                return false; // detect loop
            }
            if (!topSort(next, seen, g)) {
                return false;
            }
        }
    }
    seen[ind] = 2;
    return true;
}

bool hasCycle(vector<vector<int>> &g) {
    vector<int> seen(g.size());
    for (int i = 0; i < g.size(); i++) {
        if (seen[i] == 0) {
            if (!topSort(i, seen, g)) {
                return true;
            }
        }
    }
    return false;
}

template<typename T>
vector<int> sortInds(const vector<T> &v) {
    // initialize original index locations
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

    return idx;
}

// https://github.com/Baky9912/CppFractions/blob/main/fractions.cpp
template<class T>
class Fraction {
private:
    static T gcd(T a, T b) {
        if (b == 0)return a;
        return gcd(b, a % b);
    }

    static T lcm(T a, T b) {
        return a * b / gcd(a, b);
    }

    static T binexp(T x, T n) {
        if (n == 0) return 1;
        T u = binexp(x, n / 2);
        u *= u;
        if (n % 2 == 1) u = (u * x);
        return u;
    }

public:
    T num, den;

    Fraction(T a, T b) {
        if (b <= 0)throw new std::exception();
        T ngcd = gcd(a, b);
        num = a / ngcd, den = b / ngcd;
    }

    void operator=(Fraction other) {
        num = other.num;
        den = other.den;
    }

    Fraction operator+(Fraction other) {
        T nden = lcm(den, other.den);
        T nnum = (nden / den) * num + (nden / other.den) * other.num;
        T ngcd = gcd(nden, nnum);
        return Fraction(nnum / ngcd, nden / ngcd);
    }

    Fraction operator-(Fraction other) {
        T nden = lcm(den, other.den);
        T nnum = (nden / den) * num - (nden / other.den) * other.num;
        T ngcd = gcd(nden, nnum);
        return Fraction(nnum / ngcd, nden / ngcd);
    }

    Fraction operator*(Fraction other) {
        T nnum = num * other.num;
        T nden = den * other.den;
        T ngcd = gcd(nden, nnum);
        return Fraction(nnum / ngcd, nden / ngcd);
    }

    Fraction operator/(Fraction other) {
        T nnum = num * other.den;
        T nden = den * other.num;
        T ngcd = gcd(nden, nnum);
        return Fraction(nnum / ngcd, nden / ngcd);
    }

    static Fraction pow(Fraction f, T n) {
        T expnum = binexp(f.num, n);
        T expden = binexp(f.den, n);
        if (n < 0) {
            return Fraction(expden, expnum);
        }
        return Fraction(expnum, expden);

    }

    Fraction pow(T n) {
        return pow(*this, n);
    }
};


// Li-Chao Tree. Convex hull trick is in kactl, named "LineContainer". It has lines of the form kx + m
// https://cp-algorithms.com/geometry/convex_hull_trick.html
struct LiChao {
    typedef int ftype;
    typedef pair<int, int> params;
    int maxn;

    vector<params> best_params;

    LiChao(int maxN) {
        maxn = maxN;
        best_params = vector<params>(maxn * 4);
    }

    // The function you add to the tree. It is a family of functions
    // parameterized by a
    // Any two functions f(a, -), f(b, -) must intersect at most once,
    // else the tree will not work.
    ftype f(params a, ftype x) {
        return a.first * x + a.second;
    }

    // Add the function parameterized by nw to the tree
    void add_fn(params nw, int v, int l, int r) {
        int m = (l + r) / 2;
        bool lef = f(nw, l) < f(best_params[v], l);
        bool mid = f(nw, m) < f(best_params[v], m);
        if (mid) {
            swap(best_params[v], nw);
        }
        if (r - l == 1) {
            return;
        } else if (lef != mid) {
            add_fn(nw, 2 * v, l, m);
        } else {
            add_fn(nw, 2 * v + 1, m, r);
        }
    }

    void add_fn(params nw) {
        return add_fn(nw, 1, 0, maxn);
    }

    // Compute the maximum valued function over all x
    int get(int x, int v, int l, int r) {
        int m = (l + r) / 2;
        if (r - l == 1) {
            return f(best_params[v], x);
        } else if (x < m) {
            return min(f(best_params[v], x), get(x, 2 * v, l, m));
        } else {
            return min(f(best_params[v], x), get(x, 2 * v + 1, m, r));
        }
    }

    int get(int x) {
        return get(x, 1, 0, maxn);
    }
};


vector<ll> precomputeInvMod(int n, ll mod) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    return inv;
}


struct Query {
    int l, r, idx;
    int64_t ord;

    inline void calcOrder() {
        ord = hilbertOrder(l, r, 21, 0);
    }
};

inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

// https://codeforces.com/blog/entry/61203
inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
    ) : (
                      (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = nt64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

ll modPow(ll base, ll pow, ll mod) {
    if (pow == 0) {
        return 1;
    } else {
        ll half = modPow(base, pow / 2, mod) % mod;
        ll whole = (half * half) % mod;
        if (pow % 2 == 1) {
            whole = (whole * base) % mod;
        }
        return whole;
    }
}

ll inv_mod(ll v, ll mod) {
    ll inv = (modPow(v, mod - 2, mod)) % mod;
    assert((inv * v) % mod == 1);
    return inv;
}

