# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int> VI;
typedef vector<VI> VVI;
// https://open.kattis.com/problems/latinsquare
bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (!w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);
    int ct = 0;
    for (int i = 0; i < w.size(); ++i) {
        for (int j = 0; j < w[0].size(); ++j) {
            if (!w[i][j] && mc[j] == -1) {
                mc[j] = i;
                mr[i] = j;
                ct++;
                break;
            }
        }
    }
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (mr[i] == -1 && FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    cout << "YES" << endl;
    vector<vi> g(n, vi(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    set<int> left;
    for (int i = 0; i < n; ++i) {
        left.insert(g[0][i]);
    }
    for(int cur = 1; cur <= n; cur++) {
        if(left.count(cur)){
            continue;
        }
        vi mr;
        vi mc;
        int matches = BipartiteMatching(g, mr, mc);
        assert(matches == n);
        for (int i = 0; i < n; ++i) {
            g[i][mr[i]] = cur;
        }
    }
    for (int i = 0; i < g.size(); ++i) {
        cout << g[i][0];
        for (int j = 1; j < g.size(); ++j) {
            cout << " " << g[i][j];
        }
        cout << endl;
    }
    return 0;
}

