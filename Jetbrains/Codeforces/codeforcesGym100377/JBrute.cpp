# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

struct Rect {
    ll w;
    ll h;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Rect> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].w;
        cin >> a[i].h;
    }
    sort(a.begin(), a.end(), [](Rect a, Rect b) {
        return a.h == b.h ? a.w > b.w : a.h > b.h;
    });
    vector<Rect> r;
    r.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i].w >= r[r.size() - 1].w) {
            r.push_back(a[i]);
        }
    }

    vector<ll> dp(r.size() + 1);
    dp[0] = 0;
    deque<pii> points;
    for (int i = 1; i < dp.size(); i++) {
        dp[i] = dp[i - 1] + r[i - 1].w * r[i - 1].h;
        for (int j = 0; j < i; j++) {
            // dp[i] = max_k(dp[k] + w[i]*h[k]);
            dp[i] = min(dp[i], dp[j] + r[i - 1].w * r[j].h);
        }
    }
    cout << dp[r.size()] << '\n';
    return 0;
}