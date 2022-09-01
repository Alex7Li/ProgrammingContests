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
    vector<double> a(n);
    vector<bool> skip(n, false);
    ll S = 0;
    rep(i, 0, n){
      cin >> a[i];
      if(ceil(a[i]) == floor(a[i])) {
        skip[i] = true;
      }
      a[i] = floor(a[i]);
      S += int(a[i]);
    }
    rep(i, 0, n){
      if(S < 0 && !skip[i]){
        a[i] += 1;
        S += 1;
      }
    }
    rep(i, 0, n){
      cout << int(a[i]) << "\n";
    }
    return 0;
}