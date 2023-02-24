#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'

#ifdef LOCAL
#pragma GCC optimize("trapv")  // signed overflow => RE
#else
#pragma GCC target("arch=skylake")  // CF only
#endif
// Description: ntt(a) computes ˆf (k) = ∑
// x a[x]gxk for all k, where g =
// root(mod−1)/N . N must be a power of 2. Useful for convolution modulo spe-
// cific nice primes of the form 2a b + 1, where the convolution result has size
// at most 2a . For arbitrary modulo, see FFTMod. conv(a, b) = c, where
// c[x] = ∑ a[i]b[x − i]. For manual convolution: NTT the inputs, multiply
// pointwise, divide by n, reverse(start+1, end), NTT back. Inputs must be in
// [0, mod).
const ll mod = (119 << 23) + 1, root = 62;  // = 998244353
ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
typedef vector<ll> vl;
void ntt(vl &a) {
  int n = sz(a), L = 31 - __builtin_clz(n);
  static vl rt(2, 1);
  for (static int k = 2, s = 2; k < n; k *= 2, s++) {
    rt.resize(n);
    ll z[] = {1, modpow(root, mod >> s)};
    rep(i, k, 2 * k) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  vi rev(n);
  rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
        ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? mod : 0);
        ai += (ai + z >= mod ? z - mod : z);
      }
}
vl conv(const vl &a, const vl &b) {
  if (a.empty() || b.empty()) return {};
  int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
  int inv = modpow(n, mod - 2);
  vl L(a), R(b), out(n);
  L.resize(n), R.resize(n);
  ntt(L), ntt(R);
  rep(i, 0, n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
  ntt(out);
  return {out.begin(), out.begin() + s};
}

struct DSU {
  vi e;
  vi c;
  vector<pii> st;
  vector<vector<vl>> ways;
  DSU(int n) : e(n, -1), c(n, 0){
    rep(i, 0, n) {
      ways.push_back(vector<vl>(1, vl(1, 1))); 
    }
  }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return sz(st); }
  void merge(vector<vl> &wayList) {
    int n = sz(wayList);
    while (wayList.size() > 1) {
      wayList[0] = conv(wayList[0], wayList[wayList.size() - 1]);
      wayList.pop_back();
    }
    vl ans2 = vl(sz(wayList[0]) + n - 1);
    ans2[0] = 1;
    rep(i, 0, sz(wayList[0])) {
      ans2[i + n - 1] = wayList[0][i];
    }
    wayList[0] = ans2;
  }
  void join(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
      if (e[a] > e[b]) swap(a, b);
      st.push_back({a, e[a]});
      st.push_back({b, e[b]});
      e[a] += e[b];
      c[a] += c[b];
      e[b] = a;
      while (sz(ways[b])) {
        ways[a].push_back(ways[b][ways[b].size() - 1]);
        ways[b].pop_back();
      }
    }
    c[a]++;
    if (c[a] == (-e[a] * (-e[a] - 1)) / 2) {
      merge(ways[a]);
    }
  }
};

struct Edge {
  int w;
  int l, r;
  bool operator<(Edge &o) { return w < o.w; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Edge> edges;
  int x;
  rep(i, 0, n) {
    rep(j, 0, n) {
      cin >> x;
      if (i < j) {
        edges.push_back({x, i, j});
      }
    }
  }
  sort(edges.begin(), edges.end());
  DSU dsu(n);
  rep(i, 0, edges.size()) {
    dsu.join(edges[i].l, edges[i].r);
  }
  vl ans = dsu.ways[dsu.find(0)][0];
  rep(i, 0, ans.size()) {
    cout << ans[i] << " ";
  }
  return 0;
}