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
    int n;
    cin >> n;
    vi b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    vi a(n);
    for (int i = 0; i <= n/2; ++i) {
        if (2 * i < n) {
            a[2 * i] = b[i];
        }
        if (2 * i + 1 < n) {
            a[2 * i + 1] = b[n - i - 1];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << a[i] << " ";
    }
    cout << a[n- 1];
    cout << endl;
    // get answer
    bool has = false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1] && has) {
            cout << "S";
            has = false;
        } else if (a[i] < a[i + 1] && !has) {
            cout << "B";
            has = true;
        } else {
            cout << "E";
        }
    }
    if (has) {
        cout << "S";
    } else {
        cout << "E";
    }
    cout << endl;
    return 0;
}