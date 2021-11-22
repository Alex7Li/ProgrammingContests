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
        vector<int> a(n);
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int s = 0;
        for(int i = 0; i < n; i++){
            s += a[i];
        }
        if(s==0){
            cout << "NO\n";
            continue;
        }else if(s > 0){
            cout << "YES\n";
            reverse(a.begin(), a.end());
        }else{
            cout << "YES\n";
        }
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}