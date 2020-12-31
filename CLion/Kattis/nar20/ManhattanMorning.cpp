# include <bits/stdc++.h>

using namespace std;

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MIN;

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
};

struct Loc {
    int x;
    int y;

    // Overloaded for ordered map. If !(x<y), !(y<x), then
    //  x will be considered equal to y.
    bool operator<(const Loc &o) const {
        return x == o.x ? y < o.y : x < o.x;
    }
};

vector<Loc> get_points() {
    int n;
    cin >> n;
    int xh, yh, xw, yw;
    cin >> xh >> yh >> xw >> yw;
    vector<Loc> points;
    int minx = min(xh, xw);
    int miny = min(yh, yw);
    xh -= minx;
    xw -= minx;
    yh -= miny;
    yw -= miny;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x -= minx;
        y -= miny;
        if ((x > xh && x > xw) || (x < xh && x < xw)) {
            continue;
        }
        if ((y > yh && y > yw) || (y < yh && y < yw)) {
            continue;
        }
        points.push_back(Loc{x, y});
    }
    if (yh > yw) {
        int temp = yh;
        yh = yw;
        yw = temp;
        for (int i = 0; i < points.size(); i++) {
            points[i].y = yw - points[i].y;
        }
    }
    if (xh > xw) {
        int temp = xh;
        xh = xw;
        xw = temp;
        for (int i = 0; i < points.size(); i++) {
            points[i].x = xw - points[i].x;
        }
    }
    set<int> yS;
    for(int i = 0; i < points.size(); i++) {
        yS.insert(points[i].y);
    }
    map<int,int> yM;
    int ind = 0;
    for(int yVal: yS){
        yM[yVal] = ind++;
    }
    for(int i = 0; i < points.size(); i++) {
        points[i].y = yM[points[i].y];
    }
    sort(points.begin(), points.end());
    return points;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Loc> points = get_points();
    int maxY = 0;
    for(int i = 0; i < points.size(); i++){
        maxY = max(maxY, points[i].y);
    }
    Tree maxT = Tree(maxY + 2);
    maxT.update(0, 0);
    for (int i = 0; i < points.size(); i++) {
//        cout << points[i].x << " " << points[i].y << "\n";
        int best = maxT.query(0, points[i].y + 1);
        maxT.update(points[i].y, best + 1);
    }
    int ans = maxT.query(0, maxY + 1);
    cout << ans << "\n";
    return 0;
}