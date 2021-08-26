# include <bits/stdc++.h>

using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vii room(n, vi(m, 0));
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        room[x - 1][y - 1] = 1;
    }

    // cout << "hello" << endl;

    vii pre(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pre[i][j] = room[i][j];
            if (i > 0) pre[i][j] += pre[i - 1][j];
            if (j > 0) pre[i][j] += pre[i][j - 1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i - 1][j - 1];
        }
    }

    // cout << "hello" << endl;

    int mingap = min(m, n);
    for (int i = 0; i < n; ++i) {
        int gap = 0;
        for (int j = 0; j < m; ++j) {
            if (room[i][j] == 0) {
                gap += 1;
            } else {
                if (gap > 0)
                    mingap = min(mingap, gap);
                gap = 0;
            }
        }
        if (gap > 0)
            mingap = min(mingap, gap);
    }

    for (int j = 0; j < m; ++j) {
        int gap = 0;
        for (int i = 0; i < n; ++i) {
            if (room[i][j] == 0) {
                gap += 1;
            } else {
                if (gap > 0) {
                    mingap = min(mingap, gap);
                }
                gap = 0;
            }
        }
        if (gap > 0) {
            mingap = min(mingap, gap);
        }
    }

    // cout << mingap << endl;
    // cout << "hello" << endl;

    int lo = 0, hi = mingap;

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << pre[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    while (lo != hi) {
        int s = (lo + hi + 1) / 2;
        vii graph(n - s + 1, vi(m - s + 1, 1));
        for (int i = 0; i < n - s + 1; ++i) {
            for (int j = 0; j < m - s + 1; ++j) {
                int temp = pre[i + s - 1][j + s - 1];
                if (i > 0) temp -= pre[i - 1][j + s - 1];
                if (j > 0) temp -= pre[i + s - 1][j - 1];
                if (i > 0 && j > 0) temp += pre[i - 1][j - 1];
                if (temp > 0)
                    graph[i][j] = -1;
            }
        }

        // for (int i = 0; i < n-s+1; ++i) {
        //     for (int j = 0; j < m-s+1; ++j) {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // cout << "hello" << endl;
        pii init(-1, -1);
        int unseen = 0;
        for (int i = 0; i < n - s + 1; ++i) {
            for (int j = 0; j < m - s + 1; ++j) {
                if (graph[i][j] == 1) {
                    init.first = i;
                    init.second = j;
                    unseen++;
                }
            }
        }

        // cout << "unseen: " << unseen << endl;

        vector<pii> todo;
        todo.push_back(init);
        while (todo.size() > 0) {
            init = todo.back();
            todo.pop_back();
            int x = init.first, y = init.second;
            if (graph[x][y] != 1)
                continue;
            graph[x][y] = 0;

            if (x > 0 && graph[x - 1][y] > 0) todo.push_back({x - 1, y});
            if (x < n - s && graph[x + 1][y] > 0) todo.push_back({x + 1, y});
            if (y > 0 && graph[x][y - 1] > 0) todo.push_back({x, y - 1});
            if (y < m - s && graph[x][y + 1] > 0) todo.push_back({x, y + 1});
            unseen--;
        }

        if (unseen == 0) {
            lo = s;
        } else {
            hi = s - 1;
        }
    }
    if (lo == 0)
        cout << -1 << endl;
    else
        cout << lo << endl;
}