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
#define PI 3.14159265358979323846
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<double, double> Point;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

double cross(Point p1, Point p2){
  return p1.first * p2.second - p1.second * p2.first;
}

Point operator-(Point p1, Point p2){
  return {p1.first - p2.first, p1.second - p2.second};
}

double angle(Point p1, Point p2) {
  return atan2(p2.second - p1.second, p2.first - p1.first);
}

double mod2pi(double angle) {
    while(angle < 0){
      angle += 2 * PI;
    }
    while(angle >= 2 * PI){ 
      angle -= 2 * PI;
    }
    return angle;
}

double get_offset(vector<double> angles) {
  // find theta to rotate angles to be between [0, pi]
  // after applying angles = (angles - theta) % 2pi
  // assuming they are cyclic between [-pi, pi]
  // and that it is possible.
  sort(angles.begin(), angles.end());
  int n = angles.size();
  rep(i, 0, n) {
    double beginAngle = angles[i];
    double nextAngle = angles[(i + 1) % n];
    double diff = nextAngle - beginAngle;
    if(mod2pi(diff) > PI) {
      return nextAngle;
    }
  }
  assert(false);
  return INFINITY;
}

pair<int, int> maxmin_angles(vector<Point>& p,
    vector<bool>& seen, Point start) {
    vector<double> angles;
    vector<int> angle_inds;
    rep(i, 0, p.size()){
      if(!seen[i]) {
        double pangle = angle(start, p[i]);
        angles.push_back(pangle);
        angle_inds.push_back(i);
      }
    }
    double offset = get_offset(angles);
    rep(i, 0, angles.size()) {
      angles[i] = mod2pi(angles[i] - offset);
    }
    auto inds = minmax_element(angles.begin(), angles.end());
    int minInd = angle_inds[inds.first - angles.begin()];
    int maxInd = angle_inds[inds.second - angles.begin()];
    return {minInd, maxInd};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> p(n);
    vector<bool> seen(n);
    int startInd = 0;
    rep(i, 0, n){
      cin >> p[i].first >> p[i].second;
      if(p[i] > p[startInd]) {
        startInd = i;
      }
    }
    string order;
    cin >> order;
    vi out_order;
    out_order.push_back(startInd);
    seen[startInd] = true;
    rep(i, 0, len(order)) {
      int nextInd = 0;
      pii minmax = maxmin_angles(p, seen, p[startInd]);
      if(order[i] == 'L') {
        nextInd = minmax.first;
      } else {
        nextInd = minmax.second;
      }
      out_order.push_back(nextInd);
      seen[nextInd] = true;
      startInd = nextInd;
    }
    for(int i = 0; i < seen.size(); i++){
      if(not seen[i]){
        out_order.push_back(i);
        seen[i] = true;
      }
    }
    for(int i = 0; i < out_order.size() - 2; i++) {
      bool right = cross(p[i + 1] - p[i], p[i + 2] - p[i]);
      assert(right != (out_order[i] == 'R'));
    }
    cout << (out_order[0] + 1);
    for(int i = 1; i < out_order.size(); i++){
      cout << " " << (out_order[i] + 1);
    }
    cout << endl;
    return 0;
}
