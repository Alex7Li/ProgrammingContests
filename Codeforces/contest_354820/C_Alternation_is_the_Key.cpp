#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// https://github.com/kth-competitive-programming/kactl/blob/f6a97d9e5766c90ee71a97a90cd3faf6cff0ca72/stress-tests/data-structures/SegmentTree.cpp
struct Tree {
	typedef int T;
	const T unit = 0;
	T f(T a, T b) { return a + b; }
	vector<T> s; int n;
	Tree(int n = 0, T def = 0) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos > 1; pos /= 2)
			s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

ll c(ll d) {
  return (d * (d + 1)) / 2;
}
void split(int ind, set<int> &segLocs, int n, Tree& waySeg) {
  if(ind == n || ind == 0){
    return;
  }
  auto lptr = segLocs.upper_bound(ind);
  if (segLocs.count(ind)) {
    segLocs.erase(ind);
    int rb = *lptr;
    lptr--;
    int lb = *lptr;
    // cout << lb << " " <<  ind << " " << rb << "\n";
    waySeg.update(lb, c(rb - lb));
    waySeg.update(ind, 0);
  } else {
    int rb = *lptr;
    lptr--;
    int lb = *lptr;
    segLocs.insert(ind);
    waySeg.update(lb, c(ind - lb));
    waySeg.update(ind, c(rb - ind));
  }
}
ll query(Tree& waySeg, set<int>& segLocs, ll l, ll r){
  ll ans = waySeg.query(l, r);
  auto lptr = segLocs.lower_bound(l);
  if (*lptr < r)
  {
    ans += c(*lptr - l);
  }
  else
  {
    return ans;
  }
  auto rptr = segLocs.lower_bound(r);
  int rr = *rptr;
  int m = *(--rptr);

  ans -= waySeg.query(m, m + 1);
  ans += c(r - m);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      a[i] = 1 - a[i];
    }
  }
  set<int> segLocs;
  segLocs.insert(0);
  segLocs.insert(n);
  Tree waySeg(n);
  int last = -1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      ll d = i - last;
      waySeg.update(last + 1, (d * (d + 1)) / 2);
      last = i;
      segLocs.insert(i + 1);
    }
  }
  ll d = n - 1 - last;
  waySeg.update(last + 1, (d * (d + 1)) / 2);
  for (int i = 0; i < q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    if (t == 2) {
      cout << query(waySeg, segLocs, l, r) << "\n";
    } else {
      split(l, segLocs, n, waySeg);
      split(r, segLocs, n, waySeg);
    }
  }
  return 0;
}