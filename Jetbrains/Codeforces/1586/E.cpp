# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// WRONG: 
// We are making the number of times each node is used even, but not each edge.
// One easy way is to find paths along a fixed spanning tree and to use only
// those paths.
bool dfs(int st, int end, vector<map<int, int>>& g, vector<bool>& seen, vi& path, bool odds_only){
  for(pii x: g[st]){
    if(!seen[x.first] && (!odds_only || g[st][x.first] % 2)){
      seen[x.first] = true;
      g[st][x.first]++;
      g[x.first][st]++;
      path.push_back(x.first);
      if(x.first == end || dfs(x.first, end, g, seen, path, odds_only)){
        return true;
      }
      path.pop_back();
      g[st][x.first]--;
      g[x.first][st]--;
    }
  }
  return false;
}


vi path(int st, int end, vector<map<int, int>>& g, bool odds_only){
  vector<bool> seen(g.size());
  vi the_path = {st};
  seen[st] = true;
  dfs(st, end, g, seen, the_path, odds_only);
  return the_path;
}

vi trim_path(vi& a_path, vector<map<int, int>>& g){
  // Kill current path
  for(int i = 0; i < a_path.size() - 1; i++){
    g[a_path[i]][a_path[i+1]]--;
    g[a_path[i + 1]][a_path[i]]--;
  }
  vector<bool> seen(g.size());
  return path(a_path[0], a_path[a_path.size() - 1], g, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        g[x][y] = 0;
        g[y][x] = 0;
    }
    int q;
    cin >> q;
    vector<int> c(n);
    vector<pii> p(q);
    for(int i = 0; i < q; i++) {
      int x, y;
      cin >> x >> y;
      x--;y--;
      c[x]++;
      c[y]++;
      p[i] = pii(x, y);
    }
    int bad = 0;
    for(int i = 0; i < n; i++){
      if(c[i] % 2 ==1){
        bad++;
      }
    }
    if(bad > 0){
      cout << "NO\n" << bad/2 << "\n";
    } else {
      cout << "YES\n";
      vector<vi> paths;
      for(int i = 0; i < p.size(); i++){
        vi curP;
        paths.push_back(path(p[i].first, p[i].second, g, false));
      }
      for(int i = 0; i < p.size(); i++){
        paths[i] = trim_path(paths[i], g);
      }
      for(int i =0; i < p.size(); i++){
        cout << paths[i].size() << "\n";
        for(int j = 0; j < paths[i].size(); j++) {
            cout << (paths[i][j] + 1) << " ";
        }
        cout << "\n";
      }
    }
    return 0;
}