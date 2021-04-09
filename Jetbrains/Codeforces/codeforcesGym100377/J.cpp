# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct Rect {
    int w;
    int h;
};


ll dot(pii a, pii b) {
    return a.first * b.first + a.second * b.second;
}

bool turnRight(pii x, pii y, pii z) {
    pii a = {y.first - x.first, y.second - x.second};
    pii b = {z.first - y.first, z.second - y.second};
    return a.first * b.second - a.second * b.first < 0;
}

ll queryCHT(deque<pii> &points, ll x) {
    // minimize (x, 1) dot (points.first, points.second)
    ll front = dot({x, 1}, points[0]);
    while (points.size() > 1) {
        ll next = dot({x, 1}, points[1]);
        if (front >= next) {
            points.pop_front();
        } else {
            return front;
        }
        front = next;
    }
    return front;
}


// points must be convex
void insertCHT(deque<pii> &points, pii insert) {
    while (points.size() >= 2) {
        if (turnRight(points[points.size()-2], points.back(), insert)) {
            break;
        }
        points.pop_back();
    }
    points.push_back(insert);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Rect> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].w;
        cin >> a[i].h;
    }
    sort(a.begin(), a.end(), [](Rect a, Rect b) {
        return a.h == b.h ? a.w > b.w : a.h > b.h;
    });
    vector<Rect> r;
    r.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i].w >= r[r.size() - 1].w) {
            r.push_back(a[i]);
        }
    }

    vector<ll> dp(r.size() + 1);
    dp[0] = 0;
    deque<pii> points;
    for (int i = 1; i < dp.size(); i++) {
        // dp[i] = max_k(dp[k] + w[i]*h[k]);
        insertCHT(points, {r[i - 1].h, dp[i - 1]});
        dp[i] = queryCHT(points, r[i - 1].w);
    }
    cout << dp[dp.size() - 1] << "\n";
    return 0;
}