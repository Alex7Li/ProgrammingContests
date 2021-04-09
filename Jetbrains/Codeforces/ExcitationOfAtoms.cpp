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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<ll> post(n);
    ll sum = a[n - 1];
    post[n - 1] = max(0LL, a[n - 1] - d[n - 1]);
    ll score = max(0LL, post[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        sum += a[i];
        post[i] = max(post[i + 1], sum - d[i]);
        if (i != 0) {
            score = max(score, post[i]);
        }
    }
    if (k == 0) {
        score = max(score, post[0]);
    } else if (k == 1) {
        vector<ll> pre(n);
        ll minD = d[0];
        sum = a[0];
        for (int i = 1; i < n - 1; i++) {
            minD = min(minD, d[i]);
            sum += a[i];
            pre[i] = max(0LL, sum - minD);
            score = max(pre[i] + post[i + 1], score);
        }
        sum += a[n - 1];
        score = max(score, sum - d[0] - a[1]);
    } else {
        // We can just get them all or just the last.
        ll score2 = 0;
        ll minV = d[0];
        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                minV = min(d[i], minV);
            }
            score2 += a[i];
        }
        score2 -= minV;
        score = max(max(score, score2), a[n - 1] - d[n - 1]);
    }
    cout << score << endl;
    return 0;
}