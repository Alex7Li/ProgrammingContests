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

int dip(int start, int color_dip_mask, int equipment_mask) {
  int orig_equip_ind_mask = start & ((1 << 10) - 1);
  int orig_color_mask = start >> 10;
  int after_color = (equipment_mask & orig_color_mask) | \
    ((~equipment_mask) & color_dip_mask);
  return (after_color << 10) | orig_equip_ind_mask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vi color_dips(k);
    rep(i, 0, n) {
      int desired_color;
      cin >> desired_color;
      color_dips[desired_color - 1] |= 1 << i;
    }
    dbg(color_dips[0]);
    vi equipment(m);
    rep(i, 0, m) {
      int n_regions;
      cin >> n_regions;
      rep(j, 0, n_regions) {
        int place;
        cin >> place;
        equipment[i] |= 1 << (place - 1);
      }
    }
    vi states(1 << 20, -1);
    queue<int> S;
    int start = dip(0, color_dips[0], 0);
    S.push(start);
    states[start] = 0;
    int goal_state = ((1 << n) - 1) << 10;
    while(!S.empty()) {
      int from_state = S.front();
      S.pop();
      int dist = states[from_state];
      if(from_state == goal_state) {
        cout << dist;
        return 0;
      }
      int equipment_mask = 0;
      rep(i, 0, m) {
        if((from_state & (1 << i)) != 0){
          equipment_mask |= equipment[i];
        }
      }
      // put on or take off equipment
      rep(i, 0, m) {
        int next_state = from_state ^ (1 << i);
        if(states[next_state] == -1) {
          states[next_state] = dist + 1;
          S.push(next_state);
        }
      }
      // put in bucket
      rep(c, 0, k) {
        int next_state = dip(from_state, color_dips[c], equipment_mask);
        if(states[next_state] == -1) {
          states[next_state] = dist + 1;
          S.push(next_state);
        }
      }
    }
    cout << -1;
    return 0;
}