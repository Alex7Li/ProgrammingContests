# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

void setH(int v, vi &h, vector<vi> &edges) {
    trav(v1, edges[v]) {
        if (h[v1] != 0) {
            h[v] = h[v1] + 1;
        }
    }
    trav(v1, edges[v]) {
        if (h[v1] == 0) {
            setH(v1, h, edges);
        }
    }
}

bool left(pii a, pii b, pii c) {
    pii v = pii{b.first - a.first, b.second - a.second};
    pii w = pii{c.first - b.first, c.second - b.second};
    ll cross = v.first * w.second - v.second * w.first;
    return cross >= 0;
}

void addToHull(deque<pii> &hull, pii toAdd) {
    while (hull.size() > 1) {
        pii first = hull[hull.size() - 2];
        pii mid = hull[hull.size() - 1];
        if (left(first, mid, toAdd)) {
            hull.pop_back();
        } else {
            break;
        }
    }
    hull.push_back(toAdd);
}

ll dot(pii a, pii b) {
    return a.first * b.first + a.second * b.second;
}

ll CHT(deque<pii> &hull, pii query) {
    ll s = dot(hull[hull.size() - 1], query);
    ll sn = 0;
    if (hull.size() > 1) {
        sn = dot(hull[hull.size() - 2], query);
        if (sn < s) {
            return s;
        }
        hull.pop_back();
        s = sn;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<vi> edges(n);
        rep(i, 1, n) {
            int e;
            cin >> e;
            edges[i].push_back(e - 1);
            edges[e - 1].push_back(i);
        }
        rep(i, 1, n) {
            cin >> a[i];
        }
        vi h(n, 0);
        h[0] = 1;
        setH(0, h, edges);

        vector<int> idx(a.size());
        iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(),
                    [&h, &a](int i1, int i2) { return h[i1] == h[i2] ? a[i1] > a[i2] : h[i1] > h[i2]; });
        ll maxLayer;
        ll minLayer;
        ll maxLastLayer = 0;
        ll minLastLayer = 1000000001;
        ll h1;
        ll h2;
        ll h1Last = 0;
        ll h2Last = 1000000001;
        int curLayer = -1;
        vector<ll> best(n, 0);
        trav(i, idx) {
            if (curLayer != h[i]) {
                maxLastLayer = maxLayer;
                minLastLayer = minLayer;
                h1Last = h1;
                h2Last = h2;

                curLayer = h[i];
                maxLayer = 0;
                minLayer = 1000000001;
                h1 = -minLayer;
                h2 = -minLayer;
            }
            if (curLayer != h[idx[0]]) {
                trav(e, edges[i]) {
                    if (h[e] > h[i]) {
                        best[i] = max(best[i], best[e] - a[e] + maxLastLayer);
                        best[i] = max(best[i], best[e] + a[e] - minLastLayer);
                        best[i] = max(best[i], max(h1Last - a[e], h2Last + a[e]));
                    }
                }
//                cerr << i << " " << best[i] << endl;
            }
            h1 = max(best[i] + a[i], h1);
            h2 = max(best[i] - a[i], h2);
            maxLayer = max(a[i], maxLayer);
            minLayer = min(a[i], minLayer);
        }
        cout << best[0] << "\n";
    }
    return 0;
}