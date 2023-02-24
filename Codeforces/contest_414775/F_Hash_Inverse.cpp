#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
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
int polyhash(string& s, int p, int m, ll offset) {
	long long res = 0;
	long long place = offset;
	for (int i=0; i < s.size(); i++) {
		res += ((s[i] - 'a' + 1) * place) % m;
		res %= m;
		place *= p;
		place %= m;
	}
	return res;
}
#define M 15

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, m, x;
    cin >> p >> m >> x;
    vector<ll> pows;
    pows.push_back(1);

    for(int i = 0; i <= M; i++) {
      pows.push_back((pows[i] * p) % m);
    }
    hash_map<int, string> low_collisions ;
    hash_map<int, string> high_collisions ;
    for(int i = 0; i < 1 << M; i++) {
      string s;
      for(int j = 0; j < M; j++){
        if(i & (1 << j)){
          s += 'a';
        } else {
          s += 'b';
        }
      }
      int hash = polyhash(s, p, m, 1);
      int highhash = (polyhash(s, p, m, 1) * pows[M]) % m;
      low_collisions[hash] = s;
      high_collisions[highhash] = s;
    }
    for(auto c: low_collisions){
      int goal = x - c.first;
      if(high_collisions.find(goal) != high_collisions.end()){
        string str = high_collisions[goal];
        cout << low_collisions[c.first] << str << "\n";
        return 0;
      }
    }
    cout << "FAIL";
    return 0;
}