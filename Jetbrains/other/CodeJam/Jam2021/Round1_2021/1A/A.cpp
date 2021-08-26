# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool isPrefix(string prefix, string full) {
    auto m = mismatch(prefix.begin(), prefix.end(), full.begin());
    return m.first == prefix.end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string cur = a[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            while (a[i].size() < cur.size() || (a[i].size() == cur.size() && a[i] <= cur)) {
                if (a[i] != cur && isPrefix(a[i], cur)) {
                    int lastNotNine = cur.size() - 1;
                    while (lastNotNine >= a[i].size() && cur[lastNotNine] == '9') {
                        lastNotNine--;
                    }
                    for(int k = a[i].size(); k < lastNotNine; k++){
                        a[i] += cur[k];
                        ans++;
                    }
                    if(lastNotNine != a[i].size() - 1) {
                        a[i] += (char) (cur[lastNotNine] + 1);
                        ans++;
                    }else{
                        lastNotNine--;
                    }
                    for(int k = lastNotNine + 1; k < cur.size(); k++){
                        a[i] += '0';
                        ans++;
                    }
                } else {
                    a[i] += '0';
                    ans += 1;
                }
            }
            cur = a[i];
            cerr << cur << " ";
        }
        cerr << "\n";
        cout << "Case #" << tt << ": " << ans;
        cout << endl;
    }
    return 0;
}