# include <bits/stdc++.h>
// https://codeforces.com/contest/915/problem/F
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Vertex {
    int val;
    int ind;
    vector<shared_ptr<Vertex>> adj;
};

struct UF {
    vi e;

    UF(int n) : e(n, -1) {}

    bool same_set(int a, int b) { return find(a) == find(b); }

    int size(int x) { return -e[find(x)]; }

    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};


ll paths(ll n) {
    return n * (n + 1) / 2;
}

/*
 * return the sum of the max elements of
 * each path
 */
ll countMax(vector<shared_ptr<Vertex>> &v) {
    int n = v.size();
    auto sortByVal = [](const shared_ptr<Vertex> a, const shared_ptr<Vertex> b) -> bool {
        return a->val == b->val ? a->ind < b->ind : a->val < b->val;
    };
    sort(v.begin(), v.end(), sortByVal);
    ll count = 0;
    UF uf(n);
    rep(i, 0, n) {
        ll diff = 0;
        ll stSize = uf.size(v[i]->ind);
        diff = paths(stSize) - paths(stSize - 1);
        for (auto joined : v[i]->adj) {
            if (sortByVal(joined, v[i])) {
                if (uf.same_set(v[i]->ind, joined->ind)) {
                    continue;
                } else {
                    diff -= paths(uf.size(v[i]->ind));
                    diff -= paths(uf.size(joined->ind));
                    uf.join(v[i]->ind, joined->ind);
                    diff += paths(uf.size(v[i]->ind));
                }
            }
        }
      //  cout << v[i]->ind << " " << diff << " " << v[i]->val << endl;
        count += diff * v[i]->val;
    }
    //cout << endl;
    return count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<shared_ptr<Vertex>> a(n);
    rep(i, 0, n) {
        Vertex v = {0, i, vector<shared_ptr<Vertex>>(0)};
        a[i] = make_shared<Vertex>(v);
        cin >> a[i]->val;
    }
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        a[x - 1]->adj.push_back(a[y - 1]);
        a[y - 1]->adj.push_back(a[x - 1]);
    }
    ll ans = countMax(a);
    rep(i, 0, n) {
        a[i]->val *= -1;
    }
    ans += countMax(a);
    cout << ans;
    return 0;
}