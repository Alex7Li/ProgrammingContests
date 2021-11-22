# include <bits/stdc++.h>
// https://codeforces.com/gym/102694/problem/E

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<vector<int>> adj;
int ind = 0;
vi startInd;
vi endInd;
vector<bool> seen;

struct SegTree {
    // The number of leaves.
    int size;
    // The sum of this node and all nodes under it.
    vector<double> sum;

    SegTree(int sz) {
        size = sz;
        sum = vector<double>(2 * sz, 0);
    }

    void update(int index, double val) {
        index += size;
        double diff = val - sum[index];
        for (; index > 0; index /= 2) {
            sum[ind] = sum[index] + diff;
        }
    }

    // Sum over the range [l, r)
    double query(int l, int r) {
        l += size;
        r += size;
        double tSum = 0;
        for (; l < r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                tSum += sum[l];
                l++;
            }
            if (r % 2 == 1) {
                r--;
                tSum += sum[r];
            }
        }
        return tSum;
    }
};

void computeValues(int root) {
    seen[root] = true;
    startInd[root] = ind++;
    for (int i = 0; i < adj[root].size(); i++) {
        int next = adj[root][i];
        if (!seen[next]) {
            computeValues(next);
        }
    }
    endInd[root] = ind;
};

double value(int node, SegTree& tree) {
    return tree.query(startInd[node], endInd[node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj = vector<vector<int>>(n, vector<int>(0, 0));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    seen = vector<bool>(n);
    startInd = vi(n);
    endInd = vi(n);
    computeValues(0);
    SegTree tree = SegTree(n);
    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            tree.update(startInd[x - 1], log(y));
        } else {
            assert(type == 2);
            double ans = value(x - 1, tree) - value(y - 1, tree);
            cout << min(1000000000.0, exp(ans)) << "\n";
        }
    }
    return 0;
}