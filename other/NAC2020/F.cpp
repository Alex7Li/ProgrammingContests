# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int inf =100000000 ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int k;
    cin >> n >> k;
    vvi a(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vvi val(n, vi(n, inf));
    for (int kk = 1; kk <= k; ++kk) {
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (a[row][col] == kk) {
                    if (kk == 1) {
                        val[row][col] = 0;
                    } else {
                        for (int row2 = 0; row2 < n; ++row2) {
                            for (int col2 = 0; col2 < n; ++col2) {
                                if (a[row2][col2] == kk - 1) {
                                    val[row][col] = min(
                                            val[row2][col2] + abs(row - row2) + abs(col - col2),
                                            val[row][col]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int best = inf;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if(a[row][col]==k){
                best = min(best, val[row][col]);
            }
        }
    }
    cout << (best==inf? -1:best) << endl;
    return 0;
}