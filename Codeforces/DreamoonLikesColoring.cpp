# include <bits/stdc++.h>
//https://codeforces.com/contest/1330/problem/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void impos() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        sum += l[i];
    }
    if (sum < n) {
        impos();
    }
    vector<int> p(m + 1);
    p[m] = n;
    for (int i = m - 1; i >= 0; i--) {
        sum -= l[i];
        p[i] = min(sum, p[i + 1] - 1LL);
        p[i] = min(p[i], n - l[i]);
        if (p[i] < 0 || p[i + 1] - p[i] > l[i]) {
            impos();
        }
    }
    for (int i = 0; i < m; i++) {
        cout << p[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}