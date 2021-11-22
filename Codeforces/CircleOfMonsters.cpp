# include <bits/stdc++.h>
//http://codeforces.com/contest/1334/problem/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        rep(i, 0, n){
            cin >> a[i] >> b[i];
        }
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] < a[(i + 1) % n]) {
                ll shots = a[(i + 1) % n] - b[i];
                cost += shots;
                a[(i + 1) % n] -= shots;
            }
        }
        ll minHP = a[0];
        for(int i = 0; i < n; i++){
            minHP = min(a[i], minHP);
        }
        cout << (cost + minHP) << "\n";
    }
    return 0;
}