# include <bits/stdc++.h>

using namespace std;

https://codeforces.com/problemset/problem/1257/F
map<vector<int>, int> bigMap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < 1 << 15; ++i) {
        vector<int> vals;
        for (int j = 0; j < n; ++j) {
            int set = __builtin_popcount((a[j] >> 15) ^ i);
            vals.push_back(set);
        }
        if (bigMap.find(vals) == bigMap.end()) {
            bigMap[vals] = i;
        }
    }
    for (int i = 0; i < 1 << 15; ++i) {
        vector<int> vals;
        for (int j = 0; j < n; ++j) {
            vals.push_back(15 - __builtin_popcount((a[j] ^ i)&((1<<15)-1)));
        }
        for (int j = 0; j < 15; ++j) {
            if (bigMap.find(vals) != bigMap.end()) {
                cout << i + (bigMap[vals] << 15) << endl;
                return 0;
            }
            for (int k = 0; k < n; ++k) {
                vals[k]--;
            }
        }
    }
    cout << -1;
    return 0;
}


