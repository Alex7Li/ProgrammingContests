# include <bits/stdc++.h>
//https://codeforces.com/gym/101482/attachments
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


unordered_set<ll> distanceSet(vector<int> &inds, vector<vi> &d) {
    vector<int> order(inds.size() - 2);
    iota(order.begin(), order.end(), 1);
    unordered_set<ll> dists;
    if(inds.size() == 2){
        dists.insert(d[inds[0]][inds[1]]);
    }else {
        do {
            ll dist = d[inds[0]][inds[order[0]]];
            for (int i = 0; i < order.size() - 1; ++i) {
                dist += d[inds[order[i]]][inds[order[i + 1]]];
            }
            dist += d[inds[order[order.size() - 1]]][inds[inds.size() - 1]];
            dists.insert(dist);
        } while (next_permutation(order.begin(), order.end()));
    }
    return dists;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, L;
    cin >> n >> L;
    vector<vi> d(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    int st = 0;
    bool pos = false;
    for (int mid = 1; mid < n; ++mid) {
        int lSize = (n - 2) / 2;
        for (int i = 0; i < 1 << n; ++i) {
            if ((i & (1 << st)) || (i & (1 << mid))) {
                continue;
            }
            if (__builtin_popcount(i) == lSize) {
                vector<int> lSet = {st};
                vector<int> rSet = {st};
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        lSet.push_back(j);
                    } else if (j != st && j != mid) {
                        rSet.push_back(j);
                    }
                }
                lSet.push_back(mid);
                rSet.push_back(mid);
                // Generate distance sets
                unordered_set<ll> lDist = distanceSet(lSet, d);
                unordered_set<ll> rDist = distanceSet(rSet, d);
                // Meet in the middle.
                for (ll ld : lDist) {
                    ll req = L - ld;
                    if (rDist.find(req) != rDist.end()) {
                        pos = true;
                    }
                }
            }
        }
    }
    cout << (pos ? "" : "im") << "possible\n";
    return 0;
}