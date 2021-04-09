# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool FindMatch(int i, const vvi &w, vi &mr, vi &mc, vi &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
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

int BipartiteMatching(const vvi &w, vi &mr, vi &mc) {
    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        vi seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int d, n;
    cin >> d >> n;
    vi names(n, 0);
    rep(i, 0, n) {
        string raw;
        cin >> raw;
        for (int j = 0; j < d; ++j) {
            names[i] += (raw[j] - '0') * (1 << j);
        }
    }
    stable_sort(names.begin(), names.end(), [](const int &a, const int &b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    });
    vector<vi> e(n, vi(n));
    vi costL(n);
    rep(i, 0, n) {
        costL[i] = __builtin_popcount(names[i]) + 1;
        rep(j, 0, n) {
            // edge from i to j
            if (i != j && (names[i] | names[j]) == names[j]) {
                e[i][j] = 1;
            }
        }
    }
    vi mr(n, -1);
    vi mc(n, -1);
    BipartiteMatching(e, mr, mc);
    vector<int> path;
    for (int i = 0; i < n; ++i) {
        if (mc[i] == -1) {
            int mask = 0;
            int j = i;
            while (mr[j] != -1) {
                for (int k = 0; k < d; k++) {
                    if ((names[j] ^ mask) & (1 << k)) {
                        mask ^= (1 << k);
                        path.push_back(k);
                    }
                }
                j = mr[j];
            }
            for (int k = 0; k < d; k++) {
                if ((names[j] ^ mask) & (1 << k)) {
                    mask ^= (1 << k);
                    path.push_back(k);
                }
            }
            path.push_back(-1);
        }
    }
    cout << path.size() - 1 << endl;
    rep(i, 0, path.size() - 1) {
        if (path[i] == -1) {
            cout << "R ";
        } else {
            cout << path[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
