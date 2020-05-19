# include <bits/stdc++.h>

using namespace std;
//http://codeforces.com/problemset/problem/1278/E
vector<vector<int>> edges;
int n;
int ind = 0;
vector<vector<int>> solution;

void search(int cur, int parent) {
    for (int e: edges[cur]) {
        if (e != parent) {
            solution[e][0] = ++ind;
        }
    }
    solution[cur][1] = ++ind;
    for (auto e = edges[cur].rbegin(); e != edges[cur].rend(); e++) {
        if (*e != parent) {
            search(*e, cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    edges = vector<vector<int>>(n);
    solution = vector<vector<int>>(n, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    solution[0][0] = ++ind;
    search(0, -1);
    for (vector<int> x : solution) {
        cout << x[0] << " " << x[1] << "\n";
    }
    return 0;
}