#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    vii a(n);
    rep(i, 0, n){
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    vi ans(n);
    queue<pii> last_times;
    queue<int> free_times;
    free_times.push(1);
    int max_size = 1;
    rep(i, 0, n){
      int t = a[i].first;
      int free_time = 0;
      while(!last_times.empty() && last_times.front().first + d < t){
        free_times.push(last_times.front().second);
        last_times.pop();
      }
      if (free_times.empty()){
        max_size = last_times.size() + 1;
        free_times.push(max_size);
      }
      ans[a[i].second] = free_times.front();
      last_times.push({t, free_times.front()});
      free_times.pop();
    }
    std::cout << max_size << "\n";
    std::cout << ans[0];
    rep(i, 1, n){
      std::cout << " " << ans[i];
    }
    std::cout << "\n";
    return 0;
}