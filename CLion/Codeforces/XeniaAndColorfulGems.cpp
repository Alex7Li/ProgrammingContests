# include <bits/stdc++.h>
//https://codeforces.com/contest/1336/problem/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define billion 1000000000LL
typedef long long ll;

ll score(ll x, ll y, ll z) {
    return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t) {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        set<int> r, g, b;
        int temp;
        rep(i, 0, nr) {
            cin >> temp;
            r.insert(temp);
        }
        rep(i, 0, ng) {
            cin >> temp;
            g.insert(temp);
        }
        rep(i, 0, nb) {
            cin >> temp;
            b.insert(temp);
        }
        ll bestScore = billion * billion * 5;
        rep(i, 0, 3) {
            trav(w, r) {
                // Assume we are choosing the gem with the median weight w.
                auto bprev = b.upper_bound(w);
                if (bprev != b.begin()) {
                    bprev--;
                }
                auto bnext = b.lower_bound(w);
                auto gprev = g.upper_bound(w);
                if (gprev != g.begin()) {
                    gprev--;
                }
                auto gnext = g.lower_bound(w);
                if (gnext != g.end()) {
                    bestScore = min(score(w, *bprev, *gnext), bestScore);
                }
                if (bnext != b.end()) {
                    bestScore = min(score(w, *bnext, *gprev), bestScore);
                }
            }
            set<int> tempset = r;
            r = g;
            g = b;
            b = tempset;
        }
        cout << bestScore << "\n";
    }
    return 0;
}
