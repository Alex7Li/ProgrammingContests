#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
const L INF = numeric_limits<L>::max() / 4;
// My book code
struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;
  MinCostMaxFlow(int N)
      : N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), found(N), dist(N),
        pi(N), width(N), dad(N) {}
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }
  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;

    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k])
          continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best])
          best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }
  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};

int main() {
  string g;
  cin >> g;
  map<int, int> gletters;
  for (char c : g) {
    int v = c - 'a';
    if (gletters.count(v)) {
      gletters[v] += 1;
    } else {
      gletters[v] = 1;
    }
  }
  int trays;
  cin >> trays;
  vector<int> counts(trays);
  vector<map<int, int>> letters(trays);
  for (int i = 0; i < trays; i++) {
    string s;
    cin >> s;
    cin >> counts[i];
    for (char c : s) {
      int v = c - 'a';
      if (letters[i].count(v)) {
        letters[i][v] += 1;
      } else {
        letters[i][v] = 1;
      }
    }
  }
  int gsize = 1 + trays + 26 + 1;
  MinCostMaxFlow mcmf(gsize);
  int source = gsize - 1;
  int sink = gsize - 2;
  for (int i = 0; i < trays; i++) {
    mcmf.AddEdge(source, 26 + i, counts[i], 0);
    for(auto p: letters[i]){
      mcmf.AddEdge(26 + i, p.first, p.second, i + 1);
    }
  }
  for (int i = 0; i < 26; i++) {
    mcmf.AddEdge(i, sink, gletters[i], 0);
  }
  pair<L, L> res = mcmf.GetMaxFlow(source, sink);
  if(res.first != g.size()){
    cout << "-1\n";
  } else {
    cout << res.second << "\n";
  }
  return 0;
}