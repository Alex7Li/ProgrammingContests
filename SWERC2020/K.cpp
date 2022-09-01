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
    string s;
    cin >> s;
    int n = s.size();
    map<string, pii> seenT;
    for (int i = 0; i < n; i++){
      string base = "";
      for (int j = 0; i + j < min(n, 13); j++) {
        base += s[i + j];
        string base_cp = base;
        if (seenT.count(base)) {
          seenT[base_cp] = {15, 0};
        } else {
          seenT[base_cp] = {j, i};
        }
      }
    }
    string best = "";
    pii v = pii(15, 0);
    for(auto s: seenT){
      if(s.second < v) {
        v = s.second;
        best = s.first;
      }
    }
    cout << best << "\n";
    return 0;
}