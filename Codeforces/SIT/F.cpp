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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    if(m==1){
        cout << n << endl;
    }else {
        for (int d = 1; d < n; ++d) {
            ll l = (m - 1) * d + 1;
            ans += max(n - l + 1, 0LL);
        }
        cout << ans << endl;
    }
    return 0;
}