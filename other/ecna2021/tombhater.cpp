#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define FAST               \
  ios::sync_with_stdio(0); \
  cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n';
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ld, ld> pd;
typedef complex<ld> cd;
#define M (51)
#define MM (51 * 51)
#define MMM (51 * 51 * 51)
#define MMMM (51 * 51 * 51 * 51)
int toInd(int x, int y, int wind, int cind) {
  return x + y * M  + wind * MM + cind * MMM;
}
int addDir(int indtype1, int dir) { return indtype1 + dir * MMMM; }
int getX(int x) { return x % 51; }
int getY(int x) { return (x / M) % 51; }
int getW(int x) { return (x / MM) % 51; }
int getC(int x) { return (x / MMM) % 51; }
int getDir(int x) { return (x / MMMM); }

int main() {
  FAST int m, n, k;
  cin >> n >> m >> k;
  if (n == 0) {
    finish(0);
  }
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  vector<string> words(k);
  for (int i = 0; i < k; i++) {
    cin >> words[i];
  }
  vector<pii> dirs = {{1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>> graph(MMMM);
  for (int x = 0; x < grid.size(); x++) {
    for (int y = 0; y < grid[0].size(); y++) {
      for (pii dir : dirs) {
        if (0 <= x + dir.f && x + dir.f < grid.size() && 0 <= y + dir.s &&
            y + dir.s < grid[0].size()) {
          for (int wind = 0; wind < k; wind++) {
            int l = words[wind].size();
            for (int cind = 0; cind < l - 1; cind++) {
              if (grid[x][y] == words[wind][cind] &&
                  grid[x + dir.f][y + dir.s] == words[wind][cind + 1]) {
                graph[toInd(x, y, wind, cind)].pb(
                    toInd(x + dir.f, y + dir.s, wind, cind + 1));
              }
            }
            for (int wind2 = 0; wind2 < k; wind2++) {
              if (grid[x][y] == words[wind][l - 1] &&
                  grid[x + dir.f][y + dir.s] == words[wind2][0]) {
                graph[toInd(x, y, wind, l - 1)].pb(
                    toInd(x + dir.f, y + dir.s, wind2, 0));
              }
            }
          }
        }
      }
    }
  }
  queue<int> Q;
  vector<int> d(MMMM * 3);
  for (int i = 0; i < grid[0].size(); i++) {
    for (int j = 0; j < words.size(); j++) {
      if(words[j][0] == grid[0][i]) {
        int pt = addDir(toInd(0, i, j, 0), 0);
        Q.push(pt);
        d[pt] = 1;
      }
    }
  }
  while (!Q.empty()) {
    int ind = Q.front();
    Q.pop();
    if (getX(ind) == n - 1 && sz(words[getW(ind)]) - 1 == getC(ind)) {
      // cout << getX(ind) << " "<< getY(ind) << " " << words[getW(ind)] << " "
      // << getC(ind) << "\n";
      finish(d[ind]);
    }
    int lastDir = getDir(ind);
    for (int next : graph[ind % (51 * 51 * 51 * 51)]) {
      int thisDir;
      if (getY(next) == getY(ind) + 1) {
        assert(getX(next) == getX(ind));
        thisDir = 1;
      } else if (getY(next) == getY(ind) - 1) {
        assert(getX(next) == getX(ind));
        thisDir = 2;
      } else {
        assert(getX(next) == getX(ind) + 1);
        thisDir = 0;
      }
      if (thisDir + lastDir == 3) {
        continue;
      }
      assert((getW(next) == getW(ind) && getC(next) == getC(ind) + 1) ||
             (getC(next) == 0 && words[getW(ind)].size() - 1 == getC(ind)));
      int nextWDir = addDir(next, thisDir);
      if (d[nextWDir] == 0) {
        // cout << getX(next) _ getY(next) _ words[getW(next)] _ getC(next) _
        // d[ind] << "\n";
        Q.push(nextWDir);
        d[nextWDir] = d[ind] + 1;
      }
    }
  }
  finish("impossible");
}
