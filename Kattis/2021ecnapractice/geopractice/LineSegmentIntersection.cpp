// https://open.kattis.com/problems/segmentintersection
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x−axis in interval [−pi , pi ]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); } // makes dist ()=1
  P perp() const { return P(-y, x); }       // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated ’a’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};
double eps = 1e-7;
template <class P> bool onSegment(P s, P e, P p) {
  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= eps;
}
template <class P> vector<P> segInter(P a, P b, P c, P d) {
  auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c),
       od = a.cross(b, d);
  // Checks if intersection is single non−endpoint point.
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
  set<P> s;
  if (onSegment(c, d, a))
    s.insert(a);
  if (onSegment(c, d, b))
    s.insert(b);
  if (onSegment(a, b, c))
    s.insert(c);
  if (onSegment(a, b, d))
    s.insert(d);
  return {all(s)};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    Point<double> s1, e1, s2, e2;
    cin >> s1.x >> s1.y >> e1.x >> e1.y >> s2.x >> s2.y >> e2.x >> e2.y;
    auto o = segInter(s1, e1, s2, e2);
    // avoid negative 0
    for(int j = 0; j < sz(o); j++) {
      o[j].x = abs(o[j].x) < .005 ? 0 : o[j].x;
      o[j].y = abs(o[j].y) < .005 ? 0 : o[j].y;
    }
    if (sz(o) == 0) {
      printf("none\n");
    } else if (sz(o) == 1) {
      printf("%.2f %.2f\n", o[0].x, o[0].y);
    } else {
      if (o[1] < o[0]) {
        swap(o[0], o[1]);
      }
      printf("%.2f %.2f %.2f %.2f\n", o[0].x, o[0].y, o[1].x, o[1].y);
    }
  }
  return 0;
}