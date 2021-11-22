# include <bits/stdc++.h>
//https://codeforces.com/contest/1312/problem/B
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
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for(int j = 0; j < n - 1; j++){
            cout << a[j] << " ";
        }
        cout << a[n-1] << "\n";
    }
    return 0;
}