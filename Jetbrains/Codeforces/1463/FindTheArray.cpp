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
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n;
        cin >> n;
        int v;
        rep(i, 0, n){
            cin >> v;
            int j = 1;
            for(; j <= v; j*=2){
            }
            cout << j/2 << " ";
        }
        cout << "\n";
    }
    return 0;
}