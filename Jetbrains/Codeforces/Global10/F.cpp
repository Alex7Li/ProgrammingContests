# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    sum -= (n * (n - 1)) / 2;
    ll q = sum / n;
    ll rem = sum % n;
    cout << q + min(rem, 1LL);
    rep(i, 1, n) {
        cout << " " << q + i + max(min(rem - i, 1LL), 0LL);
    }
    return 0;
}