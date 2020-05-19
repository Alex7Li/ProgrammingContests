# include <bits/stdc++.h>
//http://codeforces.com/problemset/problem/1344/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t){
        bool possible = true;
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> used(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] = (a[i])%n;
            used[(a[i]+i+n)%n] = true;
        }
        for(int i = 0; i < n; i++){
            if(!used[i]){
                possible = false;
            }
        }
        cout << (possible?"YES":"NO") << "\n";
    }
    return 0;
}