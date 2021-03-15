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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, x;
        cin >> n >> x;
        ll sum = 0;
        vector<ll> v(n);
        vector<ll> w(n, 1);
        rep(i, 0, n) {
            cin >> v[i];
        }
        int i = 0;
        for (; i < v.size(); i++) {
            int temp = v[i];
            if (temp % x == 0) {
                temp /= x;
                v.push_back(temp);
                w.push_back(w[i] * x);
            } else {
                break;
            }
        }
        for(int i = 0; i < v.size(); i++){
            sum += v[i] * w[i];
        }
        cout << sum << "\n";
    }
    return 0;
}