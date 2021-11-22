# include <bits/stdc++.h>
//http://codeforces.com/contest/1340/problem/A
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
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, 0, n){
            cin >> a[i];
        }
        int minV = a[0];
        bool possible = true;
        for(int i = 0; i < n - 1; i++){
            if(a[i]+1 == a[i+1]){
                continue;
            }else{
                if(minV > a[i+1]){
                    minV = a[i+1];
                }else{
                    possible = false;
                }
            }
        }
        cout << (possible?"Yes":"No") << "\n";
    }
    return 0;
}