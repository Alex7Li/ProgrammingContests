# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string solve(string a, string b, bool shareOnes) {
    if (!shareOnes) {
        for (int i = 0; i < a.size(); ++i) {
            a[i] = (char) ('1' + '0' - a[i]);
            b[i] = (char) ('1' + '0' - b[i]);
        }
    }
    string ans = "";
    int bPtr = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (bPtr == b.size() || a[i] == b[bPtr]) {
            ans += a[i];
            bPtr++;
        } else if (a[i] == '0') {
            ans += '0';
        } else {
            while (bPtr < b.size() && b[bPtr] == '0') {
                bPtr++;
                ans += '0';
            }
        }
    }
    while (bPtr < b.size()) {
        ans += b[bPtr++];
    }
    assert(ans.size() <= (3 * a.size()) / 2);
    while (ans.size() < (3 * a.size()) / 2) {
        ans += '0';
    }
    assert(ans.size() == (3 * a.size()) / 2);
    if (!shareOnes) {
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = (char) ('1' + '0' - ans[i]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<string> strs(3);
        cin >> strs[0] >> strs[1] >> strs[2];
        vector<int> oneC(3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[i][j] == '1') {
                    oneC[i]++;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                if (min(oneC[i], oneC[j]) >= n) {
                    ans = solve(strs[i], strs[j], true);
                } else if (min(2 * n - oneC[i], 2 * n - oneC[j]) >= n) {
                    ans = solve(strs[i], strs[j], false);
                }
            }
        }
        assert(!ans.empty());
        cout << ans << "\n";
    }
    return 0;
}