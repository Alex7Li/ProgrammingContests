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
    int r, c;
    cin >> r >> c;
    vi rM(c);
    vi cM(r);
    vector<vi> G(r, vi(c));
    rep(i, 0, r) {
      rep(j, 0, c) {
        cin >> G[i][j];
      }
    }

    rep(i, 0, r) {
      cM[i] = G[i][0];
      rep(j, 0, c) {
        cM[i] = min(cM[i], G[i][j]);
      }
    }
    rep(i, 0, c) {
      rM[i] = G[0][i];
      rep(j, 0, r) {
        rM[i] = min(rM[i], G[j][i]);
      }
    }
    int co = 0;
    rep(i, 0, r){
      rep(j, 0, c) {
        if(G[i][j] == min(cM[i], rM[j])){
          co+=1;
        }
      }
    }
    cout << co << endl;
    return 0;
}