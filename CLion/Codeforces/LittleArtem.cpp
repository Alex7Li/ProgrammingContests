# include <bits/stdc++.h>
// http://codeforces.com/contest/1333/problem/A

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
    int t, n ,m;
    cin >> t;
    rep(tt, 0, t){
        cin >> n >> m;
        rep(i, 0, n){
            rep(j, 0, m){
                if(j==m-1 && i==n-1){
                    cout << "W";
                }else {
                    cout << "B";
                }
            }
            cout <<"\n";
        }
    }
    return 0;
}