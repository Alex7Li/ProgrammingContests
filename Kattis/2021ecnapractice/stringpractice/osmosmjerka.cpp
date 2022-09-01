// https://oj.uz/problem/view/COCI17_osmosmjerka
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
struct H {
  typedef uint64_t ull;
  ull x;
  H(ull x = 0) : x(x) {}
#define OP(O, A, B)                                                            \
  H operator O(H o) {                                                          \
    ull r = x;                                                                 \
    asm(A "addq %%rdx, %0\nadcq $0,%0" : "+a"(r) : B);                         \
    return r;                                                                  \
  }
  OP(+, , "d"(o.x)) OP(*, "mul %1\n", "r"(o.x) : "rdx") H operator-(H o) {
    return *this + ~o.x;
  }
  ull get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};
struct chash {
    uint64_t operator()(const H &l) const {
        return l.x;
    }
};
static const H C = (ll)1e10 + 7; // (order ~ 3e9; random also ok)
// Return a vector v where v[i] is the hash of the substring [i, i + length)
vector<H> getHashes(vector<char> &str, int length) {
  H h = 0, pw = 1;
  rep(i, 0, length) h = h * C + str[i % sz(str)], pw = pw * C;
  vector<H> ret = {h};
  rep(i, length, length + sz(str)) {
    ret.push_back(h = h * C + str[i % sz(str)] -
                      pw * str[(i - length) % sz(str)]);
  }
  return ret;
}
H CPow(ll p) {
  if (p == 0) {
    return H(1);
  }
  H half = CPow(p / 2);
  if (p % 2 == 1) {
    return half * half * C;
  } else {
    return half * half;
  }
}
// return (C^{qs} + ... + C^{2s} + Cs + 1)
H CPowSum(ll q, ll s) {
  if (q < 0) {
    return H(0LL);
  }
  if (q == 0) {
    return H(1LL);
  }
  H lowTerms = CPowSum((q - 1) / 2, s);
  H highTerms = lowTerms * CPow(s * ((q + 1)/2));
  if(q % 2 == 0){
    highTerms = highTerms + CPow(q * s);
  }
  return highTerms + lowTerms;
}
vector<H> getHashesLong(vector<char> &str, ll length) {
  // last terms of the polynomial
  int s = str.size();
  int r = length % s;
  vector<H> rem = getHashes(str, r);
  // initial terms of the polynomial
  vector<H> p = getHashes(str, s);
  int q = length / s - 1;
  // return pC^r * (C^{qs} + ... + C^{2s} + C^s + 1)  + rem
  H v = CPow(r) * CPowSum(q, s);
  vector<H> ans(s);
  for (int i = 0; i < s; i++) {
    ans[i] = p[i] * v + rem[i];
  }
  return ans;
}

void merge(vector<H> &hashes, unordered_map<H, ll, chash> &c) {
  for (auto h : hashes) {
    if (c.find(h) == c.end()) {
      c[h] = 1;
    } else {
      c[h] += 1;
    }
  }
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
void count(vector<vc> &in, unordered_map<H, ll, chash> &counts, ll k) {
  for (int i = 0; i < in.size(); i++) {
    vector<H> rowHashes = getHashesLong(in[i], k);
    merge(rowHashes, counts);
  }
  ll g = gcd(in.size(), in[0].size());
  ll l = (ll)(in.size()) * (in[0].size() / g);
  for (int i = 0; i < g; i++) {
    vector<char> diag(l);
    for (int j = 0; j < l; j++) {
      diag[j] = in[(i + j) % in.size()][j % in[0].size()];
    }
    vector<H> diagHashes = getHashesLong(diag, k);
    merge(diagHashes, counts);
  }
}

vector<vc> rot90(vector<vc> &in) {
  vector<vc> out(in[0].size(), vc(in.size()));
  for (int i = 0; i < in.size(); i++) {
    for (int j = 0; j < in[0].size(); j++) {
      out[j][in.size() - i - 1] = in[i][j];
    }
  }
  return out;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n, k;
  cin >> m >> n >> k;
  vector<vc> a(m, vc(n));
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j];
    }
  }
  unordered_map<H, ll, chash> counts;
  for (int i = 0; i < 4; i++) {
    count(a, counts, k);
    a = rot90(a);
  }
  ll q = 8LL * m * n;
  q = q * q;
  ll p = 0;
  for (auto c : counts) {
    ll dups = c.second;
    p += dups * dups;
  }
  ll g = gcd(p, q);
  p = p / g;
  q = q / g;
  cout << p << "/" << q;
  return 0;
}
