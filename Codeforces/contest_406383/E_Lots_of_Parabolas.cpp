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
typedef __float128 ld;
typedef vector<long double> vd;
#define inf 1e30
#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

ld evaluate_parab(ld a, ld b, ld c, ld x) {
  return (a * x + b) * x + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vd a(n);
    vd b(n);
    vd c(n);
    rep(i, 0, n){
      long double av, bv, cv;
      cin >> av >> bv >> cv;
      a[i] = av;
      b[i] = bv;
      c[i] = cv;
    }
    bool flip = a[0] < 0;
    if(flip) {
      rep(i, 0, n) {
          a[i] *= -1;
          b[i] *= -1;
          c[i] *= -1;
      }
    }
    // Choose the upwards parabola with the highest minimum,
    // let that be the 0th parabola
    ld best_x_0 = -b[0] / (2 * a[0]);
    ld best_min_y = evaluate_parab(a[0], b[0], c[0], best_x_0);
    rep(i, 0, n){
      if(a[i] > 0){
        ld best_x = -b[i] / (2 * a[i]);
        ld min_y = evaluate_parab(a[i], b[i], c[i], best_x);
        if(min_y > best_min_y) {
          if(i != 0){
            swap(a[0], a[i]);
            swap(b[0], b[i]);
            swap(c[0], c[i]);
          }
          best_min_y = min_y;
        }
      }
    }
    ld l_x = -inf;
    ld r_x = inf;
    rep(i, 1, n) {
      ld da = a[0] - a[i];
      ld db = b[0] - b[i];
      ld dc = c[0] - c[i];
      if(abs((long double)da) < 1e-1) {
        ld first_x_loc = -b[0] / (2 * a[0]);
        ld new_x_loc = -b[i] / (2 * a[i]);
        if(abs((long double)db) > 1e-1) {
          ld solution_x = -dc / db;
          if(new_x_loc > first_x_loc) {
            l_x = max(l_x, solution_x);
          } else {
            r_x = min(r_x, solution_x);
          }
        }
      } else {
        long double discriminant = db * db - 4 * da * dc;
        if(discriminant < 1e-1) {
          assert(a[i] >= 1e-1);
          // No solutions
          continue;
        } else if(discriminant > 1e-1) {
          ld offset = sqrt(discriminant);
          // Two solutions
          l_x = max(l_x, (-db - offset) / (2 * da));
          r_x = min(r_x, (-db + offset) / (2 * da));
        } else {
          //(discriminant == 0) {
          // One solution
          assert(a[i] <= -1e-1);
          ld solution_x = -db / (2 * da);
          l_x = solution_x;
          r_x = solution_x;
          break;
        }
      }
    }
    // assert(l_x <= r_x + 1e-1);
    ld ans_x = (l_x + r_x) / 2;
    ld ans_y = evaluate_parab(a[0], b[0], c[0], ans_x);
    if (flip) {
      ans_y *= -1;
    }
    cout << fixed << setprecision(69);
    // printf("%.8lld %.8lld\n", ans_x, ans_y);
    cout << ((long double)ans_x) << " " << ((long double)ans_y) << "\n";
    return 0;
}
