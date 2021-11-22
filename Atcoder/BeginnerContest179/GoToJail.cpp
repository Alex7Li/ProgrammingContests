# include <bits/stdc++.h>
//https://atcoder.jp/contests/abc179/tasks/abc179_b
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, 0, n){
        cin >> a[i];
        cin >> b[i];
    }
    for(int i = 0; i < n - 2; i++){
        if(a[i] == b[i] && a[i+1] == b[i+1] &&a[i+2] == b[i+2]){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}