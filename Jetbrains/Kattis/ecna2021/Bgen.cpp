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
    int n = 10;
    int m = 4;
    cout << n << " " << m << "\n";
    rep(i, 0, n){
        rep(j, 0, m){
            cout << "A";
        }
        cout << "\n";
    }
    cout << 100 << "\n";
    rep(i, 0, 100) {
        cout << "A";
    }

    return 0;
}