# include <bits/stdc++.h>

using namespace std;

vector<int> seenOrder;

void dfs(int st, vector<vector<int>>& edges, vector<bool>& seen) {
    seen[st] = true;
    for (int i = 0; i < edges[st].size(); i++) {
        if (!seen[edges[st][i]]) {
            dfs(edges[st][i], edges, seen);
        }
    }
    seenOrder.push_back(st);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(0));
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                edges[i].push_back(j);
            }
        }
    }
    vector<bool> seen(n, false);
    dfs(0, edges, seen);
    if (seenOrder.size() == n) {
        for (int i = 0; i < seenOrder.size(); i++) {
            cout << seenOrder[i] << " ";
        }
    } else {
        cout << "impossible";
    }
    return 0;
}