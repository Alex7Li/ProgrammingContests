#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
  #pragma GCC optimize("trapv") // signed overflow => RE
#else
  #pragma GCC target("arch=skylake") // CF only
#endif

struct Unit {
  int c;
  ll v;
};

int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, C;
  cin >> n >> C;
  vector<Unit> units(n);
  rep(i, 0, n) {
    ll d, h;
    cin >> units[i].c >> d >> h;
    units[i].v = d * h;
  }
  sort(units.begin(), units.end(), [](const Unit& a, const Unit& b){
    if(a.c == b.c){
      return a.v > b.v;
    } else{
      return a.c < b.c;
    }
  });
  vector<ll> maxScore(C + 2);
  maxScore[C + 1] = 2e18;
  int lastcost = -1;
  rep(i, 0, units.size()) {
    if(units[i].c == lastcost) {
      continue;
    } else {
      lastcost = units[i].c;
      ll value = 0;
      for(int j = units[i].c; j <= C; j += units[i].c){
        value += units[i].v;
        maxScore[j] = max(maxScore[j], value);
      }
    }
  }
  rep(i, 1, C + 2) {
    maxScore[i] = max(maxScore[i - 1], maxScore[i]);
  }

  int m;
  cin >> m;
  vector<ll> V(m);
  for(int i = 0; i < m; i++) {
    ll d, h;
    cin >> d >> h;
    V[i] = d * h;
    int opt_c = (1 << 20) - 1;
    for(int x = 1 << 19; x != 0; x /= 2) {
      if(opt_c - x >= maxScore.size() || maxScore[opt_c - x] > V[i]) {
        opt_c -= x;
      }
    }
    if(opt_c == C + 1){
      opt_c = -1;
    }
    cout << opt_c << " ";
  }


  return 0;
}