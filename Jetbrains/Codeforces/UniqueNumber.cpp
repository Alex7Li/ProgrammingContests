# include <bits/stdc++.h>
//https://codeforces.com/contest/1462/problem/C
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
        int x;
        cin >> x;
        if(x>45){
            cout << "-1";
        }else {
            stack<int> s;
            int max = 9;
            while (max < x) {
                s.push(max);
                x-=max--;
            }
            if(x!=0){
                s.push(x);
            }
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
        }
        cout << endl;
    }
    return 0;
}