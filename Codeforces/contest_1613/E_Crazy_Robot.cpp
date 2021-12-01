#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void search(pii loc, vector<string> &grid, vector<vector<bool>> &seen) {
  if (seen[loc.first][loc.second]) {
    return;
  }
  seen[loc.first][loc.second] = true;
  vi dx = {-1, 0, 1, 0};
  vi dy = {0, -1, 0, 1};
  char g = grid[loc.first][loc.second];
  if (g == '.') {
    // Maybe make g a '+'
    int wrong_paths = 0;
    for (int i = 0; i < 4; i++) {
      int x = loc.first + dx[i];
      int y = loc.second + dy[i];
      if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()) {
        if (grid[x][y] == '.') {
          wrong_paths += 1;
        }
      }
    }
    if (wrong_paths <= 1) {
      grid[loc.first][loc.second] = '+';
      // unsee nearby squares
      for (int i = 0; i < 4; i++) {
        int x = loc.first + dx[i];
        int y = loc.second + dy[i];
        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()) {
          if (grid[x][y] == '.') {
            seen[x][y] = false;
          }
        }
      }
    }
  }
  if (grid[loc.first][loc.second] == '+') {
    for (int i = 0; i < 4; i++) {
      int x = loc.first + dx[i];
      int y = loc.second + dy[i];
      if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()) {
        if (grid[x][y] == '.') {
          search(pii(x, y), grid, seen);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    pii lab;
    for (int i = 0; i < n; i++) {
      cin >> grid[i];
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'L') {
          lab = pii(i, j);
          grid[i][j] = '+';
        }
      }
    }
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    search(lab, grid, seen);
    grid[lab.first][lab.second] = 'L';
    for (int i = 0; i < n; i++) {
      cout << grid[i] << "\n";
    }
  }
  return 0;
}