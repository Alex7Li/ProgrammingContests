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
    ll n, nRem = 0;
    cin >> n;
    ll x, m;
    ll b, e, times;
    cin >> x >> m;
    map<ll, int> seen;
    seen[x] = 1;
    vector<ll> sum;
    sum.push_back(0);
    sum.push_back(x);
    for (int i = 2; i < m + 5; i++) {
        x = (x * x) % m;
        sum.push_back(sum[i - 1] + x);
        if (seen.find(x) != seen.end()) {
            b = seen[x];
            e = i;
            times = (n - e) / (e - b);
            nRem = (n - e) % (e - b);
            cout << sum[e - 1] + (sum[e - 1] - sum[b - 1]) * times + (sum[b + nRem] - sum[b - 1]);
            return 0;
        }
        seen[x] = i;
        if (i == n) {
            cout << sum[i] << endl;
            return 0;
        }
    }
    return 0;
}