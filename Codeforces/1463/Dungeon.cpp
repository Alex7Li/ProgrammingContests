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
    int a,b,c;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        cin >> a >> b >> c;
        if((a+b+c)%9==0 && min(a,min(b,c)) >= (a+b+c)/9) {
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}