# include <bits/stdc++.h>
// https://codeforces.com/contest/1500/problem/B
// This is some pretty funny shit. I started with SegTree2 but then moved to SegTree after MLE.
// Since that got TLE, now I'm trying to just use arrays to make it fast
// Great; it was WA.
// I basically need to restart it and use CRT; I think changing the datastructures has
// broken the solution quite a bit. But I can't bring myself to destroy the funny code.
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef vector<int> vi;


// I didn't read the (bolded) word different that occurs (twice) in the problem statement, so my solution is
// extra general.
// It gets MLE with this segtree, though, my calculations say it should be barely over:
// (n trees, each with at most 20 active nodes, each node is of size 20 bytes)
// gives a total of n*20*20 = 5*10^5*20*20 = 4*10^8 bytes, we are allowed 256MB = 2.5*10^8 bytes)
struct SegTree2 {
    SegTree2 *l = nullptr, *r = nullptr;
    int lo, hi, sum;

    // Convenient map functions like [] require the ability to create
    // a default constructor.
    SegTree2() : lo(0), hi(0), sum(0) {};

    SegTree2(int lo, int hi) : lo(lo), hi(hi), sum(0) {}

    void place(int x) {
        if (x < lo || hi <= x) {
            return;
        }
        sum++;
        int mid = (lo + hi) / 2;
        if (hi - lo > 1) {
            if (x < mid && mid - lo > 0) {
                if (r == nullptr) {
                    r = new SegTree2(lo, mid);
                }
                r->place(x);
            } else if (x >= mid && hi - mid > 0) {
                if (l == nullptr) {
                    l = new SegTree2(mid, hi);
                }
                l->place(x);
            }
        }
    }

    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return sum;
        int ans = 0;
        if (l != nullptr) {
            ans += l->query(L, R);
        }
        if (r != nullptr) {
            ans += r->query(L, R);
        }
        return ans;
    }
};

// The stupidest segment tree which supports the following operations:
// 1) a 1 to the tree at a location (can only be used once)
// 2) sum an interval
// It gives TLE. Maybe because we have 6 layers of data structure to do a stupid task :P
struct SegTree {
    int val = -1;

    // Convenient map functions like [] require the ability to create
    // a default constructor.
    SegTree() {};

    SegTree(int lo, int hi) {};

    void place(int x) {
        val = x;
    }

    int query(int L, int R) {
        if (L <= val && val < R) {
            return 1;
        } else {
            return 0;
        }
    }
};

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

int sum_right(int pos, int l, int r) {
    if (l <= pos && pos < r) {
        return 1;
    } else {
        return 0;
    }
}

vi makeC(vi &a, vector<unordered_map<int, int>> &b) {
    int n = a.size();
    vi c(n);
    for (int i = 0; i < n; i++) {
        int j = i % b.size();
        c[i] = b[j][a[i]];
    }
    return c;
}

bool willBeMad(ll day, vi &c, ll k, ll step, ll count) {
    ll rageDays = 0;
    int n = c.size();
    ll effectiveDays = 1 + day / n;
    for (int i = 0; i < n; i++) {
        if (day % n == i) {
            effectiveDays--;
        }
        ll fullLoops = effectiveDays / step;
        ll missed = sum_right(c[i], 0, step) * fullLoops;

        ll extraDays = effectiveDays % step;
        ll stInd = (i / count) % step;
        ll endInd = extraDays + stInd;
        if (endInd <= step) {
            missed += sum_right(c[i], stInd, endInd);
        } else {
            missed += sum_right(c[i], stInd, step);
            missed += sum_right(c[i], 0, endInd % step);
        }
        rageDays += effectiveDays - missed;
    }
    return rageDays >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    ll count = gcd(n, m);
    ll step = m / count;
    vector<int> a(n);
    vector<set<int>> distinctColors(count);
    rep(i, 0, n) {
        cin >> a[i];
        distinctColors[i % count].insert(a[i]);
    }

    vector<unordered_map<int, int>> colors(count);
    rep(i, 0, count) {
        colors[i] = unordered_map<int, int>();
        for (int color: distinctColors[i]) {
            colors[i][color] = -1;
        }
    }
    rep(i, 0, m) {
        int x;
        cin >> x;
        if (colors[i % count].find(x) != colors[i % count].end()) {
            colors[i % count][x] = i / count;
        }
    }
    vi c = makeC(a, colors);
    ll high = 1LL << 62;
    ll low = k;
    while (low + 1 < high) {
        ll mid = (high + low) / 2;
        if (willBeMad(mid, c, k, step, count)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if (low + 1 == high) {
        if (!willBeMad(low, c, k, step, count)) {
            low = low + 1;
        }
    }
    cout << low << endl;
    return 0;
}