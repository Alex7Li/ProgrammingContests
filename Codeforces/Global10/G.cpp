# include <bits/stdc++.h>
// WA
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef pair<int, int> pii;

int n, m, k;

int swapBits(int x, int pos1, int pos2) {
    int y = x;
    // Gotta cast to bool here, getting too tricky with bitwise operations
    // and not doing so confused me for several hours before I fixed it
    if (bool((1 << pos1) & x) ^ bool((1 << pos2) & x)) {
        y ^= (1 << pos1) + (1 << pos2);
    }
    return y;
}

void updateDists(vector<pii> &dists, int loc, int d, int endInd) {
    if (dists[loc].first > d) {
        dists[loc] = pii(d, endInd);
        for (int i = 0; i < k; i++) {
            updateDists(dists, loc ^ (1 << i), d + 1, endInd);
        }
    }
}

int applyPerm(vector<int> &perm, int x) {
    int y = 0;
    for (int i = 0; i < k; i++) {
        if (x & (1 << perm[i]))
            y += 1 << i;
    }
    return y;
}

void updatePerm(vector<int> &perm, int x, int y) {
    /* Swap x and y before applying perm. */
    int a = 0, b = 0;
    rep(j, 0, k) {
        if (perm[j] == x) {
            a = j;
        } else if (perm[j] == y) {
            b = j;
        }
    }
    swap(perm[a], perm[b]);
}

void printPerm(vector<int> &perm) {
    for (int i = 0; i < perm.size(); i++) {
        cout << perm[i] << " ";
    }
    cout << "\n";
}

bitset<12> bin(int a) {
    bitset<12> x(a);
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    int st = 0;
    int end = 0;
    string x;
    cin >> x;
    rep(i, 0, k) {
        st += (x[i] - '0') << i;
    }
    cin >> x;
    rep(i, 0, k) {
        end += (x[i] - '0') << i;
    }
    vector<pii> pairs(n);
    rep(i, 0, n) {
        cin >> pairs[i].first >> pairs[i].second;
        pairs[i].first -= 1;
        pairs[i].second -= 1;
    }
    vector<int> perm(k, 0);
    rep(i, 0, k) {
        perm[i] = i;
    }
//    for (int i = n - m; i < n; i++) {
    for (int i = n - 1; i >= n - m; i--) {
        swap(perm[pairs[i].first], perm[pairs[i].second]);
    }
    vector<pii> dists(1 << k, pii(k + 2, -1));
    updateDists(dists, end, 0, n);
    int bestScore = dists[applyPerm(perm, st)].first;
    pii bestPair = pii(n - m + 1, dists[end].second);
    for (int i = n - m - 1; i >= 0; i--) {
        cout << bin(end) << "\n";
        cout << "Swap " << pairs[i + m].first << " " << pairs[i + m].second << "\n";
        end = swapBits(end, pairs[i + m].first, pairs[i + m].second);
        updateDists(dists, end, 0, i + m);

//        updatePerm(perm, pairs[i].first, pairs[i].second);
        swap(perm[pairs[i].first], perm[pairs[i].second]);
        int afterPerm = applyPerm(perm, st);
//        cout << i+1 << " " << dists[afterPerm].second << " " << dists[afterPerm].first <<"\n";
        if (dists[afterPerm].first < bestScore) {
            bestScore = dists[afterPerm].first;
            bestPair = pii(i + 1, dists[afterPerm].second);
        }
    }
    cout << bin(end) << "\n";
    cout << k - bestScore << "\n";
    cout << bestPair.first << " " << bestPair.second << endl;
    return 0;
}

