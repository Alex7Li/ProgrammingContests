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
    for(int tt = 0; tt < t; tt++){
        ll min = 0;
        int n;
        int x;
        cin >> n >> x;
        ll sum = 0;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            min += (a[i]+x-1) / x;
        }
        cout << (sum+x-1)/x << " " << min << "\n";
    }

    return 0;
}
