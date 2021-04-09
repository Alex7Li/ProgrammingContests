# include <bits/stdc++.h>
// This is just for practice, I am copying/cleaning the Reference solution at
// https://codeforces.com/problemset/submission/1427/95156412
// https://codeforces.com/problemset/problem/1427/G
// it's too hard for me to solve without help but I wanna learn flow :P
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const vi dir = {0, 1, 0, -1};

bool dfs(int x, int y, vector<vector<bool>> &isGoal,
         vector<vector<bool>> &visited,
         vector<vector<vector<bool>>> &available, bool toSource) {
    visited[x][y] = true;
    if (isGoal[x][y]) {
        // yay, we found a path to the goal
        return true;
    }
    rep(t, 0, 4) {
        if (!available[x][y][t]) {
            continue;
        }
        int x1 = x + dir[t];
        int y1 = y + dir[t ^ 1];
        // If going to a source,we only want to get rid of paths with flow already
        if (toSource && available[x1][y1][t ^ 2]) { continue; }
        if (visited[x1][y1]) { continue; }
        // If we can get to the goal from this path
        if (dfs(x1, y1, isGoal, visited, available, toSource)) {
            // Then mark this whole path as seen
            if (available[x1][y1][t ^ 2]) { available[x][y][t] = false; }
                // if we are going backwards, undo marking stuff as seen
            else { available[x1][y1][t ^ 2] = true; }
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vi> vals(N, vi(N));
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> vals[i][j];
        }
    }
    vector<pii> tiles;
    vector<vector<bool>> sinks(N, vector<bool>(N, false));
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (vals[i][j] >= 1) {
                tiles.push_back(pii(i, j));
                sinks[i][j] = true;
            }
        }
    }
    // edges in the flow graph
    vector<vector<vector<bool>>> available(N, vector<vector<bool>>
            (N, (vector<bool>(4, false))));

    // Set up the flow graph
    rep(x, 0, N) {
        rep(y, 0, N) {
            if (vals[x][y] != -1) {
                rep(d, 0, 4) {
                    int x1 = x + dir[d];
                    int y1 = y + dir[d ^ 1];
                    if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= N) {
                        continue;
                    }
                    if (vals[x1][y1] == -1) {
                        continue;
                    }
                    available[x][y][d] = true;
                }
            }
        }
    }
    sort(tiles.begin(), tiles.end(), [&](pii A, pii B) {
        return vals[A.first][A.second] < vals[B.first][B.second];
    });

    ll res = 0;
    int flow = 0;

    vector<vector<bool>> sources(N, vector<bool>(N, false));
    vector<vector<bool>> visited;
    rep(it, 0, tiles.size() - 1) {
        int x = tiles[it].first, y = tiles[it].second;
        // Remove any flow that ends with this tile, as it is
        // about to transform from a sink into a source.
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        while (dfs(x, y, sources, visited, available, true)) {
            visited = vector<vector<bool>>(N, vector<bool>(N, false));
            flow--;
        }
        // Let's find the flow from all tiles with cost at least vals[x][y] to
        // tiles with cost more than vals[x][y].
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        sinks[x][y] = false;
        sources[x][y] = true;
        for (auto pp: tiles) {
            int i = pp.first, j = pp.second;
            // Look for new augmenting paths from each source to a sink.
            // No point in checking sources that we visited already, so the second condition
            // is just a speedup
            if (sources[i][j] && !visited[i][j]) {
                while (dfs(i, j, sinks, visited, available, false)) {
                    visited = vector<vector<bool>>(N, vector<bool>(N, false));
                    flow++;
                }
            }
        }

        // How much extra cost does adding this tile give vs next tile
        ll cost = vals[tiles[it + 1].first][tiles[it + 1].second] - vals[x][y];
        // multiply by the amount of flow going through.
        res += cost * flow;
    }
    cout << res << endl;
    return 0;
}