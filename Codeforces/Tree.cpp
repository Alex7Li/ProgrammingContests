# include <bits/stdc++.h>
//http://codeforces.com/gym/101964/attachments/download/7814/seerc-2018.pdf
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> black;
    for (int i = 0; i < n; ++i) {
        int inp;
        cin >> inp;
        if (inp) {
            black.push_back(i);
        }
    }

//    for (int i = 0; i < black.size(); ++i) {
//        cout << black[i] << " ";
//    }
//    cout << endl;

    vector<vector<int>> dist(n, vector<int>(n, 300));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int ans = 200;
    for (int i = 0; i < black.size(); ++i) {
        for (int j = i; j < black.size(); ++j) {
            int u = black[i];
            int v = black[j];
            int diam = dist[u][v];
            int count = 0;
            for (int k = 0; k < black.size(); ++k) {
                int w = black[k];
                if (dist[u][w] <= diam && dist[v][w] <= diam) {
                    count++;
                }
            }
            if (count >= m && ans > diam) {
//                cout << "Valid: " << u << v << " Diam: " << diam;
                ans = diam;
            }
        }
    }

    cout << ans;
    return 0;
}