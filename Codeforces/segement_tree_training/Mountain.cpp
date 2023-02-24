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

struct LazySparseSegTree;
LazySparseSegTree *nodes;
int memInd = 0;
struct LazySparseSegTree {
  int left;
  int right;
  int slope;
  // Must set to 0 for some reason
  int range_sum=0;
  int max_sum=0;
  int lchild=0;
  int rchild=0;
  bool need_push=false;
  
  LazySparseSegTree(){}
  LazySparseSegTree(int l, int r, int s) : left(l), right(r), slope(s) {
    need_push = left + 1 < right;
    lchild=rchild=range_sum=max_sum=0;
  };
  void merge() {
    range_sum = nodes[lchild].range_sum + nodes[rchild].range_sum;
    max_sum = max(nodes[lchild].max_sum, nodes[lchild].range_sum + nodes[rchild].max_sum);
  }
  void update(int new_slope) {
    slope = new_slope;
    range_sum = slope * (right - left);
    max_sum = max(0, range_sum);
    need_push = left + 1 < right; // must push further, except leaf nodes.
  }
  void push() {
    if(need_push) {
      need_push = false;
      int mid = (left + right) / 2;
      if(!lchild) nodes[lchild = ++memInd] = {left, mid, slope};
      if(!rchild) nodes[rchild = ++memInd] = {mid, right,  slope};
      nodes[lchild].update(slope);
      nodes[rchild].update(slope);
    }
  }
  void set_range(int l, int r, int new_slope) {
    if(right <= l || r <= left) {
      return;
    }
    if(l <= left && right <= r) {
      update(new_slope);
      // Note you do not need to push here
    } else {
      push();
      nodes[lchild].set_range(l, r, new_slope);
      nodes[rchild].set_range(l, r, new_slope);
      merge();
    }
  }
  int distance(int H) {
    if(max_sum <= H) {
      return right;
    } else {
      if(!lchild) {
        if(slope <= 0) {
          return right;
        }
        return min(right, left + H / slope);
      } else {
        push();
        if(nodes[lchild].max_sum <= H){
          return nodes[rchild].distance(H - nodes[lchild].range_sum);
        } else {
          return nodes[lchild].distance(H);
        }
      }
    }
  }
};
LazySparseSegTree mem[5 << 20];

// https://dmoj.ca/problem/ioi05p3
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nodes = mem;
    int n;
    cin >> n;
    LazySparseSegTree root(0, n, 0);
    char c;
    while(c != 'E') {
      cin >> c;
      if(c == 'Q') {
        int H;
        cin >> H;
        cout << root.distance(H) << "\n";
      } else if(c == 'I') {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        root.set_range(l, r, x);
      }
    }
    return 0;
}
