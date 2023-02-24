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
typedef pair<ll, ll> pll;

struct Frac{
  ll num, denom;
  bool T::operator <(const Frac& other){
    return this.num * other.denom < this.denom * other.num;
  }
}

// length * 2 + 1
Frac score(vi& a, &vi pSum, int mid, int length) {
  int lStart = mid - length + 1;
  int rStart = n - length;
  if(lStart < 0 || rStart <= mid) {
    return Frac({0, 1});
  }
  ll sum = 0;
  rep(i, lStart, mid + 1){

  }
  pll best= (0, 1);
  Frac bestScore = Frac(0,0);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    vi pSum(n + 1);
    rep(i, 0, n){
      cin >> a[i];
      pSum[i + 1] = pSum[i] + a[i];
    }
    sort(all(a));
    pii best(0, 1);
    rep(i, 1, n) {
      int minV = 0;
      int maxV = n / 2;
      while(minV < maxV) {
       mid1 = (minV + maxV * 2) / 3;
       mid2 = (minV * 2 + maxV) / 3;

      }

      
    }
    return 0;
}