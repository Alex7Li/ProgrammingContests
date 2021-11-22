# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> nodebad(n, false);
    vector<vi> edge(n);
    vector<vi> color(n);
    vector<vector<int>> bad(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        color[a].push_back(c);
        color[b].push_back(c);
        bad[a].push_back(0);
        bad[b].push_back(0);
    }
    queue<pii> nextEdge;
    for (int i = 0; i < n - 1; ++i) {
        unordered_map<int, int> colors;
        for (int j = 0; j < edge[i].size(); ++j) {
            int c = color[i][j];
            colors[c] += 1;
        }
        for (int j = 0; j < edge[i].size(); ++j) {
            int c = color[i][j];
            if (colors[c] > 1) {
                bad[i][j] = 1;
                nextEdge.push({i, edge[i][j]});
            }
        }
    }
    vector<int> badInDegree(n, 0);
    while (!nextEdge.empty()) {
        pii next = nextEdge.front();
        nextEdge.pop();
        if (badInDegree[next.second] >= 2) {
            continue;
        }
        badInDegree[next.second]++;
        for (int j = 0; j < edge[next.second].size(); j++) {
            int st = next.second;
            int end = edge[next.second][j];
            if (bad[st][j] == 0 && end != next.first) {
                bad[st][j] = 1;
                nextEdge.push({st, end});
            }
        }
    }
    int total = count(badInDegree.begin(), badInDegree.end(), 0);
    cout << total << "\n";
    for (int i = 0; i < n; i++) {
        if (badInDegree[i] == 0) {
            cout << (i + 1) << "\n";
        }
    }
    return 0;
}
