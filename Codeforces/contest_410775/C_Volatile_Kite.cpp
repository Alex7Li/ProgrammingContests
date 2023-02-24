#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<double, double> Point;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

double dist(Point p1, Point p2) {
  return hypot(p1.first - p2.first, p1.second - p2.second); 
}

double cross(Point p1, Point p2){
  return p1.first * p2.second - p1.second * p2.first;
}
Point operator-(Point p1, Point p2){
  return {p1.first - p2.first, p1.second - p2.second};
}

Point operator/(Point p1, double d){
  return {p1.first / d, p1.second / d};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vd x(n);
    vd y(n);
    double min_d = 9e9;
    rep(i, 0, n){
      cin >> x[i] >> y[i];
    }
    vector<Point> points(n + 2);
    rep(i, 0, n){
      points[i] = {x[i], y[i]};
      rep(j, 0, i){
        min_d = min(min_d, dist(points[i], points[j]) / 2);
      }
    }
    points[n] = {x[0], y[0]};
    points[n + 1] = {x[1], y[1]};
    rep(i, 0, n){
      Point a = points[i];
      Point b = points[i+1];
      Point c = points[i+2];
      double hdist = abs(cross(b - a, c - a)) / (dist(a, c) * 2);
      min_d = min(min_d, hdist);
    }
    cout << std::setprecision(33);
    cout << min_d;
    return 0;
    
}