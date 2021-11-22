# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<bool> vb;

bool solve(int c1, int c2, int c3, set<int>&b, int d) {
    vector<vector<vb>> dp(d + 5, vector<vb>(c2 + 1, vb(c3 + 1)));
    dp[0][c2][c3] = true;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            for (int k = 0; k < dp[i][j].size(); ++k) {
                if(dp[i][j][k] > 0){
                    if(j > 0 && b.find(i + 2) == b.end()) {
                        dp[i + 2][j - 1][k] = true;
                    }
                    if(k > 0 && b.find(i + 3) == b.end()){
                        dp[i + 3][j][k - 1] = true;
                    }
                    if(b.find(i + 1) == b.end()){
                        int size1used = i - (c2 - j) * 2 - (c3 - k) * 3;
                        int size1left = c1 - size1used;
                        if(size1left > 0){
                            dp[i + 1][j][k] = true;
                        }
                    }
                }
            }
        }
    }
    bool pos = false;
    for (int i = 0; i < dp[d].size(); ++i) {
        for(int j = 0; j < dp[d][i].size(); j++){
            if(dp[d][i][j]){
                pos = true;
            }
        }
    }
    return pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int c1, c2, c3;
    cin >> n >> c1 >> c2 >> c3;
    int d = 0;
    set<int> b;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        d += v;
        if (i != n - 1) {
            b.insert(d);
        }
    }
    if (solve(c1, c2, c3, b, d)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}