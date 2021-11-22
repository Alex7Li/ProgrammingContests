# include <bits/stdc++.h>

using namespace std;

bool hasPath(vector<vector<pair<int, bool>>> &edges, int s, int t) {
    vector<bool> seen(edges.size(), false);
    seen[s] = true;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto &w: edges[v]) {
            if (w.second && !seen[w.first]) {
                seen[w.first] = true;
                Q.push(w.first);
            }
        }
    }
    return seen[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    vector<vector<pair<int, bool>>> edges(n);
    // time, edgeSt, edgeEndInd
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edges[--a].push_back({--b, false});
        events.emplace_back(c, a, edges[a].size() - 1);
        events.emplace_back(d + 1, a, edges[a].size() - 1);
    }
    int score = 0;
    int t1 = 0;
    sort(events.begin(), events.end());
    for (auto e:events) {
        int time = get<0>(e);
        if (time != t1) {
            if (hasPath(edges, s, t)) {
                score += time - t1;
                /*   for (int i = t1; i < time; ++i) {
                       cerr << i << " ";
                   }
                   cerr << "\n";*/
            }
            t1 = time;
        }
//        cerr << "Flip " << get<1>(e) << " -> "<< edges[get<1>(e)][get<2>(e)].first << " " << time << "\n";
        edges[get<1>(e)][get<2>(e)].second ^= true;
    }
    cout << score << "\n";
    return 0;
}
