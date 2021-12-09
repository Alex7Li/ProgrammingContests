// https://cses.fi/problemset/task/1684
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct TwoSat {
  int N;
  vector<vi> gr;
  vi values; // 0 = fa lse , 1 = true
  TwoSat(int n = 0) : N(n), gr(2 * n) {}
  int addVar() { // ( optional )
    gr.emplace_back();
    gr.emplace_back();
    return N++;
  }
  void either(int f, int j) {
    f = max(2 * f, -1 - 2 * f);
    j = max(2 * j, -1 - 2 * j);
    gr[f].push_back(j ^ 1);
    gr[j].push_back(f ^ 1);
  }
  void setValue(int x) { either(x, x); }
  void atMostOne(const vi &li) { // ( optional )
    if (sz(li) <= 1)
      return;
    int cur = ~li[0];
    rep(i, 2, sz(li)) {
      int next = addVar();
      either(cur, ~li[i]);
      either(cur, next);
      either(~li[i], next);
      cur = ~next;
    }
    either(cur, ~li[1]);
  }
  vi val, comp, z;
  int time = 0;
  int dfs(int i) {
    int low = val[i] = ++time, x;
    z.push_back(i);
    for (int e : gr[i])
      if (!comp[e])
        low = min(low, val[e] ?: dfs(e));
    if (low == val[i])
      do {
        x = z.back();
        z.pop_back();
        comp[x] = low;
        if (values[x >> 1] == -1)
          values[x >> 1] = x & 1;
      } while (x != i);
    return val[i] = low;
  }
  bool solve() {
    values.assign(N, -1);
    val.assign(2 * N, 0);
    comp = val;
    rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
    rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
    return 1;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  TwoSat solver(m + 1);
  for(int i = 0; i < n; i++) {
    char p1, p2;
    int a1, a2;
    cin >> p1 >> a1 >> p2 >> a2;
    if(p1 == '-') {
      a1 = ~a1;
    }
    if(p2 == '-') {
      a2 = ~a2;
    }
    solver.either(a1, a2);
  }
  if(solver.solve()){
    for(int i = 1; i < m; i++){
      cout << (solver.values[i] ? '+' : '-') << " ";
    }
    cout << (solver.values[m] ? '+' : '-');
  }
  else
  {
    cout << "IMPOSSIBLE";
  }
  return 0;
}
