# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int distSq(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int dijkstra(vector<vector<int>> &edges, int start, int end) {
    vector<int> distances(edges.size(), 5000);
    // (-d, x) means the distance to node x is d.
    priority_queue<pii> q;
    distances[start] = 0;
    q.push({0, start});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (distances[a] != 5000) {
            for (auto e: edges[a]) {
                if (distances[a] + 1 < distances[e]) {
                    distances[e] = distances[a] + 1;
                    q.push({-distances[e], e});
                }
            }
        }
    }
    return distances[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, f;
    cin >> a >> f;
    int l, w;
    cin >> l >> w;
    vector<int> x(0);
    vector<int> y(0);
    int start;
    int end;
    rep(i, 0, l) {
        string grid;
        cin >> grid;
        rep(j, 0, w) {
            if (grid[j] != 'B') {
                if (grid[j] == 'S') {
                    start = x.size();
                }
                if (grid[j] == 'G') {
                    end = x.size();
                }
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    vector<vector<int>> edgesElsa(x.size());
    vector<vector<int>> edgesFather(x.size());
    for (int i = 0; i < x.size(); i++) {
        rep(j, i+1, x.size()) {
            int ds = distSq(x[i], y[i], x[j], y[j]);
            if (ds <= a * a) {
                edgesElsa[i].push_back(j);
                edgesElsa[j].push_back(i);
            }
            if (ds <= f * f && (x[i] == x[j] || y[i] == y[j])) {
                edgesFather[i].push_back(j);
                edgesFather[j].push_back(i);
            }
        }
    }
    int distE = dijkstra(edgesElsa, start, end);
    int distF = dijkstra(edgesFather, start, end);
    if (distE == 5000 && distF == 5000) {
        cout << "NO WAY";
    } else if (distE == distF) {
        cout << "SUCCESS";
    } else if (distE < distF) {
        cout << "GO FOR IT";
    } else if (distE > distF) {
        cout << "NO CHANCE";
    }
    return 0;
}