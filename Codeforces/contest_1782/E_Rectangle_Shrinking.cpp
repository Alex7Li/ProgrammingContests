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

struct Interval {
  int l;
  int r;
  int ind;
  bool operator<(Interval& o) {
    if (l == o.l) {
      return r < o.r;
    } else {
      return l < o.l;
    }
  }
};

vector<Interval> filter(vector<Interval>& ints) {
  sort(ints.begin(), ints.end());
  vector<Interval> ok;
  int cur_r = -1;
  rep(i, 0, ints.size()) {
    if (cur_r < ints[i].l) {
      ok.push_back(ints[i]);
    } else {
      if (cur_r < ints[i].r) {
        ok.push_back({cur_r + 1, ints[i].r, ints[i].ind});
      }
    }
    cur_r = max(cur_r, ints[i].r);
  }
  return ok;
}

bool covers(vector<Interval>& ints, int st, int end, int from_ind) {
  if (from_ind == ints.size()) {
    return false;
  }
  int i_st = ints[from_ind].l;
  int i_end = ints[from_ind].r;
  while (from_ind + 1 < ints.size() && i_end < end) {
    from_ind += 1;
    if (ints[from_ind - 1].r + 1 != ints[from_ind].l) {
      return false;
    }
    i_end = ints[from_ind].r;
  }
  return i_st <= st && end <= i_end;
}

vector<Interval> remove(vector<Interval>& ints) {
  vector<Interval> newInts;
  rep(i, 0, ints.size()) {
    if (ints[i].ind != -1) {
      newInts.push_back(ints[i]);
    }
  }
  return newInts;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vector<Interval> top;
    vector<Interval> bot;
    vector<Interval> full;
    rep(i, 0, n) {
      int u, l, d, r;
      cin >> u >> l >> d >> r;
      Interval inte = {l, r, i};
      if (u == d) {
        if (u == 1) {
          top.push_back(inte);
        } else {
          bot.push_back(inte);
        }
      } else {
        full.push_back(inte);
      }
    }
    top = filter(top);
    bot = filter(bot);
    full = filter(full);
    int topInd = 0;
    int botInd = 0;
    vector<Interval> newBot;
    vector<Interval> newTop;
    for (int i = 0; i < full.size(); i++) {
      while (topInd < top.size() && top[topInd].r < full[i].l) {
        topInd++;
      }
      while (botInd < bot.size() && bot[botInd].r < full[i].l) {
        botInd++;
      }
      // if the top is fully covered, move it to the bot
      if (covers(top, full[i].l, full[i].r, topInd)) {
        newBot.push_back({full[i].l, full[i].r, full[i].ind});
        full[i].ind = -1;
      } else if (covers(bot, full[i].l, full[i].r, botInd)) {
        // if the bot is fully covered, move it to the top
        newTop.push_back({full[i].l, full[i].r, full[i].ind});
        full[i].ind = -1;
      } else {
        // otherwise, shorten the top and bot to make it work
        while (topInd < top.size() && top[topInd].l <= full[i].r) {
          if (top[topInd].l < full[i].l) {
            assert(top[topInd].r < full[i].r);
            top[topInd].r = full[i].l - 1;
          } else {
            if (top[topInd].r > full[i].r) {
              assert(top[topInd].l > full[i].l);
              top[topInd].l = full[i].r + 1;
            } else {
              top[topInd].ind = -1;
            }
          }
          topInd++;
        }
        while (botInd < bot.size() && bot[botInd].l <= full[i].r) {
          if (bot[botInd].l < full[i].l) {
            assert(bot[botInd].r < full[i].r);
            bot[botInd].r = full[i].l - 1;
          } else {
            if (bot[botInd].r > full[i].r) {
              assert(bot[botInd].l > full[i].l);
              bot[botInd].l = full[i].r + 1;
            } else {
              bot[botInd].ind = -1;
            }
          }
          botInd++;
        }
        if(topInd != 0){
          topInd--;
        }
        if(botInd != 0){
          botInd--;
        }
      }
    }
    rep(i, 0, newTop.size()) {
      top.push_back(newTop[i]);
    }
    rep(i, 0, newBot.size()) {
      bot.push_back(newBot[i]);
    }
    top = remove(top);
    bot = remove(bot);
    full = remove(full);
    top = filter(top);
    bot = filter(bot);
    vector<vi> ans(n, vi(4, 0));
    ll count = 0;
    for (Interval& x : top) {
      ans[x.ind][0] = 1;
      ans[x.ind][1] = x.l;
      ans[x.ind][2] = 1;
      ans[x.ind][3] = x.r;
      count += x.r - x.l + 1;
    }
    for (Interval& x : bot) {
      ans[x.ind][0] = 2;
      ans[x.ind][1] = x.l;
      ans[x.ind][2] = 2;
      ans[x.ind][3] = x.r;
      count += x.r - x.l + 1;
    }
    for (Interval& x : full) {
      ans[x.ind][0] = 1;
      ans[x.ind][1] = x.l;
      ans[x.ind][2] = 2;
      ans[x.ind][3] = x.r;
      count += (x.r - x.l + 1) * 2;
    }
    cout << count << "\n";
    rep(i, 0, n) {
      cout << ans[i][0];
      rep(j, 1, 4) { cout << " " << ans[i][j]; }
      cout << "\n";
    }
  }
  return 0;
}