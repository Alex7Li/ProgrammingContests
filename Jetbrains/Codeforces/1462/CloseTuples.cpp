# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1'000'000'007LL;

// return a % b (positive value)
int mod(int a, int b) {
    return ((a % b) + b) % b;
}

// returns g = gcd(a, b); finds x, y such that d = ax + by
int extended_euclid(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
int mod_inverse(int a) {
    int x, y;
    int g = extended_euclid(a, MOD, x, y);
    if (g > 1) return -1;
    return mod(x, MOD);
}

ll binom(int n, int k) {
    ll prod = 1;
    rep(i, (n - k), n + 1) {
        prod = mod(prod * i, MOD);
    }
    rep(i, 1, k + 1) {
        prod = mod(prod * mod_inverse(i), MOD);
    }
    return prod;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        rep(i, 0, n){
            cin >> a[i];
        }
        int p2 = k;
        rep(p1, 0, n - k) {
            while(p1 < p2){
                p2++;
                if(p2 > n){
                    break;
                }
            }
        }
    }
    return 0;
}