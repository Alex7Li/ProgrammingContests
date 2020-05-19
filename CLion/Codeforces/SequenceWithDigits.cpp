# include <bits/stdc++.h>
//http://codeforces.com/problemset/problem/1355/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int digit(ll num, bool max) {
    int best = max ? -1 : 10;
    while (num > 0) {
        int dig = num % 10;
        num /= 10;
        if (max) {
            if (dig > best) {
                best = dig;
            }
        } else {
            if (dig < best) {
                best = dig;
            }
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t) {
        ll a;
        ll K;
        cin >> a >> K;
        int ind = 1;
        while (digit(a, false) > 0 && ind < K) {
            a += digit(a, true) * digit(a, false);
            ind++;
        }
        cout << a << "\n";
    }
    return 0;
}