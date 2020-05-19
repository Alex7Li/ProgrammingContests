# include <bits/stdc++.h>

//https://codeforces.com/contest/1311/problem/D
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int distance(int a, int b, int c, int a1, int b1, int c1) {
    return abs(a - a1) + abs(b - b1) + abs(c - c1);
}

vector<int> divisorsOf(int a) {
    vector<int> div;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            div.push_back(i);
            div.push_back(a/i);
        }
    }
    return div;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int max = 15001;
    rep(x, 0, t) {
        int a, b, c;
        cin >> a >> b >> c;
        int bestDist = 100000;
        vector<int> bestAns;
        bestAns.push_back(0);
        rep(b1, 1, max) {
            int best = 100000;
            int bestA = 1;
            for (int a1 : divisorsOf(b1)) {
                if (abs(a - a1) < best) {
                    best = abs(a - a1);
                    bestA = a1;
                }
            }
            bestAns.push_back(bestA);
        }
        vector<int> best;
        rep(c1, 1, max) {
            for (int b1 : divisorsOf(c1)) {
                int d = distance(a, b, c, bestAns[b1], b1, c1);
                if (bestDist > d) {
                    bestDist = d;
                    best = vector<int>{bestAns[b1], b1, c1};
                }
            }
        }
        cout << bestDist << "\n";
        cout << best[0] << " " << best[1] << " " << best[2] << "\n";
    }
    return 0;
}