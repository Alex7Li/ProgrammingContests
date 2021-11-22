# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// from kactl
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = -1, val = 0;

    Node(int lo, int hi) : lo(lo), hi(hi) {}

    Node(vi &v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = l->val + r->val;
        } else val = v[lo];
    }

    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }

    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            val = x * (hi - lo);
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }

    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != -1)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, q;
        cin >> n >> q;
        string ss, fs;
        cin >> ss >> fs;
        vector<int> s(n);
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            s[i] = ss[i] == '1';
            f[i] = fs[i] == '1';
        }
        vi l(q);
        vi r(q);
        for (int i = 0; i < q; i++) {
            cin >> l[i] >> r[i];
            l[i]--;
        }
        Node cur{f, 0, n + 1};
        vi final(n);
        bool possible = true;
        for (int i = q - 1; i >= 0; i--) {
            int len = r[i] - l[i];
            int sum = cur.query(l[i], r[i]);
            if (sum * 2 == len) {
                possible = false;
            } else if (sum * 2 < len) {
                cur.set(l[i], r[i], 0);
            } else {
                cur.set(l[i], r[i], 1);
            }
            /* for (int i = 0; i < n; i++) {
                 cout << cur.query(i, i + 1) << " ";
             }
             cout << endl;*/
        }
        for (int i = 0; i < n; i++) {
            final[i] = cur.query(i, i + 1);
            if (final[i] != s[i]) {
                possible = false;
            }
        }
        if (possible) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}