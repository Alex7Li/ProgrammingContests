# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        a[i] = query(1, i);
    }
    int q = query(2, n);
    vector<int> b(n);
    b[0] = a[n] - q;
    a[1] = b[0];
    for (int i = 1; i < n; i++) {
        b[i] = a[i + 1] - a[i];
    }
    cout << "!";
    for(int i = 0; i < n; i++){
        cout << " " << b[i];
    }
    cout << endl;
    return 0;
}