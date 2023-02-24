#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
const ll mod = 1'000'000'007;
ll binomSum(ll n, ll k, vll& inv) {
  ll ans = 0;
  ll nci = 1;
  for(int i = 0; i <= k; i++) {
    ans = (ans + nci) % mod;
    ll f = (n - i) * inv[i + 1] % mod;
    nci = (nci * f) % mod;
    assert(ans > 0);
    assert(nci > 0);
  }
  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    int LIM = n + 5;
    vector<ll> inv(LIM);
    vector<ll> twopow(LIM);
    inv[1] = 1;
    twopow[0] = 1;
    rep(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    rep(i,1,LIM) twopow[i] = (twopow[i - 1] * 2) % mod;
    if (k >= n){
      cout << twopow[n] << "\n";
    } else {
      cout << binomSum(n, k, inv) << "\n"; 
    }
    return 0;
}
