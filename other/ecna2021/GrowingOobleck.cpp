#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n';
#define _ << " _ " <<
#define epsilon 1e-8
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Circle {
  double x, y, r, s;
};

double euc_dist(Circle& c1, Circle& c2) {
  return hypot(c1.x - c2.x, c1.y - c2.y);
}

vector<int> grow_till_oblection(vector<Circle>& circles) {
  double min_time = 2e30;
  pii best = {-1, -1};
  for (int i = 0; i < circles.size(); i++) {
    for (int j = i + 1; j < circles.size(); j++) {
      double dist = euc_dist(circles[i], circles[j]);
      double timeLeft = (dist - circles[i].r - circles[j].r) / (circles[i].s + circles[j].s);
      if (timeLeft < min_time) {
        min_time = timeLeft;
        best = {i, j};
      }
    }
  }
  for (int i = 0; i < circles.size(); i++) {
    circles[i].r += circles[i].s * min_time;
  }
  vector<int> the_pair = {best.first, best.second};
  return the_pair;
}

Circle merge_all_circles(vector<Circle>& toMerge) {
  double x = 0;
  double y = 0;
  double r = 0;
  double s = 0;
  for (Circle c : toMerge) {
    x += c.x;
    y += c.y;
    r += c.r * c.r;
    s = max(s, c.s);
  }
  double n = toMerge.size();
  return Circle{x / n, y / n, sqrt(r), s};
}
vector<Circle> merge_oblection(vector<Circle>& circles,
                               vector<int>& ooblecting) {
  vector<Circle> new_circles;
  vector<Circle> merge_circles;
  sort(ooblecting.begin(), ooblecting.end());
  int oobind = 0;
  for (int i = 0; i < circles.size(); i++) {
    if (oobind < ooblecting.size() && i == ooblecting[oobind]) {
      oobind++;
      merge_circles.push_back(circles[i]);
    } else {
      new_circles.push_back(circles[i]);
    }
  }
  Circle new_circle = merge_all_circles(merge_circles);
  new_circles.push_back(new_circle);
  return new_circles;
}

vector<int> touching(vector<Circle>& circles, Circle& base) {
  vector<int> ans;
  for (int i = 0; i < circles.size(); i++) {
    if (euc_dist(circles[i], base) < circles[i].r + base.r - epsilon) {
      ans.push_back(i);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Circle> circles;
  for (int i = 0; i < n; i++) {
    Circle c;
    cin >> c.x >> c.y >> c.r >> c.s;
    circles.push_back(c);
  }
  while (circles.size() > 1) {
    vector<int> ooblecting = grow_till_oblection(circles);
    while (ooblecting.size() > 1) {
      circles = merge_oblection(circles, ooblecting);
      ooblecting = touching(circles, circles[circles.size()-1]);
    }
  }
  printf("%.9f %.9f\n%.9f", circles[0].x, circles[0].y, circles[0].r);
  return 0;
}