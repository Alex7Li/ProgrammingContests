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

const ll N = 300'000;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

struct Value {
  int value;
  int index;
  bool right_side;
  bool operator<(const Value &v) const{
    if(value != v.value){
      return value < v.value;
    }
    if(index != v.index){
      return  index < v.index;
    }
    return v.right_side;
  }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi l(n);
    vi r(n);
    rep(i, 0, n){
      cin >> l[i] >> r[i];
    }
    set<Value> right;
    set<Value> left;
    ll leftSum = 0;
    ll rightSum = 0;
    ll lSize = 0;
    ll rSize = 0;
    left.insert({l[0], 0, false});
    right.insert({r[0], 0, true});
    cout << "0\n";
    rep(i, 1, n){
      Value l_max_v = *(left.rbegin());
      Value r_min_v = *right.begin();
      int l_max = l_max_v.value;
      int r_min = r_min_v.value;
      if(l[i] <= r_min && l_max <= r[i]){
        left.insert({l[i], i, false});
        right.insert({r[i], i, true});
      } else if (l[i] > r_min) {
        right.erase(right.begin());
        left.insert(r_min_v);
        right.insert({l[i], i, false});
        right.insert({r[i], i, true});
        rightSum += l[i];
        rSize += 1;
        if(r_min_v.right_side) {
          leftSum += r_min_v.value;
          lSize += 1;
        } else {
          rightSum -= r_min_v.value;
          rSize -= 1;
        }
      } else if (r[i] < l_max) {
        left.erase(--left.end());
        right.insert(l_max_v);
        left.insert({l[i], i, false});
        left.insert({r[i], i, true});
        leftSum += r[i];
        lSize += 1;
        if(l_max_v.right_side) {
          leftSum -= l_max_v.value;
          lSize -= 1;
        } else {
          rightSum += l_max_v.value;
          rSize += 1;
        }
      } else {
        assert(false);
      }
      ll p = left.rbegin()->value;
      ll L = p * lSize - leftSum;
      ll R = rightSum - p * rSize;
      cout << L + R << "\n";
    }
    return 0;
}