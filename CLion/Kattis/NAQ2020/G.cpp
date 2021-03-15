# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Point {
    long double x, y;
};

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    long double val = (q.y - p.y) * (r.x - q.x) -
                 (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

vector<Point> convexHull(vector<Point> points) {
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for (int i = 2; i < points.size(); i++) {
        Point start = hull[hull.size() - 2];
        Point mid = hull[hull.size() - 1];
        Point end = points[i];
        while (hull.size() > 1 && orientation(start, mid, end) == 2) {
            hull.pop_back();
            if(hull.size() > 1) {
                start = hull[hull.size() - 2];
                mid = hull[hull.size() - 1];
            }
        }
        hull.push_back(end);
    }
    return hull;
}
// BEGIN

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double k;
    cin >> n >> k;
    vector<double> h(n + 2, 0.0);
    vector<Point> points;
    points.push_back(Point({0.0, 0.0}));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        stringstream ss(s);
        double proc = 0;
        ss >> proc;
        proc -= k * i * (n + 1 - i);
        points.push_back({i + 0.0, proc});
    }
    points.push_back(Point({n + 1.0, 0.0}));
    vector<Point> hull = convexHull(points);

    int lo = 0;
    int hi = 0;
    rep(i, 1, n + 1) {
        if (hull[hi].x < i) {
            hi++;
        }
        if (hull[lo + 1].x <= i) {
            lo++;
        }
        if (lo == hi) {
            h[i] = hull[lo].y;
            continue;
        }
        Point p1 = hull[lo];
        Point p2 = hull[hi];
        double fi = (i - p2.x) / (p1.x - p2.x);
        double se = (p1.x - i) / (p1.x - p2.x);
        h[i] = p1.y * fi + p2.y * se;
    }
    rep(i, 1, n + 1) {
        h[i] += k * i * (n + 1 - i);
    }
    double maxh = 0.0;
    rep(i, 0, n + 2) {
        maxh = max(maxh, h[i]);
    }
    printf("%lf\n", maxh);
//    cout << std::format("{:f}" , maxh) << endl;
    return 0;
}