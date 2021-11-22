# include <bits/stdc++.h>
// https://codeforces.com/gym/102694/problem/A
// Tree diameter *3
using namespace std;

int n;
vector<vector<int>> adj;

pair<int, int> furthest(int from) {
    vector<bool> seen(n, false);
    seen[from] = true;
    queue<pair<int, int>> Q;
    Q.push(make_pair(from, 0));
    auto last = make_pair(from, 0);
    while (!Q.empty()) {
        pair<int, int> next = Q.front();
        Q.pop();
        for (int i = 0; i < adj[next.first].size(); i++) {
            if(!seen[adj[next.first][i]]){
                last = make_pair(adj[next.first][i], next.second + 1);
                Q.push(last);
                seen[adj[next.first][i]] = true;
            }
        }
    }
    return last;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj = vector<vector<int>>(n, vector<int>(0, 0));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int edge = furthest(0).first;
    cout << furthest(edge).second * 3 << "\n";
    return 0;
}