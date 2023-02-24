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
    cin >> n;
    vi a(n);
    rep(i, 0, n){
      cin >> a[i];
    }
    stack<int> one;
    stack<int> two;
    int cur_target = 1;
    rep(i, 0, n) {
      cin >> a[i];
      while(one.size() > 0 && one.top() < a[i]) { 
        cout << "12\n";
        two.push(one.top());
        one.pop();
      }
      one.push(a[i]);
      cout << "1\n";
      while(two.size() > 0) { 
        cout << "21\n";
        one.push(two.top());
        two.pop();
      }
      while(one.size() > 0 && one.top() == cur_target){
        cur_target += 1;
        cout << "-1\n";
        one.pop();
      }
    }
    return 0;
}