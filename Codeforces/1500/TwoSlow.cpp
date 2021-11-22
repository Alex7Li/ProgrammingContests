# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    vi b(m);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, m) {
        cin >> b[i];
    }
    ll mad = 0;
    int i = 0;
    while (mad < k) {
        if (a[i % n] != b[i % m]) {
            mad++;
        }
        i++;
    }
    cout << i << endl;
    return 0;
}