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
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<ll> distrib(1, 1LL << 63);
struct Hasher{
  ll hash;
  vector<int> S;
  vector<ll> hashes;

  ll my_hash(){
    return distrib(gen);
  }
  Hasher(vi& a) {
    S = vi(200000);
    map<int,int> seen_t;
    for(int i = 0; i < a.size(); i++){
      if(seen_t.count(a[i])){
        hashes.push_back(hashes[seen_t[a[i]]]);
      } else {
        hashes.push_back(my_hash());
      }
      seen_t[a[i]] = i;
    }
  }
  void add(int i, int val){
    if(S[val]++ == 0){
      hash ^= hashes[i];
    }
  }
  void remove(int i, int val){
    if(--S[val] == 0) {
      hash ^= hashes[i];
    }
    assert(S[val] >= 0);
  }
};
inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
    ) : (
                      (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi a(n);
    map<int,int> unique;
    rep(i, 0, n){
      cin >> a[i];
      unique[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
      a[i] = unique[a[i]];
    }
    vector<pii> intervals;
    vector<pii> a_intervals(q);
    vector<pii> b_intervals(q);
    rep(i, 0, q){
      cin >> a_intervals[i].first >> a_intervals[i].second;
      cin >> b_intervals[i].first >> b_intervals[i].second;
      a_intervals[i].first -= 1;
      b_intervals[i].first -= 1;
      intervals.push_back(a_intervals[i]);
      intervals.push_back(b_intervals[i]);
    }
    int rootn = sqrt(n);
    int logn = log2(n) + 1;
    sort(intervals.begin(), intervals.end(), [rootn, logn](pii& ai, pii& b) {
      int adiv = ai.first / rootn;
      int bdiv = b.first / rootn;
      if(adiv != bdiv) {
        return adiv < bdiv;
      } else {
        return ai.second < b.second;
      }
      // ll o1 = hilbertOrder(ai.first, ai.second, logn, 0);
      // ll o2 = hilbertOrder(b.first, b.second, logn, 0);
      // return o1 < o2;
    });
    int cur_st = 0;
    int cur_end = 0;
    map<pii, ll> hash_store;
    Hasher H(a);
    for(pii interval: intervals) {
      if(cur_end > interval.second) { // reset
        for(int i = interval.second; i < cur_end; i++){
          H.remove(i, a[i]);
        } 
      }else {
        for(int i = cur_end; i < interval.second; i++){
          H.add(i, a[i]);
        }
     }
     if(cur_st < interval.first) {
      for(int i = cur_st; i < interval.first; i++){
        H.remove(i, a[i]);
      }
     } else {
        for(int i = interval.first; i < cur_st; i++){
          H.add(i, a[i]);
        }
     }
     cur_end = interval.second;
     cur_st = interval.first;
     hash_store[interval] = H.hash;
    //  cout << (interval.first + 1) << " " << interval.second << " " << hash_store[interval] << endl;
    //  H.printS();
    }
    for(int i = 0; i < q; i++){
      if(hash_store[a_intervals[i]] == hash_store[b_intervals[i]]) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
    return 0;
}
