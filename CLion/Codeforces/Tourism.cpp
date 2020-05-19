# include <bits/stdc++.h>
//http://codeforces.com/contest/1336/problem/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, int> scoreCount; // number below - number above
vector<vector<int>> g;

int dfs(int prev, int ind, int depth) {
    int above = depth;
    int below = 0;
    for (int i : g[ind]) {
        if (i != prev) {
            below += dfs(ind, i, depth + 1);
        }
    }
    // cout << ind+1 << " " << below << endl;
    scoreCount[above - below] += 1;
    return below + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, u, v;
    cin >> n >> k;
    g = vector<vector<int>>(n, vector<int>(0));
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    dfs(-1, 0, 0);
    ll answer = 0;
    for (auto it = scoreCount.rbegin(); k != 0; it++) {
        ll score = it->first;
        ll num = min(it->second, k);
        answer += score * num;
        k-= num;
    }
    cout << answer << endl;
    return 0;
}