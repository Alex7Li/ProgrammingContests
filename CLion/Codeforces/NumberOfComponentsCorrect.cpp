# include <bits/stdc++.h>
//https://codeforces.com/contest/1270/problem/H
using namespace std;
typedef vector<int> vi;
int n, q;
vi arr;
int maxV = 1000001;

// f[i]: the number of values 1<=j<n  arr such that (arr[j]>=i-n) != (arr[j-1]>=i-n) if i > n, else min(f[2*i], f[2*i+1])
// count[i]: the number of values left<=j<right  arr such that f[i] == f[i-n] if i > n, else the number of times i-n appears in a.
struct SegTree {
    SegTree *l, *r;
    int lo, mid, hi, fLazy = 0, f = 0, count = 0;

    SegTree(int lo, int hi) : lo(lo), hi(hi) {
        mid = lo + (hi - lo) / 2;
        if (lo + 1 < hi) {
            l = new SegTree(lo, mid);
            r = new SegTree(mid, hi);
            merge();
        }
    }

    void merge() {
        f = min(l->f, r->f);
        count = 0;
        if (f == r->f) {
            count += r->count;
        }
        if (f == l->f) {
            count += l->count;
        }
    }

    void push() {
        if (fLazy) {
            l->addF(lo, hi, fLazy), r->addF(lo, hi, fLazy), fLazy = 0;
        }
    }

    int query(int L, int R) {
        if (R <= lo || hi <= L) { return 0; }
        if (lo + 1 != hi) { push(); }
        if (L <= lo && hi <= R) { return f == 1 ? count : 0; }
        int ans = l->query(L, R) + r->query(L, R);
        merge();
        return ans;
    }

    void updCount(int ind, int diff) {
        if (ind == lo && hi == ind + 1) {
            count+= diff;
        } else {
            push();
            if (ind < mid) {
                l->updCount(ind, diff);
            } else {
                assert(ind < hi);
                r->updCount(ind, diff);
            }
            merge();
        }
    }

    void addF(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            f += x;
            if (lo + 1 != hi) {
                fLazy += x;
            }
        } else {
            push(), l->addF(L, R, x), r->addF(L, R, x), merge();
        }
    }

    void upd(int a, int b, int delta) {
        addF(min(a, b), max(a, b), delta);
    }

    void addToTree(int pos, int add) {
        upd(arr[pos - 1], arr[pos], add);
        upd(arr[pos], arr[pos + 1], add);
        updCount(arr[pos], add);
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    arr = vi(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    arr[0] = maxV;
    arr[n + 1] = 0;
    SegTree tree = SegTree(0, maxV);
    for (int i = 1; i <= n; i++) {
        tree.updCount(arr[i], 1);
    }
    for (int i = 0; i <= n; i++) {
        tree.upd(arr[i], arr[i + 1], 1);
    }
    for (int i = 0; i < q; i++) {
        int pos, val;
        cin >> pos >> val;
        tree.addToTree(pos, -1);
        arr[pos] = val;
        tree.addToTree(pos, 1);
        cout << tree.query(0, maxV) << endl;
    }
    flush(cout);
    return 0;
}