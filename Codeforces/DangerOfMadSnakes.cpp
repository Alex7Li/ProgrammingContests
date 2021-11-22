# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r;
    cin >> n >> m >>r;
    vector<int> x;
    vector<int> y;
    vector<int> b;
    vector<vector<int>> psum(1001, vector<int>(1001, 0));
    vector<vector<int>> count(1001, vector<int>(1001, 0));
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> b[i];
        count[x[i]][y[i]] = 1;
    }
    for(int i = 0; i < n; i++){
        psum[i][0] = 0;
        for(int j = 0; j < n; j++) {
            psum[i][j] = psum[i-1][j] + count[i][j];
        }
    }
    vector<vi> graph(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = 1;
        }
    }

    return 0;
}