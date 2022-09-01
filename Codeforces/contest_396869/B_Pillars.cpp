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
    vector<int> a(n);
    rep(i, 0, n){
      cin >> a[i];
    }
    vector<bool> ok(n);
    int l = 0;
    int r = n - 1;
    int loc = 1;
    while(l != r){
      if(a[l] == loc){
        l += 1;
      } else if(a[r] == loc){
        r -= 1;
      } else {
        cout << "NO\n";
        return 0;
      }
      loc += 1;
    }
    cout << "YES\n";

    return 0;
}