# include <bits/stdc++.h>
//https://maps20.kattis.com/problems/maps20.magicalcows
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll cap, n, m;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> count;
    cin >> cap >> n >> m;
    ll tmp;
    rep(i, 0, n) {
        cin >> tmp;
        count.push_back(tmp);
    }
    vector<ll> days;
    rep(i, 0, m) {
        cin >> tmp;
        days.push_back(tmp);
    }
    trav(d, days) {
        ll ans = 0;
        trav(c, count) {
            ll cur = c;
            ll daysLeft = d + 1;
            while(cur <= cap && daysLeft > 0){
                daysLeft--;
                cur *= 2L;
            }
            ans += (1LL << daysLeft);
        }
        cout << ans << endl;
    }
    return 0;
}