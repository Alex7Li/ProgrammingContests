# include <bits/stdc++.h>
//http://codeforces.com/contest/1334/problem/B
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
        ll n, x;
        cin >> n >> x;
        vector<int> a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll sum = 0;
        int ind = 0;
        while (ind < n && sum >= x * ind) {
            sum += a[n-ind-1];
            ind++;
        }
        if (ind == n) {
            if (sum >= x * ind) {
                ind++;
            }
        }
        cout << (ind - 1) << "\n";
    }
    return 0;
}