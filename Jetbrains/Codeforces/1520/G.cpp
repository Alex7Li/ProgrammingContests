# include <bits/stdc++.h>
//https://codeforces.com/contest/1520/problem/G?csrf_token=85f2e3fe9a16a3943574cd6fe7c80343
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = LONG_LONG_MAX / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, w;
    cin >> n >> m >> w;
    vector<vi> a(n, vi(m, 0));
    vector<pair<int, pii>> portals;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] > 0) {
                portals.push_back({a[i][j], {i, j}});
            }
        }
    }
    sort(portals.begin(), portals.end());
    ll portalCost = INF;
    priority_queue<pair<ll, pii>> Q;
    Q.push({0, {0, 0}});
    Q.push({-INF, {0, 0}});//sentinel
    vector<pii> adj = {{0,  -1},
                       {0,  1},
                       {1,  0},
                       {-1, 0}};
    int portalInd = 0;
    vector<vector<ll>> c(n, vector<ll>(m, INF));
    while (!Q.empty()) {
        pair<ll, pii> t = Q.top();
        ll cost = -t.first;
        bool skip = false;
        while (portalInd < portals.size() && portals[portalInd].first + portalCost < cost) {
            pii coord = portals[portalInd].second;
            Q.push({-(portals[portalInd].first + portalCost), coord});
            skip = true;
            portalInd++;
        }
        if (skip) {
            continue;
        }
        int x = t.second.first;
        int y = t.second.second;
        Q.pop();
        if (cost > c[x][y]) {
            continue;
        }
        c[x][y] = cost;
        for (pii e: adj) {
            int x2 = e.first + x;
            int y2 = e.second + y;
            ll tCost = cost + w;
            if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m && a[x2][y2] != -1) {
                if (c[x2][y2] <= tCost) {
                    continue;
                }
                c[x2][y2] = tCost;
                Q.push({-tCost, {x2, y2}});
            }
        }
        if (a[x][y] > 0) {
            ll newPortalCost = a[x][y] + cost;
            if (newPortalCost < portalCost) {
                portalCost = newPortalCost;
            }
        }
    }/*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cerr << c[i][j] << " ";
        }
        cerr << "\n";
    }*/
    cout << (c[n - 1][m - 1] == INF ? -1 : c[n - 1][m - 1]);
    return 0;
}
