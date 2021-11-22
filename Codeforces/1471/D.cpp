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
    int n = 5;
    int k = 91;
    vi a(n);
    for (int i = 0; i < n; i++) {
        a[i] = k;
    }
    for (int i = 0; i < 30; i++) {
        vi b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[(i + 1) % n] / 2 + (a[(i + n - 1) % n] + 1) / 2;
        }
        b[n - 1] = (a[n - 2] + 1) / 2;
        b[1] = a[0] + a[2] / 2;
        a = b;
        for (int j = 0; j < n; ++j) {
            cout << b[j] << " ";
        }
        cout << endl;
    }
    return 0;
}