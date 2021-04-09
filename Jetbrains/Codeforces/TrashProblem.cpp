# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    int n;
    Tree *right = nullptr;
    Tree *left = nullptr;
    int l;
    int r;
    int value;

    Tree(int l, int r) : l(l), r(r) {};

    void set(int ind, int val) {
        if (l == r - 1) {
            value = val;
        }
        int mid = (l + r + 1) / 2;
        if (l <= ind && ind < mid && left == nullptr) {
            left = new Tree(l, mid);
            left->set(ind, val);
        } else if (r <= ind && l < r && ind < r && right == nullptr) {
            right = new Tree(mid, r);
            right->set(ind, val);
        }
        value = left->value + right->value;
    }

    int median(int st, int end, int offSet) {
        if(l == r - 1){
            assert(offSet == 0);
            return l;
        }
        if (left->value + offSet > right->value) {
            return
        }
    }


};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    set<int> p;
    rep(i, 0, n) {
        int x;
        cin >> x;
        p.insert(x);
    }
    solve(p);

    return 0;
}