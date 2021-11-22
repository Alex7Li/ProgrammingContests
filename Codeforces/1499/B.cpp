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
    for (int tt = 0; tt < t; tt++) {
        string s;
        cin >> s;
        int phase = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && s[i+1]=='1' && phase==0) {
                phase++;
            }
            if (s[i] == '0' && s[i+1]=='0' && phase==1) {
                phase++;
            }
        }
        if(phase==2){
            cout << "NO";
        }else{
            cout << "YES";
        };
        cout << "\n";
    }
    return 0;
}