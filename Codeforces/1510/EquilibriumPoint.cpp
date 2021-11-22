# include <bits/stdc++.h>
// The limit is 36 and we get 34 with no problem but
// 36 is MLE and TLE, oof.
// I followed the editorial too.
//https://codeforces.com/problemset/problem/1510/E
using namespace std;

struct COM {
    int x; // x * mass
    int y; // y * mass * 6
    int mass;

    // Must be overloaded for unordered map
    bool operator==(const COM &other) const {
        return x == other.x && y == other.y && mass == other.mass;
    }
};

#include <ext/pb_ds/assoc_container.hpp>

using ui64 = uint64_t;

struct chash {
    ui64 operator()(const COM &l) const {
        return (l.x << 10) ^ ((l.y) << 5) ^ l.mass;
    }
};

// to string function, required for the hash map from gnu_pbds
ostream &operator<<(ostream &stream, const COM &c) {
    return stream << c.x << " " << c.y << " " << c.mass;
}

template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v, chash>;

inline COM merge(const COM &a, const COM &o) {
    return {a.x + o.x, a.y + o.y, a.mass + o.mass};
}

double dist(double x1, double y1, double x2, double y2) {
    return hypot(x1 - x2, y1 - y2);
}

inline COM makeCOM(int x, int yTimes6, int mass) {
    return COM{x * mass, yTimes6 * mass, mass};
}

inline COM shiftCOM(const COM &c, int dx, int dy) {
    return COM{c.x + dx * c.mass, c.y + dy * c.mass * 6, c.mass};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double x, y;
    cin >> n >> x >> y;
    n /= 2;

    vector<hash_map<COM, string>> cm(n + 1);
    cm[0][makeCOM(0, 0, 0)] = "";
    cm[1][makeCOM(1, 2, 1)] = "()";
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int offset = (j + 1) * 2;
            for (const auto &p1: cm[j]) {
                COM base_triangles = makeCOM(j + 1, 2, 1);
                COM base_rect = makeCOM(j + 1, 3, j << 1);
                COM base = merge(base_rect, base_triangles);
                COM p1Shift = shiftCOM(p1.first, 1, 1);
                COM merge1 = merge(p1Shift, base);
                for (const auto &p2: cm[i - j - 1]) {
                    const COM nm = {p2.first.x + merge1.x + offset * p2.first.mass, p2.first.y + merge1.y,
                                    p2.first.mass + merge1.mass};
                    if (cm[i].find(nm) == cm[i].end()) {
                        string newStr = '(' + p1.second + ')' + p2.second;
                        cm[i][nm] = newStr;
                    }
                }
            }
        }
    }

    auto best = min_element(cm[n].begin(), cm[n].end(), [x, y](auto v, auto w) {
        double x1 = (double) (v.first.x) / v.first.mass;
        double y1 = (double) (v.first.y) / (v.first.mass * 6.0);
        double x2 = (double) (w.first.x) / w.first.mass;
        double y2 = (double) (w.first.y) / (w.first.mass * 6.0);
        return dist(x, y, x1, y1) <
               dist(x, y, x2, y2);
    });
//    cerr << best->second.x / (0.0 + best->second.mass) << " " << best->second.y / (6.0 * best->second.mass);
    cout << best->second << endl;
    return 0;
}