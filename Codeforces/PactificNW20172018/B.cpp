# include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int n;
vector<int> p;
vector<vector<vi>> ans;

int solve(int mask, int scoreLeft, int last, int left) {
    if (scoreLeft < 0) {
        return 0;
    }
    if (ans[mask][scoreLeft][last]) {
        return ans[mask][scoreLeft][last];
    }
    if (left == 0) {
        ans[mask][scoreLeft][last] = 1;
        return 1;
    }
    int ways = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            int toAdd = max(0, p[last] - p[i] + 1);
            ways += solve(mask ^ (1 << i), scoreLeft - toAdd * left, i, left - 1);
        }
    }
    ans[mask][scoreLeft][last] = ways;
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        p.push_back(v);
    }
    ans = vector<vector<vi>>(1 << n, vector<vi>(x + 1, vi(12)));
    int biggest = *max_element(p.begin(), p.end());
    int ways = 0;
    for (int i = 0; i < n; i++) {
        int mask = (1 << n) - 1;
        if (biggest != p[i]) {
            int toAdd = biggest + 1 - p[i];
            ways += solve(mask ^ (1 << i), x - toAdd * n, i, n - 1);
        }
    }
    cout << ways << endl;
    return 0;
}