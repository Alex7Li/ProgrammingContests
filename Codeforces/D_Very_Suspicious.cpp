#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    vi scores(1, 0);
    for(int n=1; scores[scores.size() - 1] <= 1e9; n++) {
      int a = n / 3;
      int b = (n + 1) / 3;
      int c = (n + 2) / 3;
      scores.push_back(2 * (a * b + a * c + b * c));
   }
   for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    int lo = 0;
    for(int step = 1 << 30; step !=0; step /= 2) {
      if(lo + step < scores.size() && scores[lo + step] < n) {
        lo += step;
      }
    }
    cout << lo + 1 << "\n";
   }
    return 0;
}