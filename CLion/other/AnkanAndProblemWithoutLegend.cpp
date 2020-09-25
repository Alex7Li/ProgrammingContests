# include <bits/stdc++.h>

# define MOD 1'000'000'009

typedef long long ll;
// A problem by Ankan Bhattacharya:
// Given f(x, y, z) = (x^2+2yz, y^2 + 2xz, z^2 + 2xy), compute f^q(x,y,z) mod p.
// Where f is composed with itself q times.
// The answer is to use roots of unity... (Didn't solve)
// f^q(x + yw + zw^2) = (x + yw + zw^2)^q, we can find
// a root of unity in 10^9+9 & use fast power
// q <= 10^18.
using namespace std;

void print(tuple<ll, ll, ll> t) {
    ll a = get<0>(t);
    ll b = get<1>(t);
    ll c = get<2>(t);
    cout << a << " " << b << " " << c << "\n";
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

tuple<ll, ll, ll> f(tuple<ll, ll, ll> t) {
    ll a = get<0>(t);
    ll b = get<1>(t);
    ll c = get<2>(t);
    ll x = (a * a + 2 * b * c) % MOD;
    ll y = (b * b + 2 * a * c) % MOD;
    ll z = (c * c + 2 * a * b) % MOD;
    return make_tuple(x, y, z);
}

tuple<ll, ll, ll> trivial(tuple<ll, ll, ll> t, int times) {
    for (int i = 1; i <= times; i++) {
        t = f(t);
        print(t);
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    trivial(make_tuple(a, b, c), 30);
    return 0;
}