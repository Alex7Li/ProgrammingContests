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
    vector<string> grid(8);
    vector<int> row(8);
    vector<int> col(8);
    vector<int> d1(15);
    vector<int> d2(15);
    int count = 0;
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '*') {
                row[i]++;
                col[j]++;
                d1[i + j]++;
                d2[i - j + 7]++;
                count++;
            }
        }
    }
    bool pos = count == 8;
    for (int i = 0; i < 8; i++) {
        if (row[i] > 1 || col[i] > 1) {
            pos = false;
        }
    }
    for (int i = 0; i < 15; i++) {
        if (d1[i] > 1 || d2[i] > 1) {
            pos = false;
        }
    }
    cout << (pos ? "valid" : "invalid");
    return 0;
}