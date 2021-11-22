# include <bits/stdc++.h>
//http://codeforces.com/contest/1334/problem/D
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, l, r;

void gofrom(ll last, ll next, ll ind) {
    if (l <= ind && ind <= r) {
        cout << last << " ";
    }
}

void solve(ll nodes, ll st) {
    if (st > r || nodes == 1) {
        return;
    }
    ll end = 2 * (nodes - 1) + st;
    while (end < l) {
        nodes--;
        st = end;
        end = 2 * (nodes - 1) + st;
    }
    ll minNode = n - nodes + 1;
    gofrom(n, minNode, st++);
    for (ll next = minNode + 1; next < n; next++) {
        gofrom(minNode, next, st++);
        gofrom(next, minNode, st++);
    }
    gofrom(minNode, n, st++);
    assert(st == end);
    solve(nodes - 1, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t) {
        cin >> n >> l >> r;
        if (l < n * (n - 1)) {
            ll st = 1;
            for (ll next = 2; next < n; next++) {
                gofrom(1, next, st++);
                gofrom(next, 1, st++);
            }
            gofrom(1, n, st++);
            solve(n - 1, st);
        }
        gofrom(n, 1, (n * (n - 1)));
        gofrom(1, 1, (n * (n - 1)) + 1);
        cout << "\n";
    }
    return 0;
}