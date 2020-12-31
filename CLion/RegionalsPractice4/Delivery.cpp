# include <bits/stdc++.h>

using namespace std;
#define INF 1'000'000'000
#define SIZE 6
#define NLOCS (SIZE * 2 + 1) * (SIZE * 2 + 1) * 4
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef pair<int, int> pii;

int toInd(int x, int y, int dirInd) {
    return (x + SIZE) + (y + SIZE) * (SIZE * 2 + 1) + dirInd * (SIZE * 2 + 1) * (SIZE * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, r, l, b, n;
    cin >> b >> s >> r >> l >> n;

    // setup graph
    vector<vector<int>> adj(NLOCS, vector<int>(NLOCS));
    vector<pii> dirs = {pii(0, 1), pii(1, 0), pii(0, -1), pii(-1, 0)};
    for (int x1 = -SIZE; x1 <= SIZE; x1++) {
        for (int y1 = -SIZE; y1 <= SIZE; y1++) {
            rep(dir1Ind, 0, 4) {
                for (int x2 = -SIZE; x2 <= SIZE; x2++) {
                    for (int y2 = -SIZE; y2 <= SIZE; y2++) {
                        rep(dir2Ind, 0, 4) {
                            int cost = INF; // INF > the length of any path
                            pii dir1 = dirs[dir1Ind];
                            pii dir1R = dirs[(dir1Ind + 1) % 4];
                            pii dir1L = dirs[(dir1Ind + 3) % 4];
                            if (x1 == x2 && y1 == y2 && dir1Ind == dir2Ind) {
                                cost = 0;
                            } else if (x1 + dir1.first == x2 &&
                                       y1 + dir1.second == y2 && dir1Ind == dir2Ind) {
                                cost = s + b;
                            } else if (x1 + dir1R.first == x2 &&
                                       y1 + dir1R.second == y2 && (dir1Ind + 1) % 4 == dir2Ind) {
                                cost = r + b;
                            } else if (x1 + dir1L.first == x2 &&
                                       y1 + dir1L.second == y2 && (dir1Ind + 3) % 4 == dir2Ind) {
                                cost = l + b;
                            }
                            int ind1 = toInd(x1, y1, dir1Ind);
                            int ind2 = toInd(x2, y2, dir2Ind);
                            adj[ind1][ind2] = cost;
                        }
                    }
                }
            }
        }
    }

    // All pairs shortest path
    rep(k, 0, NLOCS) {
        rep(i, 0, NLOCS) {
            rep(j, 0, NLOCS) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    vector<int> x(n + 1, 0);
    vector<int> y(n + 1, 0);
    vector<int> best(4, 0);

    rep(i, 0, n) {
        vector<int> newBest(4, INF); // INF > the length of any path times n
        cin >> x[i + 1] >> y[i + 1];
        rep(oldDirInd, 0, 4) {
            rep(dirInd, 0, 4) {
                int ind1 = toInd(x[i], y[i], oldDirInd);
                int ind2 = toInd(x[i + 1], y[i + 1], dirInd);
                int d = adj[ind1][ind2];
                newBest[dirInd] = min(newBest[dirInd], best[oldDirInd] + d);
            }
        }
        best = newBest;
    }

    int ans = min(min(best[0], best[1]), min(best[2], best[3]));
    cout << ans;
    return 0;
}
