#include <bits/stdc++.h>
#include <optional>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T>
class Fraction {
 private:
  static T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  static T lcm(T a, T b) { return a * b / gcd(a, b); }

  static T binexp(T x, T n) {
    if (n == 0) return 1;
    T u = binexp(x, n / 2);
    u *= u;
    if (n % 2 == 1) u = (u * x);
    return u;
  }

 public:
  T num, den;

  Fraction(T a, T b) {
    if (b <= 0) throw new std::exception();
    T ngcd = gcd(a, b);
    num = a / ngcd, den = b / ngcd;
  }

  bool operator==(Fraction other) {
    num = other.num;
    den = other.den;
    return num == other.num && den == other.den
  }

  bool operator<(Fraction other) {
    Fraction diff = other - this;
    return (diff.num > 0) ^ (diff.den > 0)
  }

  bool operator<=(Fraction other) {
    return this < other || this == other;
  }

  Fraction operator+(Fraction other) {
    T nden = lcm(den, other.den);
    T nnum = (nden / den) * num + (nden / other.den) * other.num;
    T ngcd = gcd(nden, nnum);
    return Fraction(nnum / ngcd, nden / ngcd);
  }

  Fraction operator-(Fraction other) {
    T nden = lcm(den, other.den);
    T nnum = (nden / den) * num - (nden / other.den) * other.num;
    T ngcd = gcd(nden, nnum);
    return Fraction(nnum / ngcd, nden / ngcd);
  }

  Fraction operator*(Fraction other) {
    T nnum = num * other.num;
    T nden = den * other.den;
    T ngcd = gcd(nden, nnum);
    return Fraction(nnum / ngcd, nden / ngcd);
  }

  Fraction operator/(Fraction other) {
    T nnum = num * other.den;
    T nden = den * other.num;
    T ngcd = gcd(nden, nnum);
    return Fraction(nnum / ngcd, nden / ngcd);
  }

  static Fraction pow(Fraction f, T n) {
    T expnum = binexp(f.num, n);
    T expden = binexp(f.den, n);
    if (n < 0) {
      return Fraction(expden, expnum);
    }
    return Fraction(expnum, expden);
  }

  Fraction pow(T n) { return pow(*this, n); }
};

template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
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
  P unit() const { return *this / dist(); }  // makes dist ()=1
  P perp() const { return P(-y, x); }        // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated ’a’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};
typedef Fraction<ll> F;
typedef Point<F> P;
struct HalfPlane {
  F A;
  F B;
  F C;
  // Ax + By <= C or
  // Ax + By >= C
  bool leq;
  HalfPlane(F A=F(0,1), F B=F(0,1), F C=F(0,1), bool leq=false): A(A), B(B), C(C), leq(leq) {};
  HalfPlane(int A, int B, int C, bool leq): leq(leq) {
    this->A = F(A, 1);
    this->B = F(B, 1);
    this->C = F(C, 1);
  }
};
vector<P> convexHull(vector<P>& pts) {
  if (sz(pts) <= 1) return pts;
  sort(all(pts));
  vector<P> h(sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (P p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= F(0,1)) t--;
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

pair<HalfPlane, bool> point_pair_to_line(P& p1, P& p2) {
  if(p1 == p2) {
    return {HalfPlane(), false};
  }
  F A = p1.y - p2.y;
  F B = p1.x - p2.x;
  F C = A * p1.x + B * p1.y;
  assert(C == A * p2.x + B * p2.y);
  return {HalfPlane{A,B,C,false}, true};
}

pair<P, bool> line_line_intersection(HalfPlane& l1, HalfPlane& l2){
    F denom = l1.A * l2.B - l2.A * l1.B;
    if (!(denom == F(0, 1))) {
      return {P(F(0,1),F(0,1)), false};
    }
    F intX = l1.C * l2.B - l2.C * l1.B / denom;
    F intY = l1.A * l2.C - l2.A * l1.C / denom;
    return {P(intX, intY), true};
}

vector<P> regionToPolygon(int A, int B, int C, int D, int X, int Y) {
  vector<HalfPlane> lines = {
      HalfPlane(1, 0, 0, false), HalfPlane(0, 1, 0, false),
      HalfPlane(1, 0, X, true),  HalfPlane(0, 1, Y, true),
      HalfPlane(A, B, C, false), HalfPlane(A, B, D, true)};
  vector<P> intersection_points;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = i + 1; j < lines.size(); j++) {
      auto intP = line_line_intersection(lines[i], lines[j]);
      if(intP.second) {
        intersection_points.push_back(intP.first);
      }
    }
  }
  vector<P> valid_int_points;
  for (int i = 0; i < intersection_points.size(); i++) {
    P p = intersection_points[i];
    bool valid = true;
    for (int i = 0; i < lines.size(); i++) {
      F val = lines[i].A * p.x + lines[i].B * p.y;
      F c = lines[i].C;
      bool point_line_ok = false;
      if (val == c) {
        point_line_ok = true;
      }
      if (lines[i].leq ^ (val < c)) {
        point_line_ok = true;
      }
      if (!point_line_ok) {
        valid = false;
      }
    }
    if (valid) {
      valid_int_points.push_back(p);
    }
  }
  return convexHull(valid_int_points);
}

inline bool isBetween(P& p1, P& p2, P& test) {
    // Check that the point test on the line p1p2 
    // is on the line segment p1p2
    return F(0, 1) <= (p1 - test).dot(test - p2);
}

vector<P> merge_polygon(vector<P> poly1, vector<P> poly2) {
  vector<HalfPlane> edges1;
  vector<HalfPlane> edges2;
  for(int i = 0; i < poly1.size(); i++){
    auto intersection_p = point_pair_to_line(poly1[i], poly1[(i + 1) % poly1.size()]);
    assert(intersection_p.second);
    edges1.push_back(intersection_p.first);
  }
  for(int i = 0; i < poly2.size(); i++){
    auto intersection_p = point_pair_to_line(poly2[i], poly2[(i + 1) % poly2.size()]);
    assert(intersection_p.second);
    edges2.push_back(intersection_p.first);
  }
  vector<vi> G(poly1.size());
  bool had_intersection = false;
  rep(i, 0, sz(poly1)) {
    rep(j, 0, sz(poly2)) {
      auto intersection_p = line_line_intersection(edges1[i], edges2[j]);
      if (intersection_p.second) {
        if(isBetween(poly1[i], poly1[(i + 1) % poly1.size()], intersection_p.first)) {
          if(isBetween(poly2[i], poly2[(i + 1) % poly2.size()], intersection_p.first)) {
            G[i].push_back(j);
            G[j].push_back(i);
          }
        }
      }
    }
  }
  if(!had_intersection) {
    // check if poly1 in poly2

    // BAD: Might have to take the union of disjoint polygons...
  }



}

void test() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  string ans;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    // Read Input
    int n;
    cin >> n;
    // Replace each star region with a polygon

    // Merge the polygons in exponential fashion

    // Merge two polygons

    // Compute area with the shoelace formula

    // If area is 1, then there is no point inside.
  }

  return 0;
}