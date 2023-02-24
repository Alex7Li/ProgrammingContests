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

bool works(vector<vi>& a, int l) {
  int n = a.size();
  int m = a[0].size();
  if(l > n || l > m) {
    return false;
  }
  vi lastBad(n, -1);
  rep(j, 0, m) {
    // update lastBad
    rep(i, 0, n) {
      if(a[i][j] < l) {
        lastBad[i] = j;
      }
    }
    if(j >= l - 1) {
      int lastColBad = -1;
      rep(i, 0, n) {
        if(lastBad[i] > j - l) {
          lastColBad = i;
        }
        if(lastColBad <= i - l){
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int minL = 1;
    int maxL = 1'000;
    while(minL != maxL) {
      int midL = (minL + maxL) / 2;
      if(works(a, midL)) {
        minL = midL;
        if(maxL == minL + 1) {
          if(works(a, maxL)) {
            minL = maxL;
          } else{
            maxL = maxL - 1;
          }
        }
      } else {
        maxL = midL - 1;
      }
    }
    cout << minL << "\n";
  }

  return 0;
}