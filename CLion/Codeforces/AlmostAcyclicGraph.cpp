# include <bits/stdc++.h>
// https://codeforces.com/contest/915/problem/D
using namespace std;

enum State {
    unvisited, visiting, finished
};

int search(int cur, vector<vector<int>> &adjList, vector<State> &seen) {
    if (seen[cur] == visiting) {// found cycle
        return 1;
    } else if (seen[cur] == finished) {
        return 0;
    } else {
        seen[cur] = visiting;
        int backEdges = 0;
        for (int adj : adjList[cur]) {
            backEdges += search(adj, adjList, seen);
        }
        seen[cur] = finished; // we've found all reachable nodes from here
        return backEdges;
    }
}

void topSort(int st, vector<vector<int>> &adjList) {
    int n = adjList.size();
    int backEdges = 0;
    vector<State> seen(n, unvisited);
    for (int i = 0; i < n; i++) {
        int cur = (i + st) % n;
        if (seen[cur] == unvisited) {
            backEdges += search(cur, adjList, seen);
        }
    }
    if (backEdges < 2) {
        cout << "YES" << endl;
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
    }
    for (int st = 0; st < n; st++) {
        topSort(st, adjList);
    }
    cout << "NO" << endl;
    return 0;
}