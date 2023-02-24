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
#define INF 1'000'000'007
#ifdef LOCAL
  #pragma GCC optimize("trapv") // signed overflow => RE
#else
  #pragma GCC target("arch=skylake") // CF only
#endif

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);
}

#define LIM 1'000'007
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  vi phi(LIM);
  rep(i,0,LIM) phi[i] = i&1 ? i : i/2;
  for (int i = 3; i < LIM; i += 2) if(phi[i] == i)
  for (int j = i; j < LIM; j += i) phi[j] -= phi[j] / i;
  vector<ll> n_coprime(LIM);
  phi[1] -= 1;
  rep(i, 1, LIM) {
    n_coprime[i] = n_coprime[i - 1] + phi[i];
  }
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    ll m;
    cin >> n >> m;
    ll cost = 0;
    // greedy works
    int X = pow(n, 2.001/3.0);
    for(int k = X + 1; k >= 1 && m != 0; k--) {
      ll n_gcds = n_coprime[n / (k + 1)];
      ll batches = min(n_gcds / k, (m + k - 1) / k);
      m -= batches * k;
      cost += batches * (k + 1);
      if(m < 0) {
        if(k == 1 && m == -1) {
          cost = -1; // impossible case
        } else {
          cost += m;
        }
        m = 0;
      }
    }
    if(m > 0){
      cost = -1;
    }
    cout << cost << "\n";
  }
  return 0;
}