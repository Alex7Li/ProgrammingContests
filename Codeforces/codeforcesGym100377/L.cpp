# include <bits/stdc++.h>
//https://codeforces.com/gym/100377/attachments/download/2401/2014-zimnyaya-shkola-po-programmirovaniu-harkov-dyen-4-ya-tvyerdohlyeb-r-yedyemskiy-vysshaya-liga-en.pdf
using namespace std;
# define OFFSET 1'000'001
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct City {
    ll x, c, t;
};

// Li Chao tree holding linear functions f_{a, b}(x) = xa + b
// (functions such that any two intersect at most once)
// with the ability to get the max-valued function at a point on the interval [1, N].
struct LiChao {
    typedef pii Function;

    ll eval(Function l, ll point) {
        return l.first * point + l.second;
    }

    vector<Function> s;
    int n;

    LiChao(int n) : s(n * 2, {0, -1e16}), n(n) {}

    void update(Function insert) {
        update(insert, 0, n, 1);
    }

    // The following is maintained: The maximum valued function (besides f) is on a path from the root to a leaf.
    void update(Function f, int l, int r, int ind) {
        if (l + 1 == r) {
            return;
        }
        int mid = (l + r) / 2;
        bool betterL = eval(f, l) > eval(s[ind], l);
        bool betterM = eval(f, mid) > eval(s[ind], mid);
        if (betterM) { // one half is dominated by f
            // s[ind] = f so the half that the function dominates on will be on a path from the root to the leaf.
            // We don't need to work about f anymore, but the function previously stored in s[ind] isn't
            // accounted for, so let f = s[ind] and recurse.
            swap(s[ind], f);
        }
        if (betterL ^ betterM) { // The function changes value in the left half
            update(f, l, mid, ind * 2);
        } else { // right half
            update(f, mid, r, ind * 2 + 1);
        }
    }

    ll query(int val) {
        ll maxV = 0;
        for (int i = val + n; i != 0; i /= 2) {
            maxV = max(maxV, eval(s[i], val));
        }
        return maxV;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<City> cities(n);
    rep(i, 0, n) {
        cin >> cities[i].x >> cities[i].c >> cities[i].t;
        cities[i].x += OFFSET;
    }
    vector<ll> maxC(n, 0);
    LiChao tree(1<<21);
    rep(i, 1, n) {
        // ll cost1 = (-cities[j].c * cities[i].x) + (cities[j].c * cities[j].x) + cities[i].t;
        // ll cost2 = (cities[j].c * cities[i].x) - (cities[j].c * cities[j].x) + cities[i].t;
        tree.update({-cities[i - 1].c, cities[i - 1].c * cities[i - 1].x + maxC[i-1]});
        tree.update({cities[i - 1].c, -cities[i - 1].c * cities[i - 1].x + maxC[i-1]});
        // maxC[i] = max(maxC[i], maxC[j] + max(cost1, cost2));
        maxC[i] = tree.query(cities[i].x) + cities[i].t;
    }
    cout << maxC[n - 1] << "\n";
    return 0;
}