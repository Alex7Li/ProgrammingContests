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
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for(int i = 0; i < n; i++){
        getline(cin, s);
        string s2 = s.substr(0, 10);
        if(s2 == "Simon says"){
            cout << s.substr(10) << endl;
        }
    }
    return 0;
}