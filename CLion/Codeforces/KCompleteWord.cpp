# include <bits/stdc++.h>
//http://codeforces.com/contest/1332/problem/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dfs(vector<bool>& seen, int ind, map<char, int> &counts, string &str, vector<vi> &edges) {
    seen[ind] = true;
    int size = 1;
    counts[str[ind]]++;
    for (int nxt: edges[ind]) {
        if (!seen[nxt]) {
            size += dfs(seen, nxt, counts, str, edges);
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, k;
    cin >> t;
    rep(times, 0, t) {
        cin >> n >> k;
        string str;
        cin >> str;
        vector<vi> edges(n, vi(0));
        for (int i = 0; i < n - k; i++) {
            edges[i].push_back(i + k);
            edges[i + k].push_back(i);
        }
        for (int i = 0; i < n / 2; i++) {
            edges[i].push_back(n - i - 1);
            edges[n - i - 1].push_back(i);
        }
        vector<bool> seen(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                map<char, int> counts;
                int ccSize = dfs(seen, i, counts, str, edges);
                int maxC = 0;
                for (pair<char, int> p : counts) {
                    maxC = max(maxC, p.second);
                }
                ans += ccSize - maxC;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}