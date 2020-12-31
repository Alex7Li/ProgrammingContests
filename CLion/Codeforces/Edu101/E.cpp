# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string toBinaryString(int x, int l) {
    string s = "";
    for (int i = l - 1; i >= 0; i--) {
        if (x & (1 << i)) {
            s += "1";
        } else {
            s += "0";
        }
    }
    return s;
}

int binaryStrToInt(string s) {
    int v = 0;
    int powT = 1;
    for (int j = s.size() - 1; j >= 0; --j) {
        v += powT * (int) (s[j] - '0');
        powT *= 2;
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi seq = {2, 3, 5, 22, 448};
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int pow = 1;
        int val = 2;
        while (val <= n - k + 1 && pow < k) {
            pow++;
            val *= 2;
        }
        vector<bool> seen(val);
        string s;
        cin >> s;
        int lastZero = -1;
        for (int i = 0; i < k - pow - 1; i++) {
            if (s[i] == '0') {
                lastZero = i;
            }
        }
        for (int i = 0; i <= s.size() - k; i++) {
            if (i + k - pow - 1 >= 0 && s[i + k - pow - 1] == '0') {
                lastZero = i + k - pow - 1;
            }
            int v = binaryStrToInt(s.substr(i + k - pow, pow));
            if (lastZero < i) {
                seen[v] = true;
            }
        }
        bool done = false;
        for (int i = val - 1; i >= 0; i--) {
            if (!seen[i]) {
                cout << "YES" << "\n";
                for (int j = 0; j < k - pow; j++) {
                    cout << "0";
                }
                cout << toBinaryString(i ^ (val - 1), pow) << "\n";
                done = true;
                break;
            }
        }
        if (!done) {
            cout << "NO" << '\n';
        }
        cout << flush;
    }
    return 0;
}
