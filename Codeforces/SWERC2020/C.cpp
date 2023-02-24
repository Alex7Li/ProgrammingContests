#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<double, double> P;
double d[1000][1000];
double dista(P a, P b) { return hypot(a.first - b.first, a.second - b.second); }
bool isPath(vector<vi>& G, vector<bool>& seen, int st, int end) {
  seen[st] = true;
  for (int x : G[st]) {
    if(x == end) {
      return true;
    } else if(!seen[x]) {
      if (isPath(G, seen, x, end)) {
        return true;
      }
    }
  }
  return false;
}
bool works(vector<P>& points, double R, int mX, int mY) { int n = points.size();
  vector<vi> G = vector<vi>(n + 2);
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      bool ok = d[i][j] < 2 * R;
      if(ok) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
    bool ok1 = points[i].first < R or points[i].second > mY - R;
    bool ok2 = points[i].second < R or points[i].first > mX - R;
    if(ok1) {
      G[i].push_back(n);
      G[n].push_back(i);
    }
    if(ok2) {
      G[i].push_back(n + 1);
      G[n + 1].push_back(i);
    }
  }
  vector<bool> seen(n + 2);
  return isPath(G, seen, n, n + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x, y;
  cin >> x >> y;
  int n;
  cin >> n;
  vector<P> points(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> points[i].first >> points[i].second;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      d[i][j] = dista(points[i], points[j]);
    }
  }
  double R = 0;
  double dR = 1000000;

  while(dR > 4e-6 && (R + dR) / R > 1 + 4e-6) {
    if(!works(points, R + dR, x, y)) {
      R += dR;
    }
    dR /= 2;
  }
  std::printf("%.10f", R);
  return 0;
}