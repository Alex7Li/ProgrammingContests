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
    int n, q;
    cin >> n >> q;
    vi a(n);
    int ones = 0;
    rep(i, 0, n) {
        cin >> a[i];
        if (a[i] == 1) {
            ones++;
        }
    }
    rep(i, 0, q) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            v--;
            if (a[v] == 1) {
                ones--;
            } else {
                ones++;
            }
            a[v] = 1 - a[v];
        } else {
            if(v <= ones){
                cout << 1;
            }else{
                cout << 0;
            }
            cout << endl;
        }
    }
    return 0;
}