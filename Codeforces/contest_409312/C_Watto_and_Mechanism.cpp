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
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

ll MOD1 = 10e9 + 7;
ll MOD2 = 10e9 + 9;

pair<ll, ll> operator+(pair<ll, ll> a, ll b) {
  return pair<ll, ll>((a.first + b) % MOD1, (a.second + b) % MOD2);
}
pair<ll, ll> operator*(pair<ll, ll> a, ll b) {
  return pair<ll, ll>((a.first * b) % MOD1, (a.second * b) % MOD2);
}
pair<ll, ll> operator-(pair<ll, ll> a, pair<ll, ll> b) {
  return pair<ll, ll>((a.first - b.first + MOD1) % MOD1, (a.second - b.second + MOD2) % MOD2);
}

pair<ll, ll> operator+(pair<ll, ll> a, pair<ll, ll> b) {
  return pair<ll, ll>((a.first + b.first) % MOD1, (a.second + b.second) % MOD2);
}

pair<ll, ll> operator*(pair<ll, ll> a, pair<ll, ll> b) {
  return pair<ll, ll>((a.first * b.first) % MOD1, (a.second * b.second) % MOD2);
}

struct Hash {
  pair<ll, ll> H;
  Hash(string& s){
    H = pair<ll, ll>(0,0);
    for(char c : s){
      add(c);
    }
  }
  void add(char c){
    H = H * 4 + (1 + c - 'a');
  }
  vector<pair<ll, ll>> mistakes(string& orig){
    pair<ll, ll> pow = {1, 1};
    vector<pair<ll, ll>> offByOne;
    for(int i = 0; i < orig.size(); i++) {
      ll coef = (1 + orig[orig.size() - i - 1] - 'a');
      pair<ll, ll> H_temp = H - pow * coef;
      if(coef != 1) {
        offByOne.push_back(H_temp + pow);
      }
      if(coef != 2) {
        offByOne.push_back(H_temp + pow * 2);
      }
      if(coef != 3) {
        offByOne.push_back(H_temp + pow * 3);
      }
      pow = pow * 4;
    }
    return offByOne;
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    unordered_map<int, set<pair<ll, ll>>> hashes;
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      int L = s.size();
      Hash H(s);
      vector<pair<ll, ll>> mistakes = H.mistakes(s);
      for(pll mi: mistakes){
        hashes[L].insert(mi);
      }
    }
    for(int i = 0; i < m; i++){
      string s;
      cin >> s;
      pair<ll, ll> p = Hash(s).H;
      if(hashes[s.size()].count(p) == 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
    return 0;
}