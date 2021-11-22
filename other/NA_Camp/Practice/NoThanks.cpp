# include <bits/stdc++.h>

using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
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
    vector<int> a(n);
    a.push_back(-2);
    a.push_back(90002);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    ll ans = 0;
    cout << "          \n      ";
    for (int i = 1; i < a.size() - 1; ++i) {
        if(a[i] - 1 != a[i - 1]) {
            ans += a[i];
        }
    }
    cout << ans;
    cout << "            \n    ";
    cout << endl;
    return 0;
}