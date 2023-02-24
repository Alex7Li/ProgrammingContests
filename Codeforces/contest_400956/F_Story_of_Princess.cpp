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
typedef vector<vi> vii;
typedef vector<set<int>> Graph;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

vi find_tour(int st, Graph& G) {
  
}
vi find_e2e(int st, Graph& G, set<int>& odd_locs) {
  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, 0, n){
      rep(j, 0, n){
        int from, to;
        cin >> from >> to;
        to -= 1;
        from -= 1;
        G[to].insert(from);
        G[from].insert(to);
      }
    }
    // Connected components

    // 


    return 0;
}