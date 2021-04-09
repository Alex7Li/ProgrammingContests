# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1334/A
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
    int t, n;
    cin >> t;
    rep(tt, 0, t) {
        cin >> n;
        vector<int> p(n);
        vector<int> c(n);
        rep(i, 0, n) {
            cin >> p[i] >> c[i];
        }
        bool pos = true;
        if (c[0] > p[0]) {
            pos = false;
        } else {
            rep(i, 1, n) {
                if (p[i] - c[i] < p[i - 1] - c[i - 1]) {
                    pos = false;
                }
                if (c[i] < c[i - 1] || p[i] < p[i - 1]) {
                    pos =  false;
                }
            }
        }
        if(pos){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}