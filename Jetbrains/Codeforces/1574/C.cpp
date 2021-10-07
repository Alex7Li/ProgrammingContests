# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll solve(vector<ll>& a, ll x, ll y, ll sum){
    int l = -1;
    int maxV = 1 << (int)(log2(1 + a.size()));
    for (int i = maxV; i != 0; i/=2)
    {
        if(l + i < a.size() && a[l + i] < x){
            l += i;
        }
    }
    ll ans = LONG_LONG_MAX;
    if(l != -1){
        assert(a[l] <  x);
        ans = max(0LL, y - (sum - a[l]));
        ans += x - a[l];
    }
    l++;
    if(l != a.size()) {
        assert(a[l] >= x);
        ans = min(ans, max(0LL, y - (sum - a[l])));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    vector<ll> pSum(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        cout << solve(a, x, y, sum) << "\n";
    }
    return 0;
}