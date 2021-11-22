# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases, n;
    cin >> cases;
    rep(t, 0, cases){
        cin >> n;
        ll S=0, X=0, e;
        rep(i, 0 , n){
            cin >> e;
            S+=e;
            X^=e;
        }
        cout << "2\n" << X <<" " << S+X << "\n";
    }
    return 0;
}