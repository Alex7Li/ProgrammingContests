# include <bits/stdc++.h>

using namespace std;
typedef long long ll;

static const ll inf = LLONG_MAX;

/*
struct Line{
    ll m;
    ll b;
};

struct LineContainer {
    deque<Line> lines;
    // Add a line. Lines should be added such that slopes
    // are decreasing.
    void add(Line l){
        lines.push_back(l);
    }

    // Query a point to give a maximum value. Queries should
    // be added so that points are decreasing. Lines with slope
    // higher than 2*x will not be considered.
    ll query(ll x) {
        while(lines.)
    }
};*/

struct Line {
    mutable ll k, b, p;

    bool operator<(const Line &o) const { return k < o.k; }

    bool operator<(ll x) const {
        return p < x;
    }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles , use inf = 1/.0, div(a,b) = a/b)

    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->b > y->b ? inf : -inf;
        else x->p = div(y->b - x->b, x->k - y->k);
        return x->p >= y->p;
    }

    deque<Line> toAdd;
    ll lastK = inf;
    void add(ll k, ll b) {
        assert(k <= lastK);
        lastK = k;
        toAdd.push_back({k, b, 0});
    }

    void realAdd(Line l) {
        auto z = insert(l), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    ll lastX = inf;
    ll query(ll x) {
        assert(x <= lastX);
        lastX = x;
        while (!toAdd.empty() && x * 2 <= toAdd.back().k) {
            realAdd(toAdd.back());
            toAdd.pop_back();
        }
        auto l = lower_bound(x);
        if(l==end()){
            return inf;
        }
        assert(x * 2 <= l->k);
        return l->k * x + l->b;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    priority_queue<tuple<ll, ll, ll, ll, bool>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, s, e;
        cin >> a >> b >> s >> e;
        a--;
        b--;
        edges.push({e, s, a, b, true});
    }
    vector<LineContainer> hulls(n);
    ll ans = inf;
    // TODO: Sort events so that,
    // the departure time queries are decreasing.
    // Then, update the LineContainer to remove old lines.
    while (!edges.empty()) {
        auto edge = edges.top();
        edges.pop();
        int a = get<2>(edge);
        int b = get<3>(edge);
        if (get<4>(edge)) {// just process the arrival.
            // get cost of arrival after taking this flight (negated)
            ll arrive_time = get<0>(edge);
            ll c;
            if (b == n - 1) {
                c = 0;
            } else {
                c = hulls[b].query(arrive_time);
                if (c == inf) {
                    continue;
                }
                // cerr << c << " " << arrive_time << "\n";
                c = -c + arrive_time * arrive_time;
            }
            assert(c >= 0);
            ll depart_time = get<1>(edge);
            edges.push({depart_time, c, a, b, false});
            //cerr << depart_time << " DEPART " << a << " " << b << " " << c << endl;
        } else {
            ll depart_time = get<0>(edge);
            ll cost = get<1>(edge) + depart_time * depart_time;
            if (a == 0) {
                ans = min(ans, cost);
            }
            //cerr << arrival_time << " ARRIVE " << a << " " << b << " " << cost << endl;
            // process the departure.
            hulls[a].add(2 * depart_time, -cost);
        }
    }
    cout << ans << endl;
    return 0;
}