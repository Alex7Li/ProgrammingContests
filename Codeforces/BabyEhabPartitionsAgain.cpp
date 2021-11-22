# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1516/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool good(vi &a) {
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % 2 != 0) {
        return true;
    }
    int goal = sum / 2;
    vector<bool> possible(2 * sum, false);
    possible[0] = true;
    for (int x : a) {
        for (int i = goal; i >= 0; i--) {
            if (possible[i]) {
                possible[i + x] = true;
            }
        }
    }
    return !possible[goal];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    int gc = 2048;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        gc = gcd(gc, a[i]);
    }
    for (int i = 0; i < n; i++) {
        assert(a[i] % gc == 0);
        a[i] /= gc;
    }
    if (good(a)) {
        cout << 0 << '\n';
    } else {
        int odd = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 != 0) {
                odd = i;
            }
        }
        assert(odd != -1);
        cout << 1 << "\n" << odd + 1 << "\n";
    }
    return 0;
}