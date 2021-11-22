# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, int> pii;
typedef vector<ll> vi;
ll n, t, k;
vi distances;
vi costs;
ll min(ll a, ll b) {
    return a > b ? b : a;
}
ll max(ll a, ll b) {
    return b > a ? b : a;
}
ll mult(ll a, ll b) {
    if (a == 0) {
        return 0;
    }
    if (a == -1 || b == -1 || LLONG_MAX / a <= b) {
        return -1;
    }
    return a * b;
}
ll add(ll a, ll b) {
    if (a == -1 || b == -1 || LLONG_MAX - a < b) {
        return -1;
    }
    return a + b;
}
pair<ll, ll> try_cost(ll maxPayment) {
    ll total_cost = 0;
    ll total_built = 0;
    ll maxC = 0;
    for (int i = 0; i < k; ++i) {
        ll distOut = max((maxPayment - costs[i] + t) / t, 0);
        if(distOut == 0) {
            continue;
        }
        maxC = max(maxC, costs[i] + (distOut - 1) * t);
        ll built = mult(mult(2, distOut), distOut + 1);
        ll base_cost = mult(built, costs[i]);
        ll tmp = mult(built, (2 * distOut + 1));
        if (tmp == -1 || built == -1) {
            return {-1, -1}; // overflow
        }
        ll walk_cost = mult(tmp / 3 - built, t);
        total_cost = add(total_cost, add(walk_cost, base_cost));
        total_built = add(total_built, built);
        if (total_built == -1 || total_cost == -1) {
            return {-1, -1}; // overflow
        }
    }
    if (total_built < n) {
        return {LLONG_MAX, LLONG_MAX}; // Need to build more
    }
    total_cost -= (total_built - n) * maxC;
    return {total_built, total_cost};
}
ll solve() {
    ll st = LLONG_MAX;
    pair<ll, ll> best_cost = {LLONG_MAX, -1};
    for (ll extra = (1LL << 62); extra != 0; extra /= 2) {
        pair<ll, ll> c = try_cost(st - extra);
        if (c == pair<ll, ll>{-1LL, -1LL}) {
            st -= extra; // overflow we are way too big
        } else if (c <= best_cost) {
            best_cost = c;
            st -= extra;
        } else {
            continue;
        }
    }
    return try_cost(st).second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t >> k;
    distances = vi(k);
    costs = vi(k);
    for (int i = 0; i < k; ++i) {
        cin >> costs[i];
    }
    cout << solve() << endl;
    return 0;
}