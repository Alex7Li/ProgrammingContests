#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

int M = 10'001'000;

bool has7(int x) {
  while(x > 0) {
    if(x % 10 == 7) {
      return true;
    }
    x = x / 10;
  }
  return false;
}

vi getHas7s(){
  vi ans;
  rep(i, 7, M) {
    if(has7(i)){
      ans.push_back(i);
    }
  }
  return ans;
}

vector<bool> sieve(vector<int>& primes) {
  vector<bool> isMultiple(M, false);
  for(int p: primes) {
    if(!isMultiple[p]) {
      for(int c = p; c < M; c += p) {
        isMultiple[c] = true;
      }
    } 
  }
  return isMultiple;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vi has7s = getHas7s();
  vector<bool> isMultipl = sieve(has7s);
  vector<int> ans(sz(isMultipl), -1);
  int last = -1;
  for(int i = M - 1; i >= 0; i--) {
    if (!isMultipl[i]) {
      ans[i] = last;
      last = i;
    }
  }
  int n_tests;
  cin >> n_tests;
  for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int val;
    cin >> val;
    cout << ans[val] << "\n";
  }
  return 0;
}