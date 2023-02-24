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
    int n;
    long double R, r;
    cin >> n >> R >> r;
    int max = 0;
    if(r > R){
      cout << "NO";
      exit(0);
    }
    if (2 * r > R) {
      max = 1;
    } else {
      double theta = asin(r/(R-r));
      max = 3.14159265358979323846 / theta + 1e-9;
    }
    if(max >= n){
      cout << "YES";
    } else{
      cout << "NO";
    }
    return 0;
}