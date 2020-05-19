# include <bits/stdc++.h>
//https://codeforces.com/contest/1312/problem/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    rep(t, 0, T) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        bool possible = true;
        ll p = 1LL;
        while(p < 100'000'000'000'000'000LL){
            bool used = false;
            rep(i, 0, n) {
                if (a[i] % (p*k) == p) {
                    if (used) {
                        possible = false;
                    }
                    used = true;
                    a[i] -= p;
                } else if (a[i] % (p*k) != 0) {
                    possible = false;
                }
            }
            p *= k;
        }
        rep(i, 0, n){
            if(a[i]!=0){
                possible = false;
            }
        }
        if (possible) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}