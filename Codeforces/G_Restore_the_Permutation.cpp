#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
template <class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
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
#define INF 1'000'000
namespace Node {
int n;
vector<int> minV;
vector<int> lazy;

void construct(vi& data, int l, int r, int ind) {
  if (l + 1 == r) {
    minV[ind] = data[l];
  } else {
    int mid = (l + r) / 2;
    construct(data, l, mid, ind * 2);
    construct(data, mid, r, ind * 2 + 1);
    minV[ind] = min(minV[ind * 2], minV[ind * 2 + 1]);
  }
}
void init_(vi& data) {
  n = data.size();
  minV = vi(4 * n);
  lazy = vi(4 * n, 0);
  construct(data, 0, n, 1);
}
void push(int l, int r, int ind) {
  // make lazy[ind] = 0, push it to children.
  if (l + 1 != r) {
    lazy[2 * ind] += lazy[ind];
    lazy[2 * ind + 1] += lazy[ind];
  }
  minV[ind] += lazy[ind];
  lazy[ind] = 0;
}

void update(int l, int r, int ql, int qr, int ind, int x) {
  push(l, r, ind);
  if (ql <= l && r <= qr) {
    lazy[ind] += x;
    push(l, r, ind);
  } else if (r <= ql || qr <= l) {
  } else {
    int mid = (l + r) / 2;
    update(l, mid, ql, qr, ind * 2, x);
    update(mid, r, ql, qr, ind * 2 + 1, x);
    minV[ind] = min(minV[ind * 2], minV[ind * 2 + 1]);
  }
  assert(minV[ind] >= 0);
}
void update_(int ql, int qr, int x) { update(0, n, ql, qr, 1, x); }

int lastZero(int l, int r, int qr, int ind) {
  push(l, r, ind);
  int ans = -1;
  if (minV[ind] == 0) {
    if (l + 1 == r) {
      if (l < qr) {
        assert(minV[ind] == 0);
        ans = l;
      }
    } else {
      int mid = (l + r) / 2;
      if (qr <= mid) {
        ans = lastZero(l, mid, qr, ind * 2);
      } else {
        ans = lastZero(mid, r, qr, ind * 2 + 1);
        if (ans == -1) {
          ans = lastZero(l, mid, qr, ind * 2);
        }
      }
    }
  }
  return ans;
}
int lastZero_(int r) { return lastZero(0, n, r, 1); }

}  // namespace Node

int main() {
#ifdef LOCAL
  ifstream cin("case1.in");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vector<int> b(n / 2);
    vector<int> seen(n);
    for (int i = 0; i < n / 2; i++) {
      cin >> b[i];
      b[i]--;
      seen[b[i]] = true;
    }
    vi prefix_sum(n + 1);
    int seen_count = 0;
    for (int i = 0; i < n; i++) {
      if (seen[i]) {
        seen_count += 1;
        prefix_sum[i + 1] = prefix_sum[i] - 1;
        if (prefix_sum[i + 1] < 0) {
          seen_count = -1;  // impossible
          break;
        }
      } else {
        prefix_sum[i + 1] = prefix_sum[i] + 1;
      }
    }
    if (seen_count != n / 2) {
      cout << -1;
    } else {
      Node::init_(prefix_sum);
      vi a(n / 2);
      rep(i, 0, n / 2) {
        a[i] = Node::lastZero_(b[i] + 1);
        Node::update_(a[i] + 1, b[i], -1);
      }
      cout << (1 + a[0]) << " " << (1 + b[0]);
      rep(i, 1, n / 2) { cout << " " << (a[i] + 1) << " " << (b[i] + 1); }
    }
    cout << "\n";
  }
  return 0;
}
