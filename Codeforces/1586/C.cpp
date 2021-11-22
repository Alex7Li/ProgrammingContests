# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
      cin >> grid[i];
    }
    set<int> bad;
    bad.insert(m + 1);
    for(int i = 0; i + 1 < n; i++){
      for(int j = 1; j < m; j++) {
        if(grid[i][j]=='X' && grid[i + 1][j - 1]=='X'){
          bad.insert(j - 1);
        }
      }
    }
    int q;
    cin >> q;
    for(int t = 0; t < q; t++) {
        int l, h;
        cin >> l >> h;
        l--;
        h--;
        int x = *bad.lower_bound(l);
        if(x < h) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
        }
    }

    return 0;
}