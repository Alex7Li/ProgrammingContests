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
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      for(int j = 0; j < m; j++){
        if(s[j] == '*'){
          a[i][j] = -1;
        } else if(s[j] == '.') {
          a[i][j] = 0;
        } else {
          a[i][j] = int(s[j] - '0');
        }
      }
    }
    vi dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vi dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vi> b(n, vi(m, 0));
    rep(i, 0, n) {
      rep(j, 0, m) {
        if(a[i][j] == -1) {
          rep(k, 0, dx.size()) {
            int i2 = i + dx[k];
            int j2 = j + dy[k];
            if(0 <= i2 && i2 < n){
              if(0 <= j2 && j2 < m){
                b[i2][j2] += 1;
              }
            }
          }
        }
      }
    }
    rep(i, 0, n) {
      rep(j, 0, m) {
        if(a[i][j] != -1 && (a[i][j] != b[i][j])) {
          cout << "nO\n";
          return 0;
        }
      }
    }
    cout << "yES\n";
    return 0;
}