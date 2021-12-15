// https://codeforces.com/problemset/problem/1056/E
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct H {
  typedef uint64_t ull;
  ull x;
  H(ull x = 0) : x(x) {}
#define OP(O, A, B)                                                            \
  H operator O(H o) {                                                          \
    ull r = x;                                                                 \
    asm(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B);                        \
    return r;                                                                  \
  }
  OP(+, , "d"(o.x)) OP(*, "mul %1\n", "r"(o.x) : "rdx") H operator-(H o) {
    return *this + ~o.x;
  }
  ull get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11 + 3; // (order ~ 3e9; random also ok)

struct HashInterval {
  vector<H> ha, pw;
  HashInterval(string &str) : ha(sz(str) + 1), pw(ha) {
    pw[0] = 1;
    rep(i, 0, sz(str)) ha[i + 1] = ha[i] * C + str[i], pw[i + 1] = pw[i] * C;
  }
  H hashInterval(int a, int b) { // hash [a, b)
    return ha[b] - ha[a] * pw[b - a];
  }
};

H hashString(string &s) {
  H h{};
  for (char c : s)
    h = h * C + c;
  return h;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  string t;
  cin >> s >> t;
  ll ones = 0;
  ll zeros = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      zeros++;
    } else {
      ones++;
    }
  }
  HashInterval tHashes(t);
  int ways = 0;
  for (int zlen = 1; zlen < t.length(); zlen++) {
    ll olen = t.length() - (ll)(zlen) * zeros;
    if (olen <= 0 || olen % ones != 0) {
      continue;
    } else {
      olen /= ones;
    }
    set<H> hashes;
    int curSt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        hashes.insert(tHashes.hashInterval(curSt, curSt + zlen));
        curSt += zlen;
      } else {
        hashes.insert(tHashes.hashInterval(curSt, curSt + olen));
        curSt += olen;
      }
    }
    assert(curSt == t.length());
    if (hashes.size() == 2) {
      ways++;
    }
  }
  cout << ways << "\n";
  return 0;
}