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

vi Z_alg(string& S){
  int n = S.size();
  vi Z(n);
  int l = -1, r = -1;
  for(int i = 1; i < n; i++){
    if(i < r) {
      Z[i] = min(r - i, Z[i - l]);
    }
    while(i + Z[i] < n && S[Z[i]] == S[i + Z[i]]){
      Z[i] = Z[i] + 1;
    }
    if(Z[i] + i > r) {
      l = i;
      r = Z[i] + i;
    }
  }
  return Z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vi Z = Z_alg(s);
    set<int> suffix_lengths;
    int max_ol = 0;
    for(int i = 1; i < n; i++) {
      if(Z[i] + i == n) {
        suffix_lengths.insert(Z[i]);
        max_ol = max(max_ol, Z[i] - 1);
      } else {
        max_ol = max(max_ol, Z[i]);
      }
    }
    int largest = 0;
    for(int sl : suffix_lengths){
      if(sl <= max_ol){
        largest = max(largest, sl);
      }
    }
    int offset = s.size() - largest;
    if (largest == 0){
      cout << "Just a legend\n";
    }else{
      cout << s.substr(offset)<< "\n";
    }
    return 0;
}