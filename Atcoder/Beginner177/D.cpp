# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dfs(int i, vector<vi> &e, vi &seen) {
    seen[i] = true;
    int size = 1;
    for (int j : e[i]) {
        if (!seen[j]) {
            size += dfs(j, e, seen);
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vi> e(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int maxCC = 0;
    vi seen(n, false);
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            maxCC = max(dfs(i, e, seen), maxCC);
        }
    }
    cout << maxCC;
    return 0;
}