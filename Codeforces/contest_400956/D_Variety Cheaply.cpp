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
typedef pair<ll, int> pli;
typedef vector<int> vi;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (size_t i = 0; i < n; i++)
    {
      cin >> p[i];
    }
    sort(p.begin(), p.end());
    priority_queue<pli> Q;
    Q.push({-p[0], 0});
    ll cost = 0;
    for(int i = 0; i < k; i++){
      pli t = Q.top();
      Q.pop();
      cost = t.first;
      int ind = t.second;
      if(ind + 1 < n) {
        Q.push({cost - p[ind + 1] + p[ind], ind + 1});
        Q.push({cost - p[ind + 1], ind + 1});
      }
    }
    cout << -cost << "\n";
    return 0;
}
