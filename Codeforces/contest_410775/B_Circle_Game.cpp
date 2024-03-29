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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(i, 0, t){
      ll d, k;
      cin >> d >> k;
      ll st = 0;
      while(2 * st * st < d * d){
        st += k;
      }
      st -= k;
      ll end = st * st + st * st;
      ll penend = st * st + (st + k) * (st + k);
      if(penend <= d * d) {
        // there is another move
        cout << "Ashish\n";
      } else {
        cout << "Utkarsh\n";
      }
    }


    return 0;
}