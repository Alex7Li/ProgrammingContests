# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> x(n);
    rep(i, 0, n) {
        cin >> x[i].first >> x[i].second;
    }
    sort(x.begin(), x.end());
    vi h(n); // height is beauty
    vi c(n);
    rep(i, 0, n) {
        h[i] = x[i].first;
        c[i] = x[i].second;
    }

    ll cost = 0;
    int freeH = h[0] + c[0];
    for (int i = 1; i < n; ++i) {
        if (h[i] > freeH) {
            cost += h[i] - freeH;
        }
        freeH = max(freeH, h[i] + c[i]);
    }
    for (int i = 0; i < n; ++i) {
        cost += c[i];
    }
    cout << cost;
    return 0;
}