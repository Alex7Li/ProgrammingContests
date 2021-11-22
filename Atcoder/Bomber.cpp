# include <bits/stdc++.h>
// https://atcoder.jp/contests/abc176/tasks/abc176_e
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    int m;
    map<int, int> yCount;
    map<int, int> xCount;
    cin >> h >> w >> m;
    set<pair<int, int>> locs;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> y >> x;
        x--;
        y--;
        auto item = yCount.find(y);
        if (item == yCount.end()) {
            yCount[y] = 1;
        } else {
            item->second++;
        }
        item = xCount.find(x);
        if (item == xCount.end()) {
            xCount[x] = 1;
        } else {
            item->second++;
        }
        locs.insert(make_pair(x, y));
    }
    int maxX = 0;
    int maxY = 0;
    for (int i = 0; i < h; i++) {
        maxY = max(maxY, yCount[i]);
    }
    for (int i = 0; i < w; i++) {
        maxX = max(maxX, xCount[i]);
    }
    vector<int> bestXs;
    vector<int> bestYs;
    for (int i = 0; i < h; i++) {
        if (maxY == yCount[i]) {
            bestYs.push_back(i);
        }
    }
    for (int i = 0; i < w; i++) {
        if (maxX == xCount[i]) {
            bestXs.push_back(i);
        }
    }
    for (auto x : bestXs) {
        for (auto y : bestYs) {
            if (locs.find(make_pair(x, y)) == locs.end()) {
                cout << maxX + maxY << "\n";
                return 0;
            }
        }
    }
    cout << maxX + maxY - 1 << "\n";
    return 0;
}
