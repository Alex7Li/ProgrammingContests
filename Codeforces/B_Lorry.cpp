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

int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, v;
  cin >> n >> v; 
  vector<pii> w1;
  vector<pii> w2;
  rep(i, 0, n){
    int w, p;
    cin >> w >> p;
    if(w == 1) {
      w1.push_back({p, i});
    } else {
      assert(w == 2);
      w2.push_back({p, i});
    }
  }
  sort(w1.begin(), w1.end());
  sort(w2.begin(), w2.end());
  reverse(w1.begin(), w1.end());
  reverse(w2.begin(), w2.end());
  vector<int> psum_1(w1.size() + 1);
  vector<int> psum_2(w2.size() + 1);
  rep(i, 0, w1.size()) {
    psum_1[i + 1] = psum_1[i] + w1[i].first;
  }
  rep(i, 0, w2.size()) {
    psum_2[i + 1] = psum_2[i] + w2[i].first;
  }
  int st_ind_1 = min(v, len(w1));
  v -= st_ind_1;
  int st_ind_2 = min(v/2, len(w2));
  v -= 2 * st_ind_2;
  int best_score = psum_1[st_ind_1] + psum_2[st_ind_2];
  pii best_ans = {st_ind_1, st_ind_2};
  while(true) {
    st_ind_1 -= 2;
    while(st_ind_1 < len(w1) && v > 0) {
      v--;
      st_ind_1++;
    }
    st_ind_2 += 1;
    if(st_ind_1 < 0 || st_ind_2 > w2.size()) {
      break;
    }
    if(psum_1[st_ind_1] + psum_2[st_ind_2] > best_score) {
      best_score = psum_1[st_ind_1] + psum_2[st_ind_2];
      best_ans = {st_ind_1, st_ind_2};
    }
  }
  cout << best_score << "\n";
  rep(i, 0, best_ans.first) {
    cout << (w1[i].second + 1) << " ";
  }
  rep(i, 0, best_ans.second) {
    cout << (w2[i].second + 1) << " ";
  }
  return 0;
}
