# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1326/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> a(n);
    int maxV = 0;
    rep(i, 0, n){
        cin >> b[i];
    }
    rep(i, 0, n){
        a[i] = b[i] + maxV;
        maxV = max(a[i], maxV);
    }
    rep(i, 0, n-1){
        cout << a[i] << " ";
    }
    cout << a[n-1] << "\n";
    return 0;
}