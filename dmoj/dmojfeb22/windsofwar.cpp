#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
  #pragma GCC optimize("trapv") // signed overflow => RE
#else
  #pragma GCC target("arch=skylake") // CF only
#endif
struct Point {
  ll x;
  ll y;
  int type;
  bool operator<(Point& o) {
    return atan2l(y, x) > atan2l(o.y, o.x);
  }
  ll cross(Point o) {
    return x * o.y - o.x * y;
  }
  Point operator-(Point& o) {
    return {x - o.x, y - o.y, 0};
  }
};

bool turn_right(Point& a, Point& b, Point& c) {
  ll x = (b - a).cross(c - b);
  return x < 0;
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int p, t;
  cin >> p >> t;
  vector<Point> points(p + t); 
  rep(i, 0, p) {
    cin >> points[i].x  >> points[i].y;
    points[i].type = 1;
  }
  rep(i, p, p + t) {
    cin >> points[i].x  >> points[i].y;
    points[i].type = -1;
  }
  sort(points.begin(), points.end());
  int n = p + t;
  vector<vi> ans(n, vi(n));
  rep(e, 0, n) {
    ans[e][e] = points[e].type;
    rep(mid, 0, e) {
      ans[mid][e] = points[mid].type; // connect to mid from origin
      rep(st, 0, mid) {
        if (turn_right(points[st], points[mid], points[e])) {
          ans[mid][e] = max(ans[mid][e], ans[st][mid]);
        }
      }
      // add stuff between mid and e
      rep(x, mid + 1, e) {
        if (turn_right(points[e], points[x], points[mid])) {
          ans[mid][e] += points[x].type;
        }
      }
      ans[mid][e] += points[e].type;
    }
  }
  int best = 0;
  rep(i, 0, n){
    rep(j, 0, n) {
      best = max(best, ans[i][j]);
    }
  }
  cout << best << "\n";
  return 0;
}
