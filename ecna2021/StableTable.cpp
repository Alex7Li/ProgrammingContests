#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> getDistances(vector<set<int>> &G, int source) {
  vector<int> distances(G.size());
  distances[source] = 1;
  queue<int> Q;
  Q.push(source);
  while(!Q.empty()){
    int from = Q.front();
    Q.pop();
    for(int next: G[from]) {
      if(distances[next] == 0) {
        distances[next] = distances[from] + 1;
        Q.push(next);
      }
    }
  }
  for (int i = 0; i < distances.size(); i++){
    if(distances[i] == 0){
      distances[i] = 100'000;
    }
  } return distances;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vi> table(h + 1, vi(w, 0));
    int pieces = 0;
    int top1 = 0;
    int top2 = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> table[i][j];
        pieces = max(pieces, table[i][j]);
        if(i == 0) {
          if(top1 == 0) {
            top1 = table[i][j];
          }else if(top1 != table[i][j]) {
            top2 = table[i][j];
          }
        }
      }
    }

    vector<set<int>> G(pieces + 1);
    vector<set<int>> Ginv(pieces + 1);
    for (int i = 0; i < h; i++){
      for(int j = 0; j < w; j++) {
        int bottom = table[i + 1][j];
        int top = table[i][j];
        G[bottom].insert(top);
        Ginv[top].insert(bottom);
      }
    }

    vector<int> groundDist = getDistances(G, 0);
    if(top2 == 0){
      cout << groundDist[top1] - 1 << endl;
    } else {
      vector<int> top1Dist = getDistances(Ginv, top1);
      vector<int> top2Dist = getDistances(Ginv, top2);
      int minD = 10'000;
      for (int i = 0; i <= pieces; i++) {
        minD = min(minD, top1Dist[i] + top2Dist[i] + groundDist[i] - 3);
      }
      cout << minD << endl;
    }
    return 0;
}