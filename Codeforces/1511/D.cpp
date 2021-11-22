# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void get_cycle(map<char, vector<char>> &adj, map<string, bool> &seen, char start, vector<char> &path) {
    for (auto node: adj[start]) {
        string edge{start, node};
        if (!seen[edge]) {
            seen[edge] = true;
            get_cycle(adj, seen, node, path);
        }
    }
    path.push_back(start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<char, vector<char>> adj;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            char a = (char) ((i % k) + 'a');
            char b = (char) ((j % k) + 'a');
            adj[a].push_back(b);
        }
    }
    map<string, bool> seen;
    vector<char> path;
    get_cycle(adj, seen, 'a', path);
    path.pop_back();
    string ans = "";
    for (int i = 0; i < n; ++i) {
        ans += path[i % path.size()];
    }
    cout << ans << "\n";
    return 0;
}