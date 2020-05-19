# include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<bool> seen;

void dfs(int st) {
    seen[st] = true;
    for (int i : edges[st]) {
        if (!seen[i]) {
            dfs(i);
        }
    }
}

bool solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> seg = vector<pair<int, int>>(n, pair<int, int>(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }
    sort(seg.begin(), seg.end());
    edges = vector<vector<int>>(n, vector<int>(0, 1));
    // location on line, index
    auto comparator = [](pair<int, int> a, pair<int, int> b) { return a < b; };
    set<pair<int, int>, decltype(comparator)> endpoints(comparator);
    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        int nxtStart = seg[i].first;
        while (endpoints.size() > 0 && (*endpoints.begin()).first < nxtStart) {
            endpoints.erase((*endpoints.begin()));
        }
        endpoints.insert(pair<int, int>(seg[i].second, i));
        for (auto e = endpoints.begin(); e->first < seg[i].second; e++) {
            edges[e->second].push_back(i);
            edges[i].push_back(e->second);
            if (++edgeCount == n) {
                return 0;
            }
        }
    }
    seen = vector<bool>(n, false);
    dfs(0);
    return all_of(seen.begin(), seen.end(), [](bool b) { return b; });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (solve()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}