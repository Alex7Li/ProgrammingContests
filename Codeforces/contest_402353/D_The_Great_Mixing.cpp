#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
template<class k>
using hash_set = __gnu_pbds::gp_hash_table<k,  __gnu_pbds>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAX 1'005'000
#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

vi solve(vi& el) {
  sort(all(el));
  int max_v = el[el.size() - 1];
  vi owned(max_v + 1, 0);
  vi n_cokes(MAX, -1);
  for(int i = 0; i < el.size(); i++) {
    owned[el[i]] = 1;
  }
  n_cokes[0] = 0;
  for(int i = 0; i < el.size(); i++) {
    int v = el[i];
    for(int j = 0; j < n_cokes.size() - max_v - 1; j++) {
      if(n_cokes[j] != -1) {
        if(n_cokes[j + v] == -1){
          n_cokes[j + v] = n_cokes[j] + 1;
        } else {
          n_cokes[j + v] = min(n_cokes[j  + v], n_cokes[j] + 1);
        }
      }
    }
  }
  return n_cokes;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi pos;
    vi neg;
    rep(i, 0, k) {
      cin >> a[i];
      if(a[i] == n) {
        cout << 0 << '\n';
        return 1;
      }
      if(a[i] > n) {
        pos.push_back(a[i] - n);
      } else{
        neg.push_back(n - a[i]);
      }
    }
    if(pos.size() * neg.size() == 0) {
      cout << -1 << '\n';
      return 0;
    }
    vi upper = solve(pos);
    vi lower = solve(neg);
    int best = MAX;
    for(int i = 1; i < MAX; i++){
      if(upper[i] != -1 && lower[i] != -1) {
        if(upper[i] + lower[i] < best) {
          best = upper[i] + lower[i];
        }
      }
    }
    cout << best;
    return 0;
}