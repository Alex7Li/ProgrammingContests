# include <bits/stdc++.h>
// http://codeforces.com/problemset/problem/1385/F
using namespace std;

int n, k;
vector<vector<int>> graph;
vector<bool> removed;
int lastDfsStart;

/**
 * @return True iff a node can be removed.
 */
bool dfs(int from, int start) {
    vector<int> removable;
    vector<int> notRemovable;
    for (int next : graph[start]) {
        if (next != from && !removed[next]) {
            if (dfs(start, next)) {
                removable.push_back(next);
            } else {
                notRemovable.push_back(next);
            }
        }
    }
    int numRemoved = removable.size() - removable.size() % k;
    for (int i = 0; i < numRemoved; i++) {
        assert(!removed[removable[i]]);
        removed[removable[i]] = true;
    }
    // Edge case for removing the root. Only when there is
    // 1 node left that we can't remove.
    if (from == -1 && removable.size() % k == 0 && notRemovable.size() == 1
        && lastDfsStart != notRemovable[0]) {
        lastDfsStart = notRemovable[0];
        dfs(-1, notRemovable[0]);
    }
    return notRemovable.size() == 0 && removable.size() % k == 0;
}


int solve() {
    cin >> n >> k;
    graph = vector<vector<int>>(n, vector<int>());
    removed = vector<bool>(n, false);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if (k == 1) {
        return n - 1;
    }
    lastDfsStart = 0;
    dfs(-1, 0);
    int removeCount = accumulate(removed.begin(), removed.end(), 0,
                                 [](int count, bool wasRemoved) { return count += wasRemoved; });
    return removeCount / k;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << solve() << "\n";
    }
    return 0;
}