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
typedef vector<vector<pii>> graph;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int U;
    cin >> U >> U;
    U = (U + 1) / 2;
    graph G(n);
    for (int i = 0; i < m; i++){
      int a, b, d;
      cin >> a >> b >> d;
      G[a].push_back({d, b});
      G[b].push_back({d, a});
    }
    vector<bool> seen(n);
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, 0});
    while (!Q.empty()) {
      auto p = Q.top();
      Q.pop();
      int d = p.first;
      int intersection = p.second;
      if(d >= U) {
        continue;
      }
      seen[intersection] = true;
      for (auto x: G[intersection]){
        if(!seen[x.second]) {
          Q.push({d + x.first, x.second});
        }
      }
    }
    set<pii> streets;
    for (int i = 0; i < n; i++){
      if(seen[i]) {
        for(auto x : G[i]) {
          int j = x.second;
          if(j > i){
            streets.insert({j, i});
          } else {
            streets.insert({i, j});
          }
        }
      }
    }
    cout << streets.size() << "\n";
    return 0;
}
