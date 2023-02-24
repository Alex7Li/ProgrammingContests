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

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

bool solve(set<pii>& unknown, vi scores, int seed) {
  for(pii p: unknown){
    assert(p.first < p.second);
    if(seed % 3 == 2){
      scores[p.first] += 3;
    }else if(seed % 3 == 1){
      scores[p.first] += 1;
      scores[p.second] += 1;
    }else{
      scores[p.second] += 3;
    }
    seed /= 3;
  }
  for(int i = 1; i < scores.size(); i++){
    if(scores[i] >= scores[0]){
      return false;
    }
  }
  return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    set<pii> unknown;
    rep(i, 0, n){
      rep(j, i + 1, n){
        unknown.insert({i, j});
      }
    }
    set<pii> known;
    vector<int> scores(n);
    vector<int> mapping(n);
    rep(i, 0, n){
      mapping[i] = i;
    }
    swap(mapping[0], mapping[k - 1]);
    rep(i, 0, m) {
      int a, pa, b, pb;
      cin >> a >> pa >> b >> pb;
      a = mapping[a - 1];
      b = mapping[b - 1];
      if (a > b){
        swap(a, b);
        swap(pa, pb);
      }
      pii v = {a, b};
      assert(a < b);
      assert(known.count(v) == 0);
      assert(unknown.count(v) == 1);
      known.insert(v);
      unknown.erase(v);
      scores[a] += pa;
      scores[b] += pb;
    }
    rep(i, 1, n) {
      pii v = {0, i};
      if(known.count(v) == 0) {
        known.insert(v);
        unknown.erase(v);
        scores[0] += 3;
      }
    }
    bool possible = false;
    rep(i, 0, pow(3, unknown.size())) {
      if(solve(unknown, scores, i)){
        possible = true;
        break;
      }
    }
    if(possible){
      cout << "YES";
    } else {
      cout << "NO";
    }
    return 0;
}