# include <bits/stdc++.h>

using namespace std;

//http://codeforces.com/problemset/problem/1272/D
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    // elements i such that a[i] >= a[i+1]
    vector<int> decreasing;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    decreasing.push_back(-1);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            decreasing.push_back(i);
        }
    }
    decreasing.push_back(n - 1);
    int best = 0;
    for (unsigned int i = 0; i < decreasing.size() - 1; i++) {
        best = max(best, decreasing[i + 1] - decreasing[i]);
        if (i != 0 && a[decreasing[i] - 1] < a[decreasing[i] + 1]) {
            best = max(best, decreasing[i + 1] - decreasing[i - 1] - 1);
        }
        if (i!= 0 && decreasing[i]+2<n && a[decreasing[i]] < a[decreasing[i]+2]) {
            best = max(best, decreasing[i + 1] - decreasing[i - 1] - 1);
        }
    }
    cout << best;
    return 0;
}