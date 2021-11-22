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
        int odd = 0;
        int even = 0;
        int temp;
        for (int i = 0; i < 2*n; ++i) {
            cin >> temp;
            if(temp %2 == 0){
                even++;
            }else{
                odd++;
            }
        }
        if(odd == even){
            cout << "Yes";
        }else{
            cout << "No";
        }
        cout <<endl;
    }
    return 0;
}