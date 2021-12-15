#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  ll lo, hi, minV, maxV, madd = 0;
  Node(int lo, int hi, ll minV, ll maxV)
      : lo(lo), hi(hi), minV(minV), maxV(maxV) {}
  ll query(int t) {
    if (hi - lo == 1) {
      assert(minV == maxV);
      return maxV;
    }
    ll mid = lo + (hi - lo) / 2;
    push();
    if (t < mid) {
      return l->query(t);
    } else {
      return r->query(t);
    }
  }
  // add x to all elements in [minT, maxT)
  void add(ll L, ll R, ll x) {
    if (R <= minV || maxV < L) {
      return;
    } else if (L <= minV && maxV < R) {
      madd += x;
      minV += x;
      maxV += x;
    } else {
      push();
      l->add(L, R, x), r->add(L, R, x);
      maxV = max(l->maxV, r->maxV);
      minV = min(l->minV, r->minV);
    }
  }
  // Push the lazily stored values.
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid, minV, minV + mid - lo - 1);
      r = new Node(mid, hi, maxV - (hi - mid - 1), maxV);
      madd = 0;
    }
    else if (madd)
    {
      l->madd += madd;
      r->madd += madd;
      l->minV += madd;
      r->minV += madd;
      l->maxV += madd;
      r->maxV += madd;
      madd = 0;
    }
  }
};
const ll MAXT = 1LL << 30;
const ll MOD = 1'000'000'001;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  Node tree(0, MAXT, 0, MAXT - 1);
  int lastAns = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    // update the temp
    tree.add(t + 1, MAXT, -1);
    tree.add(0, t, 1);
    // do the queries
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      ll q;
      cin >> q;
      q = (q + lastAns) % MOD;
      ll ans = tree.query(q);
      cout << ans << "\n";
      lastAns = ans;
    }
  }
  return 0;
}