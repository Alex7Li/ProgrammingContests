# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

bool canMake(vi &a, int l, int S) {
    if (S % l != 0) {
        return false;
    }
    int v = S / l;
    int sum = 0;
    rep(i, 0, n) {
        sum += a[i];
        if (sum > v) {
            return false;
        }
        if(sum==v){
            sum = 0;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> n;
        vi a(n);
        int S = 0;
        rep(i, 0, n) {
            cin >> a[i];
            S += a[i];
        }
        int l = n;
        for (; l >= 1; --l) {
            if (canMake(a, l, S)) {
                break;
            }
        }
        cout << n-l << "\n";
    }
    return 0;
}
