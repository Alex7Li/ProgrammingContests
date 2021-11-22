# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
T gcd(T a, T b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        ll a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES\n";
            cout << a << " " << a * b << " " << a * (b + 1) << "\n";
        }
    }
    return 0;
}