# include <bits/stdc++.h>
//https://codeforces.com/contest/1270/problem/G
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)

vector<int> solve() {
    int n;
    cin >> n;
    vector<int> a = vector<int>(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n){
        if(a[i] == 0){
            return {i+1};
        }
        a[i] = i - a[i];
    }
    vector<int> ans;
    int cur=0, cur2=0, st=0;
    do{
        cur = a[cur];
        cur2 = a[a[cur2]];
    }while(cur != cur2);
    st = cur;
    do {
        ans.push_back(cur+1);
        cur = a[cur];
    } while (cur!=st);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(caseNum, 0, t) {
        vector<int> ans =  solve();
        cout << ans.size() << "\n" << ans[0];
        rep(i, 1, ans.size()){
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}