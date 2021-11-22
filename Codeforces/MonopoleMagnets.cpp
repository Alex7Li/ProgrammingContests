# include <bits/stdc++.h>
//http://codeforces.com/problemset/problem/1344/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool hMark = false;
bool vMark = false;

int check(vector<vector<bool>> &b, bool h) {
    int lastSt = b[0].size();
    int lastEnd = -1;
    int count = 0;
    for (int i = 0; i < b.size(); i++) {
        int st = b[0].size();
        int end = -1;
        for (int j = 0; j < b[i].size(); j++) {
            if (b[i][j]) {
                if (st == b[0].size()) {
                    st = j;
                } else if (j != end) {
                    return -1;
                }
                end = j + 1;
            }
        }
        if (end == -1) {
            if (h) {
                hMark = true;
            } else {
                vMark = true;
            }
        } else {
            if (st >= lastEnd || end <= lastSt) {
                count++;
            }
        }
        lastSt = st;
        lastEnd = end;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    vector<vector<bool>> gridT(m, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == '#') {
                grid[i][j] = true;
                gridT[j][i] = true;
            }
        }
    }
    int g1 = check(grid, true);
    int g2 = check(gridT, false);
    if (hMark ^ vMark) {
        cout << -1;
    } else if (g1 == -1 || g2 == -1) {
        cout << -1;
    } else {
        cout << g1;
    }
    cout << endl;
    return 0;
}