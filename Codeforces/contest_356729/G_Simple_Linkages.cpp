#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
double d(pdd p1, pdd p2) {
  return hypot(p1.first - p2.first, p1.second - p2.second);
}
pdd go_towards(pdd from, pdd to, double d){
  double dx = to.first - from.first;
  double dy = to.second - from.second;
  double norm = hypot(dx, dy);
  dx = d * dx / norm;
  dy = d * dy / norm;
  return {dx, dy};
}


pdd two_jumps(pdd dir, double j1_dist, double j2_dist) {
  double minAng = 0;
  double maxAng = 3.14159265359;
  double tD = hypot(dir.first, dir.second);
  assert(j1_dist + j2_dist >= tD + .0001);
  while (maxAng - minAng > .0000000001)
  {
    double midAng = (maxAng + minAng) / 2;
    double dx = tD - (cos(midAng) * j1_dist);
    double dy = sin(midAng) * j1_dist;
    // not far enough
    if(hypot(dx, dy) > j2_dist && dx > 0) {
      maxAng = midAng;
    } else { // overshot
      minAng = midAng;
    }
  }
  double stAngle = atan2(dir.second, dir.first);
  stAngle += minAng;
  return {cos(stAngle) * j1_dist, sin(stAngle) * j1_dist};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    pdd endP;
    cin >> endP.first >> endP.second;
    pdd curP = {0, 0};
    vi ord(n);
    vector<int> idx(a.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
                [&a](size_t i1, size_t i2) { return a[i1] < a[i2]; });
    vector<pdd> distances(n);
    int dSum = 0;
    for(int i = 0; i < n; i++) {
      dSum += a[idx[i]];
    }
    for (int i = n - 1; i >= 0; i--)
    {
      int curV = a[idx[i]];
      dSum -= curV;
      // it doesn't matter which direction
      if(d(curP, endP) < .001){
        distances[idx[i]].first = curV;
        distances[idx[i]].second = 0;
      // it's too far/impossible
      } else if(curV + dSum <= d(curP, endP) + .00001) {
        distances[idx[i]] = go_towards(curP, endP, curV);
      } else if (curV - dSum >= d(curP, endP) - .00001) {
        // it's too close/impossible
        distances[idx[i]] = go_towards(curP, endP, curV);
      } else if(dSum > curV + d(curP, endP)) {
        // we have lots of wiggle room
        distances[idx[i]] = go_towards(curP, endP, curV);
        distances[idx[i]].first *= -1;
        distances[idx[i]].second *= -1;
      } else { // need to be strategic now.
        pdd dir = {endP.first - curP.first, endP.second - curP.second};
        distances[idx[i]] = two_jumps(dir, curV, dSum);
      }
      curP.first += distances[idx[i]].first;
      curP.second += distances[idx[i]].second;
    }
    pdd loc = {0, 0};
    for (int i = 0; i < n; i++)
    {
      loc.first += distances[i].first;
      loc.second += distances[i].second;
      assert(abs(hypot(distances[i].first, distances[i].second) - a[i]) <= .01);
      printf("%.3lf %.3lf\n", loc.first, loc.second);
      // cout << loc.first << " " << loc.second << "\n";
    }

    return 0;
}