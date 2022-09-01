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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 2; i <= 200; i++){
      int count = 0;
      vi seenT(201);
      int lastT = 0;
      for(int j = 0; j < n; j++){
        if(i - a[j] >= 0 && seenT[i - a[j]] > lastT) {
          lastT = j + 1;
          count += 1;
        }
        seenT[a[j]] = j + 1;
      }
      ans = max(ans, count);
    }
    cout << ans * 2 << endl;
    return 0;
}