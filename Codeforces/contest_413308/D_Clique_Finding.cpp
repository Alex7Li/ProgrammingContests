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
// Factor every number up until n in O(n) time.
// minFact[i] = the minimum factor of i higher than 1. minFact[0] = minFact[1] = 0
// primes[i] = the ith prime.
vector<int> factorAll(int n) {
    vector<int> primes(0);
    vector<int> minFact(n + 1);
    for (int i = 2; i <= n; i++) {
        if (minFact[i] == 0) {
            primes.push_back(i);
            minFact[i] = i;
        }
        for (int j = 0; j < primes.size() && primes[j] <= minFact[i] && i * primes[j] <= n; ++j) {
            minFact[i * primes[j]] = primes[j];
        }
    }
    return minFact;
}
#define MAX 1'000'001
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vi minFact = factorAll(MAX);
    vi dp = vi(MAX);
    int n;
    cin >> n;
    int best = 0;
    rep(i, 0, n){
      int v;
      cin >> v;
      dp[v]++;
      best = max(best, dp[v]);
      for(int i = 2 * v; i < MAX; i += v){
        dp[i] = max(dp[v], dp[i]);
      }
    }
    cout << best;
    return 0;
}
