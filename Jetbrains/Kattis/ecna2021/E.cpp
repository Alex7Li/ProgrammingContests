# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int parse(char c) {
    int ans = -1;
    if (c == ' ') {
        ans = 36;
    } else if ((int) c >= (int) 'A') {
        ans = (int) c - (int) 'A';
    } else if ((int) c <= (int) '9') {
        ans = (int) c - (int) '0' + 26;
    }
    return ans;
}

char unparse(int c) {
    if (c < 26) {
        return (char) ('A' + c);
    } else if (c < 36) {
        return (char) ('0' + c - 26);
    } else { // if (c == 37) {
        return ' ';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vi> m(n, vi(n, 0));
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> m[i][j];
        }
    }
    string instr;
    getline(cin, instr);
    getline(cin, instr);
    int l = instr.length();
    int pad = ((n - l) % n + n) % n;
    l = l + pad;
    vi in(l, 36);
    vi out(l, 0);
    rep(i, 0, instr.length()) {
        in[i] = parse(instr[i]);
    }
    for (int st = 0; st < l; st += n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                out[i + st] = (out[i + st] + in[j + st] * m[i][j]) % 37;
            }
        }
    }
    rep(i, 0, l) {
        cout << unparse(out[i]);
    }
    cout << "\n";
    return 0;
}