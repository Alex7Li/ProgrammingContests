# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string strategy(int r, int c, vector<string> &g) {
    if (r == g.size() - 1) {
        return "right";
    }
    if (c == g[0].size() - 1) {
        return "down";
    }
    if (g[r + 1][c] == '*') {
        return "down";
    }
    return "right";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, 0, h) {
        cin >> g[i];
    }
    int r = 0;
    int c = 0;
    int score = g[0][0] == '*';
    while (r + c < h - 1 + w - 1) {
        string dir = strategy(r, c, g);
        if (dir == "right") {
            c++;
        } else {
            r++;
        }
        score += g[r][c] == '*';
        //cout << r << " " << c << " "<< g[r][c] << "\n";
    }
    cout << score << endl;
    return 0;
}