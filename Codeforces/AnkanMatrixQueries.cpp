# include <bits/stdc++.h>
//http://codeforces.com/gym/101964/problem/G
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Ankan {
    vector<int> rows;
    vector<ll> mono;
    int n;

    Ankan(int m) {
        n = m;
        rows = vector<int>(1 << (n + 1), 1);
        mono = vector<ll>(n + 1);
        for (int i = 0; i <= n; ++i) {
            mono[i] = 1 << i;
        }
    }

    void update(int x) {
        x += 1 << n;
        rows[x] *= -1;
        int i = n - 1;
        for (x >>= 1; x > 0; x >>= 1, --i) {
            int u = rows[2 * x];
            int v = rows[2 * x + 1];
            int prev = rows[x];
            if (u == v && u != 0) {
                rows[x] = u;
            } else {
                rows[x] = 0;
            }
            mono[i] += rows[x] ? 1 : 0;
            mono[i] -= prev ? 1 : 0;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    // +1 white
    // -1 black
    //  0 mixed
    Ankan rows = Ankan(n);
    Ankan cols = Ankan(n);
    ll num = 0;
    ll cost;
    for (int i = 0; i < q; i++) {
        num = 0;
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 0) {
            rows.update(x);
        } else {
            cols.update(x);
        }
        for (int j = 0; j <= n; ++j) {
            num += rows.mono[j] * cols.mono[j];
        }
        cost = -4LL * num + ((1LL << (2LL * n + 4LL)) - 1LL) / 3LL;
        cout << cost << "\n";
    }
    return 0;
}