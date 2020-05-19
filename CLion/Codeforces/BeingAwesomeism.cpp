# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1280/B
using namespace std;

int resolve(bool all, bool some, bool onEdge) {
    if (all) {
        if (onEdge) {
            return 1;
        } else {
            return 2;
        }
    } else if (some && onEdge) {
        return 3;
    } else {
        return 4;
    }
}

int checkRow(vector<vector<bool>> &grid, int r, int c, bool onEdge) {
    bool all = true;
    bool some = false;
    for (int i = 0; i < c; i++) {
        if (grid[r][i]) {
            some = true;
        } else {
            all = false;
        }
    }
    return resolve(all, some, onEdge);
};

int checkCol(vector<vector<bool>> &grid, int r, int c, bool onEdge) {
    bool all = true;
    bool some = false;
    for (int i = 0; i < r; i++) {
        if (grid[i][c]) {
            some = true;
        } else {
            all = false;
        }
    }
    return resolve(all, some, onEdge);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    for (int t = 0; t < cases; t++) {
        int r, c;
        cin >> r >> c;
        vector<vector<bool>> grid;
        bool hasA = false;
        bool hasP = false;
        for (int i = 0; i < r; i++) {
            vector<bool> v;
            grid.push_back(v);
            for (int j = 0; j < c; j++) {
                char x;
                cin >> x;
                grid[i].push_back(x == 'A');
                hasA |= x == 'A';
                hasP |= x == 'P';
            }
        }
        if (!hasA) {
            cout << "MORTAL" << "\n";
        } else if (!hasP) {
            cout << 0 << "\n";
        } else {
            int best = 4;
            if (grid[0][0] || grid[0][c - 1] || grid[r - 1][0] || grid[r - 1][c - 1]) {
                best = 2;
            }
            best = min(best, checkCol(grid, r, c - 1, true));
            for (int i = 1; i < c - 1; i++) {
                best = min(best, checkCol(grid, r, i, false));
            }
            best = min(best, checkCol(grid, r, 0, true));
            best = min(best, checkRow(grid, r - 1, c, true));
            for (int i = 1; i < r - 1; i++) {
                best = min(best, checkRow(grid, i, c, false));
            }
            best = min(best, checkRow(grid, 0, c, true));
            cout << best << "\n";
        }
    }

    return 0;
}