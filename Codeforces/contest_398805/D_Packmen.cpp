#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool works(int t, vi& pack_locs, vi& asts) {
  int ast_i = 0;
  for(int pack_loc: pack_locs) {
    if(ast_i >= asts.size()) {
      assert(ast_i == asts.size());
      return true;
    } else if(asts[ast_i] < pack_loc - t) {
      return false;
    } else {
      // go backwards first
      int t_forwards = t - (pack_loc - asts[ast_i]) * 2;
      // go forwards first
      t_forwards = max(t_forwards, (t - (pack_loc - asts[ast_i])) / 2);
      t_forwards = max(min(t_forwards, t), 0);
      int max_distance = pack_loc + t_forwards;
      while(ast_i < asts.size() && asts[ast_i] <= max_distance) {
        ast_i += 1;
      }
    }
  }
  return ast_i == asts.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi pack_loc;
    vi ast;
    rep(i, 0, n) {
      char c;
      cin >> c;
      if (c == '*'){
        ast.push_back(i);
      } else if (c == 'P') {
        pack_loc.push_back(i);
      }
    }
    int l = (1 << 21) - 1;
    for(int sub = 1 << 20; sub != 0; sub /= 2){
      if (works(l - sub, pack_loc, ast)) {
        l = l - sub;
      }
    }
    assert(!works(l - 1, pack_loc, ast)); 
    cout << l;
    return 0;
}
