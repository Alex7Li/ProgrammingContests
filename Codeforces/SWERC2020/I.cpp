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
typedef vector<vi> graph;

pii run_away(graph& G, int st) {
  queue<int> Q;
  vector<int> seen(G.size());
  seen[st] = 1;
  Q.push(st);
  int cur = st;
  while (!Q.empty()) {
    cur = Q.front();
    Q.pop();
    for(int next: G[cur]) {
      if(!seen[next]) {
        seen[next] = seen[cur] + 1;
        Q.push(next);
      }
    }
  }
  for (int i = 0; i < int(G.size()); i++) {
    if(!seen[i]) {
      return {-1, st};
    } 
  }
  return {seen[cur] - 1, cur};
}

int main() {
  int n, m;
  cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int st = 0;
  int best_d = -1;
  while (true) {
    pii p = run_away(g, st);
    int dist = p.first;
    st = p.second;
    if(dist == -1){
      cout << -1 << endl;
      return 0;
    }
    if (best_d == dist) {
      break;
    }
    best_d = dist;
  }
  int days = 0;
  int oof = 1;
  while(oof < best_d) {
    days += 1;
    oof = oof + oof;
  }
  cout << days + 1 << "\n";
  return 0;
}