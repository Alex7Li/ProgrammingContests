#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
pair<int, int> dfs(int root, int prev, vector<vi> &g, vi &a, int total)
{
    int xorV = a[root];
    int tCount = 0;
    for(int next : g[root]) {
        if(next != prev) {
            pair<int, int> p = dfs(next, root, g, a, total);
            xorV ^= p.second;
            tCount += p.first;
        }
    }
    if(xorV == total) {
        tCount++; // can cut this subtree off to make a cc.
        xorV = 0;
    }
    return {tCount, xorV};

}
bool solve(vector<vi> &g, vi &a, int k)
{
    int n = a.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total ^= a[i];
    }
    if(total == 0){
         return true;
    }
    if(k > 2){
        return dfs(0, -1, g, a, total).first >= 3;
    }else{
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_tests;
    cin >> n_tests;
    for (int cur_test = 1; cur_test <= n_tests; cur_test++)
    {
        int n, k;
        cin >> n >> k;
        vector<vi> g(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(solve(g, a, k)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}