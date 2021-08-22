# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef vector<ll> vi;
// https://napc21.kattis.com/sessions/craf4z/problems/napc21.icecreamcones
// Could not submit, passes test cases though.

// Return 1 + 2 + ... + n
ll sum_to(ll n) {
    return (n * (n + 1)) / 2;
}

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll madd = 0, mset = -1, count = 0, cost = 0;
    Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
    ll query_count(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return count;
        push();
        return l->query_count(L, R) + r->query_count(L, R);
    }
    ll query_cost(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return cost;
        push();
        return l->query_cost(L, R) + r->query_cost(L, R);
    }
    void add_range(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != -1) {
                mset += x;
            } else {
                madd += x;
            }
            count += (hi - lo) * x;
            cost += (sum_to(hi - 1) - sum_to(lo - 1)) * x;
        } else {
            push(), l->add_range(L, R, x), r->add_range(L, R, x);
            count = l->count + r->count;
            cost = l->cost + r->cost;
        }
    }
    void set_range(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd = 0;
            mset = x;
            count = (hi - lo) * x;
            cost = (sum_to(hi - 1) - sum_to(lo - 1)) * x;
        } else {
            push(), l->set_range(L, R, x), r->set_range(L, R, x);
            count = l->count + r->count;
            cost = l->cost + r->cost;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != -1) {
            l->set_range(lo, hi, mset), r->set_range(lo, hi, mset), mset = -1;
        } else if (madd) {
            l->add_range(lo, hi, madd), r->add_range(lo, hi, madd), madd = 0;
        }
    }
};

const ll MAX = 2'000'004;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Node tree(0, MAX);
    for (int i = 0; i < n; ++i) {
        string op;
        ll a, b;
        cin >> op;
        if (op == "ADD") {
            cin >> a >> b; // Add a cones of cost b
            tree.add_range(b, b + 1, a);
        } else if (op == "ADDRANGE") {
            cin >> a >> b; // Add a cone to the interval [a, b]
            tree.add_range(a, b + 1, 1);
        } else if (op == "BUYAMT") {
            cin >> a; // Buy a cones
            int lo = 0;
            for (int j = 1 << (int) (log2(MAX)); j != 0; j >>= 1) {
                if (tree.query_cost(0, lo + j) <= a) {
                    lo += j;
                }
            }
            ll bought = tree.query_count(0, lo);
            ll left_to_buy = (a - tree.query_cost(0, lo)) / lo;
            tree.set_range(0, lo, 0);
            bought += left_to_buy;
            tree.add_range(lo, lo + 1, -left_to_buy);
            cout << bought;
        } else if (op == "BUYLOW") {
            cin >> a;
            int lo = 0;
            for (int j = 1 << (int) (log2(MAX)); j != 0; j >>= 1) {
                if (tree.query_count(0, lo + j) <= a) {
                    lo += j;
                }
            }
            ll cost = tree.query_cost(0, lo);
            ll left_to_buy = a - tree.query_count(0, lo);
            tree.set_range(0, lo, 0);
            cost += lo * left_to_buy;
            tree.add_range(lo, lo + 1, -left_to_buy);
            cout << cost;
        } else if (op == "COST") {
            cin >> a;
            int hi = 1 << (int) (log2(MAX) + 1);
            for (int j = 1 << (int) (log2(MAX)); j != 0; j >>= 1) {
                if (tree.query_count(0, hi - j) >= a) {
                    hi -= j;
                }
            }
            cout << hi - 1;
        } else if (op == "BUYHIGH") {
            cin >> a;
            int hi = 1 << (int) (log2(MAX) + 1);
            for (int j = 1 << (int) (log2(MAX)); j != 0; j >>= 1) {
                if (tree.query_count(hi - j, MAX) <= a) {
                    hi -= j;
                }
            }
            ll cost = tree.query_cost(hi, MAX);
            ll left_to_buy = a - tree.query_count(hi, MAX);
            tree.set_range(hi, MAX, 0);
            cost += left_to_buy * (hi - 1);
            tree.add_range(hi - 1, hi, -left_to_buy);
            cout << cost;
        } else if (op == "NUMCONES") {
            cout << tree.query_count(0, MAX);
        } else if (op == "TOTALCOST") {
            cout << tree.query_cost(0, MAX);
        }
        if (op != "ADD" && op != "ADDRANGE") {
            if (n < 1000) {
                cout << endl;
            } else {
                cout << "\n";
            }
        }
    }
    return 0;
}