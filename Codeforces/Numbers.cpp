# include <bits/stdc++.h>
//http://codeforces.com/gym/101964/attachments/download/7814/seerc-2018.pdf
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
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    int div = 0;
    if (a == b && b == c) {
        div = 6;
    } else if (a == b || b == c || a == c) {
        div = 2;
    }
    ll m = n / 2;
    unsigned long long f1;
    unsigned long long f2;
    unsigned long long f3;
    if (n % 2 == 0LL) {
        f1 = 2 * m;
        f2 = m - 1;
        f3 = m + 4;
    } else {
        f1 = m;
        f2 = m + 1;
        f3 = 2 * m + 1;
    }
    if (div == 6) {
        if (f1 % 3 == 0) {
            f1 /= 3;
        } else if (f2 % 3 == 0) {
            f2 /= 3;
        } else {
            assert(f3 % 3 == 0);
            f3 /= 3;
        }
    }
    if (div == 6 || div == 2) {
        if (f1 % 2 == 0) {
            f1 /= 2;
        } else {
            assert(f2 % 2 == 0);
            f2 /= 2;
        }
    }
    cout << f1 * f2 * f3;
    return 0;
}