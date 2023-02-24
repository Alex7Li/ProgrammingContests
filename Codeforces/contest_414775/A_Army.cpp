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
typedef vector<ll> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

// return
// number of soliders, cost used
pair<ll, ll> solve(ll thresh, ll n, vi& a, vi& b, vi& bpsum) {
  int j = b.size();
  ll nSoldiers =  0;
  ll cost = 0;
  for(int i = 0; i < a.size(); i++) {
    while(j >= 1 && a[i] + b[j - 1] > thresh) {
      j--;
    }
    nSoldiers += j;
    cost += j * a[i] + bpsum[j];
  }
  return {nSoldiers, cost};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll G, A, N;
    cin >> G >> A >> N;
    vi g(G);
    vi a(A);
    vi g_psum(G + 1);
    // vi a_psum(A + 1);
    rep(i, 0, G){
      cin >> g[i];
    }
    sort(g.begin(), g.end());
    rep(i, 0, G){
      g_psum[i + 1] = g_psum[i] + g[i];
    }
    rep(i, 0, A){
      cin >> a[i];
    }
    // for(int i = A - 1; i >= 0; i--) {
    //   a_psum[i] = a_psum[i + 1] + a[i];
    // }
    sort(a.begin(), a.end());
    ll tMin = 0;
    ll tMax = 1 << 24; // inclusive
    while(tMin < tMax) {
      int mid = (tMin + tMax) / 2;
      if(solve(mid, N, a, g, g_psum).first < N) {
        tMin = mid + 1;
      } else {
        tMax = mid;
      }
      if(tMin + 1 == tMax) {
        if(solve(tMin, N, a, g, g_psum).first < N) {
          tMin = tMax;
        } else {
          tMax = tMin;
        }
      }
    }
    pair<ll, ll> ans = solve(tMin, N, a, g, g_psum);
    ll finalAns = ans.second;
    if(ans.first > N) {
      finalAns -= tMin * (ans.first - N);
    }
    cout << finalAns << "\n";
    return 0;
}