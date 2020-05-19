# include <bits/stdc++.h>

//http://codeforces.com/contest/1340/problem/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<int> nodes;
vector<vector<pii>> edges;
vector<vector<int>> timeSeen;

struct Visit {
    int node;
    int time;
    int reds;
};

struct Comparison {
    bool operator()(const Visit &a, const Visit &b) const {
        return b.reds < a.reds;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    nodes = vector<int>(m + 1);
    edges = vector<vector<pii>>(m);
    for (int i = 0; i < m; i++) {
        cin >> nodes[i];
    }
    nodes[m] = 100'000'000;
    int g, r;
    cin >> g >> r;
    // reds seen at the ith node at the jth time
    timeSeen = vector<vector<int>>(m, vector<int>(g + 1, -1));
    sort(nodes.begin(), nodes.end());
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; nodes[j] - nodes[i] <= g && j < i + 2; j++) {
            edges[i].push_back(pii(j, nodes[j] - nodes[i]));
            edges[j].push_back(pii(i, nodes[j] - nodes[i]));
        }
    }
    // priority_queue<Visit, vector<Visit>, Comparison> Q;
    deque<Visit> Q;
    Q.push_back({0, 0, 0});
    while (!Q.empty()) {
        Visit v = Q.front();
        // cout << v.node << " " << v.time << " " << v.reds << "\n";
        Q.pop_front();
        for (pii next: edges[v.node]) {
            if (next.second + v.time > g) {
                continue;
            }
            Visit w = {next.first, next.second + v.time, v.reds};
            if (timeSeen[w.node][w.time] == -1) {
                timeSeen[w.node][w.time] = w.reds;
                Q.push_front(w);
            }
            if (next.second + v.time == g) {
                w = {next.first, 0, v.reds + 1};
                if (timeSeen[w.node][w.time] == -1) {
                    timeSeen[w.node][w.time] = w.reds;
                    Q.push_back(w);
                }
            }
        }
    }
    vector<int> vec = timeSeen[m - 1];
    int fastest = 2'000'000'000;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != -1) {
            fastest = min(vec[i] * (g + r) + i, fastest);
        }
    }
    if (fastest == 2'000'000'000) {
        cout << -1;
    } else {
        cout << fastest;
    }
    cout << endl;
    return 0;
}