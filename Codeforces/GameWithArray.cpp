# include <bits/stdc++.h>
//http://codeforces.com/problemset/problem/1355/D
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
    rep(i,0,a){

    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    if(s < 2*n){
        cout << "NO" << "\n";
    }else{
        cout << "YES" << "\n";
        for(int i = 0; i < n-1; i++){
            cout << 2 << " ";
        }
        cout << s - 2*(n-1) << "\n";
        cout << 1 << "\n";
    }
    return 0;
}