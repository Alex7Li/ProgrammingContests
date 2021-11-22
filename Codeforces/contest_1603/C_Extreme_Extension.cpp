#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 998'244'353;
const ll MAX = 100'002;

map<int, int> getCounts(int a) {
  priority_queue<int> Q;
  map<int, int> counts;
  counts[a] = 1;
  Q.push(a);
  while (!Q.empty()) {
    int top = Q.top();
    Q.pop();
    int v = (top + 1) / 2;
    if (counts.count(v)) {
      counts[v] += counts[a];
    } else {
      counts[v] = counts[a];
      Q.push(v);
    }
    int v = top / 2;
    if (counts.count(v)) {
      counts[v] += counts[a];
    } else {
      counts[v] = counts[a];
      Q.push(v);
    }
  }
  return counts;
}
map<int, int> getCosts(map<int, int> counts){
  for (auto x = counts.rbegin(); x != counts.rend(); x--){

  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    map<int, pii> w;
    w[a[n - 1]] = {1, 0};
    for (int i = n - 2; i >= 0; i--) {
      map<int, int> counts = getCounts(a[i]);
      map<int, int> costs = getCosts(counts);
    }
  }

  return 0;
}