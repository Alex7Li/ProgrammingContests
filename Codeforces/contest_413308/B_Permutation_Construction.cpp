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
typedef pair<pair<int, int>, int> piii;
typedef vector<int> vi;

#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

vi topoSort(const vector<vi>& gr) {
  vi indeg(gr.size()), ret;
  for (auto& li : gr) for (int x : li) indeg[x]++;
  queue<int> q; // use priority queue for l e x i c . l a r g e s t ans .
  rep(i,0,gr.size()) if (indeg[i] == 0) q.push(i);
  while (!q.empty()) {
  int i = q.front(); // top () for priority queue
  ret.push_back(i);
  q.pop();
  for (int x : gr[i])
  if (--indeg[x] == 0) q.push(x);
  }
  return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<piii> intervals(q);
    rep(i, 0, q) {
      cin >> intervals[i].first.first >> intervals[i].first.second >> intervals[i].second;
      intervals[i].first.first -= 1;
    }
    sort(intervals.begin(), intervals.end());
    vector<vi> constraints(n);
    int current_st = n;
    int current_end = 0;
    int last_minV = -1;
    for(piii interval: intervals){
      int start = interval.first.first;
      int end = interval.first.second;
      int minV = interval.second;
      dbg(start);
      dbg(end);
      if(end <= current_end) {
        continue; // This interval is contained in another
      } else {
        for(int i = current_end; i < end; i++){
          constraints[minV].push_back(i);
        }
        for(int i = current_st; i < start; i++){
          constraints[last_minV].push_back(i);
        }
      }
      current_end = end;
      current_st = start;
      last_minV = minV;
    }
    vi order = topoSort(constraints);
    cout << order[0];
    rep(i, 1, n){
      cout << " " << order[i] + 1; // might be inverted
    }

    return 0;
}