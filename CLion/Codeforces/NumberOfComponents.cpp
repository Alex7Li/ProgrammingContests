# include <bits/stdc++.h>
//https://codeforces.com/contest/1270/problem/H
// In this solution, I falsely assumed that the query result could never increase
// by more than 1. I think it's right under that assumption despite being chaotically complex.
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, q;
vi a;


typedef pii T;
static constexpr T unit = pii(INT_MAX, INT_MIN);

struct Tree {
    static T f(T aval, T b) { return pii(min(aval.first, b.first), max(aval.second, b.second)); }

    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : s(static_cast<unsigned int>(2 * n), def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }

    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
} tree;

struct Component {
    int l, r, minV, maxV;

    bool operator<(Component o) const {
        // still a total ordering, but now we can search tree sets based on multiple keys
        if ((r == -1 || o.r == -1) && (minV != o.minV)) {
            return minV > o.minV;
        } else if ((r == -2 || o.r == -2) && (maxV != o.maxV)) {
            return maxV > o.maxV;
        } else if (l != o.l) {
            return l < o.l;
        } else {
            return r < o.r;
        }
    }
};

set<Component> comps;

void check() {
    for (Component c:comps) {
        assert(c.l < c.r);
        assert(c.minV <= c.maxV);
        cout << c.l << "_" << c.r << "_" << c.minV << "_" << c.maxV << "_";
    }
    for (auto it = comps.begin(); it != comps.end();) {
        Component x = *it++;
        if (it == comps.end()) {
            break;
        }
        Component y = *it;
        assert(x.r == y.l);
        assert(x.minV >= y.maxV);
    }
}

void insertMerged(Component l, Component r){
    if(l.l == l.r){
        comps.insert(r);
    }else if(r.l == r.r){
        comps.insert(l);
    }else if(l.minV >= r.maxV){
        comps.insert(l);
        comps.insert(r);
    }else{
        comps.insert({l.l, r.r, min(l.minV, r.minV), max(l.maxV, r.maxV)});
    }
}

int update(int ind, int val) {
    a[ind] = val;
    tree.update(ind, pii(val, val));
    // see if we destroy the component a belongs to
    auto oldComp = comps.upper_bound({ind, n, 0, 0});
    if (oldComp != comps.begin()) {
        oldComp--;
    }
    int rBound = oldComp->r, lBound = oldComp->l;
    pii before = tree.query(oldComp->l, ind);
    pii after = tree.query(ind + 1, oldComp->r);
    if (before.first < val && val < after.second) {
        return comps.size();
    }
    // no connection to the right side
    if (val >= tree.query(ind + 1, n).second
         // also, a left merge will go all the way to the left
         && (before == unit || before.first < val)) {
        // merge left side
        Component leftComp = {lBound, ind + 1, min(val, before.first), max(val, before.second)};
        auto mergeComp = comps.upper_bound({lBound, -1, val, 0});
        if (mergeComp != comps.end() && val > mergeComp->minV && ind >= mergeComp->r) {
            leftComp.l = mergeComp->l;
            while (oldComp != mergeComp) {
                leftComp.maxV = max(leftComp.maxV, mergeComp->maxV);
                leftComp.minV = min(leftComp.minV, mergeComp->minV);
                mergeComp = comps.erase(mergeComp);
            }
        }
        comps.erase(oldComp);
        Component rComp = {ind + 1, rBound, after.first, after.second};
        insertMerged(leftComp, rComp);
    } else {
        Component rightComp = {ind, rBound, min(val, after.first), max(val, after.second)};
        auto mergeComp = comps.lower_bound({ind, -2, 0, val});
        if ((mergeComp == comps.end()) ||
            (mergeComp != comps.begin() && mergeComp != oldComp && val >= mergeComp->minV)) {
            mergeComp--;
        }
        if (val < mergeComp->maxV && ind < mergeComp->l) {
            rightComp.r = mergeComp->r;
            while (oldComp != mergeComp) {
                oldComp = comps.erase(oldComp);
                rightComp.minV = min(rightComp.minV, oldComp->minV);
                rightComp.maxV = max(rightComp.maxV, oldComp->maxV);
            }
        }
        comps.erase(oldComp);
        Component lComp = {lBound, ind, before.first, before.second};
        insertMerged(lComp, rightComp);
    }
    return comps.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    tree = Tree(n, pii(0, 0));
    a = vi(n, 0);
    comps.insert({0, n, 0, 0});
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }
    for (int i = 0; i < q; i++) {
        int pos, val;
        cin >> pos >> val;
        cout << update(pos - 1, val) ;
    }
    flush(cout);
    return 0;
}