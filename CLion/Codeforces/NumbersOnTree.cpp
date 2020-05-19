# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1286/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> children;
vector<int> cost;
vector<int> subTreeSize;
vector<int> a;
template<class T> void removeAt(vector<T>& v, int ind) {
    for (unsigned int i = ind; i < v.size(); i++) {
        v[i] = v[i + 1];
    }
    v.pop_back();
}

void fill(int from, vector<int> vals){
    a[from] = vals[cost[from]];
    removeAt(vals, cost[from]);
    int st = 0;
    trav(child, children[from]){
        int sz = subTreeSize[child];
        vector<int> newVals(vals.begin() + st, vals.begin() + st + sz);
        fill(child, newVals);
        st += sz;
    }
}

int sizes(int from) {
    int tSize = 1;
    for (int i: children[from]) {
        tSize += sizes(i);
    }
    subTreeSize[from] = tSize;
    return tSize;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vals(n);
    children = vector<vector<int>>(n, vector<int>());
    cost = vi(n, 0);
    a = vi(n, 0);
    subTreeSize = vi(n, 0);
    vals = vi(n, 0);
    rep(i, 0, n) {
        vals[i] = i + 1;
    }
    int root = -1;
    rep(i, 0, n) {
        int p, c;
        cin >> p >> c;
        if (p == 0) {
            root = i;
        } else {
            children[p - 1].push_back(i);
        }
        cost[i] = c;
    }
    sizes(root);
    rep(from, 0, n) {
        if (cost[from] >= subTreeSize[from]) {
            cout << "NO";
            return 0;
        }
    }
    fill(root, vals);
    cout << "YES\n" << a[0];
    for (int i = 1; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}