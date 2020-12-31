# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> output;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (true) {
        vector<int> splits;
        int t = 0;
        splits.push_back(0);
        while (t < n && a[t] == t + 1) {
            t++;
        }
        if (0 != t) {
            splits.push_back(t);
        }
        if (t == n) {
            break;
        }
        for (int i = t; i < n; i++) {
            if (i == splits[splits.size() - 1]) {
                continue;
            }
            if ((a[i] < a[splits[splits.size() - 1]]) ^ (t != 0)) {
                splits.push_back(i);
            }
        }
        if (splits[splits.size() - 1] != n) {
            splits.push_back(n);
        }
        vector<int> b;
        for (int i = splits.size() - 2; i >= 0; i--) {
            for (int j = splits[i]; j < splits[i + 1]; j++) {
                b.push_back(a[j]);
            }
        }
        vector<int> seq;
        for (int i = 1; i < splits.size(); i++) {
            seq.push_back(splits[i] - splits[i - 1]);
        }
        output.push_back(seq);
        a = b;
    }
    cout << output.size() << "\n";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i].size();
        for (int j = 0; j < output[i].size(); j++) {
            cout << " " << output[i][j];
        }
        cout << "\n";
    }
    return 0;
}