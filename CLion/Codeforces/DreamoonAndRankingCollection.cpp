# include <bits/stdc++.h>
//https://codeforces.com/contest/1330/problem/A
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
    rep(ntimes, 0 , t) {
        int n, x;
        cin >> n  >> x;
        set<int> a;
        rep(i, 0, n) {
            int v;
            cin >> v;
            a.insert(v);
        }
        for(int v = 300; v > 0; v--){
            int in = 0;
            for(auto el = a.cbegin(); el != a.lower_bound(v+1); el++){
                in++;
            }
            if(v - in <= x){
                cout << v << endl;
                break;
            }
        }
    }

    return 0;
}