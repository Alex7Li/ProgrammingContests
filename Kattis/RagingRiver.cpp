# include <bits/stdc++.h>
//https://open.kattis.com/problems/ragingriver
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int augment(vector<vi> &edges, vector<int> &path) {
    int len = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int from = path[i];
        int to = path[i + 1];
        len += edges[from][to];
        if (edges[from][to] == -1) {
            edges[from][to] = 1;
            edges[to][from] = 1;
        } else {
            edges[from][to] = 20000;
            edges[to][from] = -1;
        }
    }
    return len;
}

vector<int> path(vector<vi> &edges, vector<pii> edgeList, int start, int end) {
    vi dist = vi(edges.size(), 20000);
    vi prev = vi(edges.size(), start);
    dist[start] = 0;
    for (int i = 0; i < edges.size(); i++) {
        for (pii p: edgeList) {
            int a = p.first;
            int b = p.second;
            if (dist[b] > dist[a] + edges[a][b]) {
                dist[b] = dist[a] + edges[a][b];
                prev[b] = a;
            }
        }
    }
    if (dist[start] < 0) {
        throw "cycle";
    }
    vector<int> path(1, end);
    int cur = end;
    while (cur != start) {
        cur = prev[cur];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, r, l;
    cin >> p >> r >> l;
    vector<vector<int>> edges(r + 2, vi(r + 2, 20000));
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        a += 2;
        b += 2;
        edgeList.push_back(pii(a, b));
        edgeList.push_back(pii(b, a));
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    int time = 0;
    for (int i = 0; i < p; i++) {
        vector<int> pa = path(edges, edgeList, 0, 1);
        time += augment(edges, pa);
        if (time >= 10000) {
            cout << p - i << " people left behind\n";
            return 0;
        }
    }
    cout << time << "\n";
    return 0;
}