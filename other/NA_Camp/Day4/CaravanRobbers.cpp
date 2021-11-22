# include <bits/stdc++.h>

using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Frac {
    ll p, q;
};

template<class F>
Frac fracBS(F f, ll N) {
    bool dir = 1, A = 1, B = 1;
    Frac lo{0, 1}, hi{1, 1}; // Set hi to 1/0 to search (0, N]
    if (f(lo)) return lo;
    assert(f(hi));
    while (A || B) {
        ll adv = 0, step = 1; // move hi if dir, else lo
        for (int si = 0; step; (step *= 2) >>= si) {
            adv += step;
            Frac mid{lo.p * adv + hi.p, lo.q * adv + hi.q};
            if (abs(mid.p) > N || mid.q > N || dir == !f(mid)) {
                adv -= step;
                si = 2;
            }
        }
        hi.p += lo.p * adv;
        hi.q += lo.q * adv;
        dir = !dir;
        swap(lo, hi);
        A = B;
        B = !!adv;
    }
    return dir ? hi : lo;
}

int offset = 0;
vector<pii> ranges;

bool broke(Frac f) {
    long double v = (long double) (f.p) / f.q + 1e-13 + offset;
    long double curEnd = 0;
    for (auto &range : ranges) {
        if (curEnd < range.first) {
            curEnd = range.first;
        }
        curEnd += v;
        if (curEnd > range.second) {
            return true;
        }
    }
    return false;
}

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ranges = vector<pii>(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    sort(all(ranges));
    int lo = 0;
    for (ll j = 1LL << (ll) (log2(1000000)); j != 0; j >>= 1) {
        if (!broke({lo + j, 1})) {
            lo += j;
        }
    }
    offset = lo;
    Frac ans = fracBS(broke, n);
    ans.p += (ans.q * offset);
    ll g = gcd(ans.p, ans.q);
    cout << ans.p/g << "/" << ans.q/g << endl;
    return 0;
}