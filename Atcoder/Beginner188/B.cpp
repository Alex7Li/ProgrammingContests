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
    vi a(n);
    vi b(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, n){
        cin >> b[i];
    }
    ll sum = 0;
    rep(i, 0, n) {
        sum += a[i] * b[i];
    }
    cout << (sum==0?"Yes":"No");
    return 0;
}