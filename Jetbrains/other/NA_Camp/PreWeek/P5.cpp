# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 10000000;
vi solve(int n, int m, vector<string> &grid) {
    vector<vi> cost(n, vi(m, -1));
    priority_queue<tiii> Q;
    for (int i = 0; i < m; ++i) {
        if (grid[0][i] == '#') {
            cost[0][i] = INF;
            Q.push({INF, 0, i});
        }
    }
    vector<vector<bool>> done(n, vector<bool>(m, false));
    while (!Q.empty()) {
        tiii x = Q.top();
        Q.pop();
        int c = get<0>(x);
        int row = get<1>(x);
        int col = get<2>(x);
        if (done[row][col]) {
            continue;
        }
        done[row][col] = true;
        // go right
        for (int ncol = col + 1; ncol != m; ncol++) {
            if (grid[row][ncol] == '#') {
                int d = ncol - col - 1;
                if (d == 0) { d = INF; }
                cost[row][ncol] = max(cost[row][ncol], min(d, c));
                Q.push({cost[row][ncol], row, ncol});
                break;
            }
        }
        // go left
        for (int ncol = col - 1; ncol != -1; ncol--) {
            if (grid[row][ncol] == '#') {
                int d = col - ncol - 1;
                if (d == 0) { d = INF; }
                cost[row][ncol] = max(cost[row][ncol], min(d, c));
                Q.push({cost[row][ncol], row, ncol});
                break;
            }
        }
        // go down
        for (int nrow = row + 1; nrow != n; nrow++) {
            if (grid[nrow][col] == '#') {
                int d = nrow - row - 1;
                if (d == 0) { d = INF; }
                cost[nrow][col] = max(cost[nrow][col], min(d, c));
                Q.push({cost[nrow][col], nrow, col});
                break;
            }
        }
        // go up
        for (int nrow = row - 1; nrow != -1; nrow--) {
            if (grid[nrow][col] == '#') {
                int d = row - nrow - 1;
                if (d == 0) { d = INF; }
                cost[nrow][col] = max(cost[nrow][col], min(d, c));
                Q.push({cost[nrow][col], nrow, col});
                break;
            }
        }
    }
    vi costRow(m);
    for (int i = 0; i < m; ++i) {
        int c = cost[n - 1][i];
        costRow[i] = (c == INF) ? 0 : c;
    }
    return costRow;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vi ans = solve(n, m, grid);
    cout << ans[0];
    for (int i = 1; i < m; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}