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

void make_p(vi& p, vector<vi>& G, int cur){
  for(int next: G[cur]) {
    if(p[next] == -1){
      p[next] = cur;
      make_p(p, G, next);
    }
  }
}
void fill_parents(vector<bool>& set, vector<vi>& G, int cur, vi& p) {
  bool has_child = false;
  for(int next: G[cur]) {
    if(p[next] == cur) {
      fill_parents(set, G, next, p);
      has_child |= set[next];
    }
  }
  set[cur] = set[cur] | has_child;
}
vector<vi> make_pp(vi& p) {
  vector<vi> pp;
  pp.push_back(p);
  rep(i, 0, 18) {
    vi* p_next = new vi(p.size());
    vi last_pow = pp[i];
    rep(j, 0, p.size()) {
      (*p_next)[j] = last_pow[last_pow[j]];
    }
    pp.push_back(*p_next);
  }
  return pp;
}
int nth_parent(vector<vi>& pp, int child, int n) {
  int parent = child;
  for(int i = 0; (1 << i) <= n; i++) {
    if((1 << i) & n) {
      parent = pp[i][parent];
    }
  }
  return parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int d;
    cin >> n >> d;
    vector<vi> G(n);
    rep(i, 0, n - 1) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      G[y].push_back(x);
      G[x].push_back(y);
    }
    vi p(n, -1);
    p[0] = 0;
    make_p(p, G, 0);
    vector<vi> pp = make_pp(p);
    int m1, m2;
    cin >> m1;
    vector<bool> s1(2e5+2);
    vector<bool> s2(2e5+2);
    rep(i, 0, m1) {
      int x;
      cin >> x;
      x--;
      s1[x] = true;
      s2[nth_parent(pp, x, d)] = true;
    }
    cin >> m2;
    rep(i, 0, m2) {
      int x;
      cin >> x;
      x--;
      s2[x] = true;
      s1[nth_parent(pp, x, d)] = true;
    }
    fill_parents(s1, G, 0, p);
    fill_parents(s2, G, 0, p);
    int c1=0, c2=0;
    cerr << s1[0] _ s1[1] _ s1[2] _ s1[3] _ "\n";
    rep(i, 0, n){
      if(s1[i]){
        c1++;
      }
      if(s2[i]){
        c2++;
      }
    }
    cout << (c1 + c2 - 2) * 2 << "\n";
    return 0;
}